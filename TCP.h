#pragma once

#include "buildconfig.h"

#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>

#include <memory>
#include <boost/function.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <nlohmann/json.hpp>

#include "Logger.h"

using json = nlohmann::json;
using boost::asio::ip::tcp;

namespace TCP {

	// Connection represents an ongoing TCP connection with a client
	template <typename SizeType>
	class Connection : public std::enable_shared_from_this<Connection<SizeType> > {
	public:
		typedef std::function<void(boost::system::error_code&)> StopHandler;
		typedef std::function<void()> StartHandler;
	protected:
		typedef std::function<void(const json&)> RecvHandlerType;
		boost::system::error_code error_state;
		bool stopped;
		std::vector<SizeType> read_msgsize_buff;
		std::mutex write_mutex;
		tcp::socket socket;
		std::function<void(boost::system::error_code&)> onStopHandler;
		std::map<short, RecvHandlerType> handlers;
	
	protected:

		void handle_read(boost::system::error_code readErr) {
			if (stopped) return;
			if (readErr) {
				error_state = readErr;
				stop();
				return;
			}

			// Already read the message size
			SizeType msgSize = read_msgsize_buff[0];

			// Synchronously read and extract the message kind
			short msgKind;
			size_t syncBytesRead = boost::asio::read(socket, boost::asio::buffer(&msgKind, 2), readErr);
			if (!readErr && syncBytesRead != 2) {
				error_state = boost::system::error_code(boost::system::errc::message_size, boost::system::generic_category());
				stop();
				return;
			}
			if (readErr) {
				error_state = readErr;
				stop();
				return;
			}

			// Read the actual message
			std::vector<char> rawMsg(msgSize - 2);
			syncBytesRead = boost::asio::read(socket, boost::asio::buffer(rawMsg, msgSize - 2), readErr);
			if (syncBytesRead != msgSize - 2) {
				error_state = boost::system::error_code(boost::system::errc::message_size, boost::system::generic_category());
				stop();
				return;
			}
			if (!readErr && readErr) {
				error_state = readErr;
				stop();
				return;
			}
			std::string msgString = std::string(rawMsg.begin(), rawMsg.end());
			// Parse the message into json
			json msgJson;
			try {
				msgJson = json::parse(msgString);
			}
			catch (const json::parse_error&) {
				error_state = boost::system::error_code(boost::system::errc::bad_message, boost::system::generic_category());
				stop();
				return;
			}

			// Call the handler for this kind of message
			// If there is no handler, ignore the message
			auto& it = handlers.find(msgKind);
			if (it != handlers.end()) {
				it->second(msgJson);
			}

			// Begin the next asynchronous read
			boost::asio::async_read(socket,
				boost::asio::buffer(read_msgsize_buff, sizeof(SizeType)),
				boost::asio::transfer_exactly(sizeof(SizeType)),
				boost::bind(&Connection::handle_read, this, _1));
		}

		void write(short msgKind, const json& msgBody) {
			if (stopped) return;

			// Serialise message
			std::string msgString = msgBody.dump();
			SizeType msgSize = (SizeType)msgString.length() + sizeof(msgKind);

			// Construct the bytes to send
			std::ostringstream out_stream;
			out_stream.write(reinterpret_cast<char*>(&msgSize), sizeof(msgSize));
			out_stream.write(reinterpret_cast<char*>(&msgKind), sizeof(msgKind));
			out_stream << msgString;

			// Message writing is synchronous and serialised to avoid a data race
			boost::system::error_code writeErr;

			size_t bytesWritten;
			{
				std::lock_guard<std::mutex> lock(write_mutex);
				bytesWritten = boost::asio::write(socket, boost::asio::buffer(out_stream.str(), out_stream.str().length()), writeErr);
			}
			if (!writeErr && bytesWritten != msgSize + sizeof(SizeType)) {
				writeErr.assign(boost::system::errc::message_size, boost::system::generic_category());
			}
			if (writeErr) {
				error_state = writeErr;
				stop();
			}
		}

	public:
		Connection(boost::asio::io_service& ios) :
			socket(ios),
			read_msgsize_buff(1),
			write_mutex(),
			error_state(),
			handlers(),
			stopped(false) {
			static_assert(std::is_integral<SizeType>::value, "SizeType type parameter must be an integral type");
		}

		void add_handler(short msgKind, RecvHandlerType handler) {
			handlers[msgKind] = handler;
		}

		tcp::socket& get_socket() {
			return socket;
		}

		void send(short msgKind, const json& msgBody) {
			write(msgKind, msgBody);
		}

		virtual void start(StartHandler connect_handler = NULL, StopHandler stop_handler = NULL) {
			stopped = false;
			onStopHandler = stop_handler;
			boost::asio::async_read(socket,
				boost::asio::buffer(read_msgsize_buff, sizeof(SizeType)),
				boost::asio::transfer_exactly(sizeof(SizeType)),
				boost::bind(&Connection::handle_read, this, _1));

			if (connect_handler) {
				connect_handler();
			}
		}

		void set_stop_handler(StopHandler stop_handler) {
			onStopHandler = stop_handler;
		}

		void stop() {
			Logger::debug("stopping connection... error code is %d: %s", error_state.value(), error_state.message());
			stopped = true;
			socket.close();

			if (onStopHandler) {
				onStopHandler(error_state);
			}
		}

		boost::system::error_code get_error_state() {
			return error_state;
		}

		bool is_stopped() {
			return stopped;
		}

	};

	// Client represents an asynchronous TCP Client
	template <typename SizeType>
	class Client : public Connection<SizeType> {
		typedef std::function<void(const json&)> RecvHandlerType;
	private:
		std::function<void()> onConnectHandler;
	private:

		void handle_connect(const boost::system::error_code& conErr) {
			if (stopped) return;

			if (!socket.is_open()) {
				// async_connect automatically opens the socket
				// If the socket is still closed, then timeout occurred
				// Also check if in an error state
				error_state = boost::system::error_code(boost::system::errc::connection_aborted, boost::system::generic_category());
				stop();
				return;
			}
			else if (conErr) {
				// Connection error
				error_state = conErr;
				stop();
				return;
			}

			// Successful connection
			this->Connection<SizeType>::start(onConnectHandler, onStopHandler);
		}

	public:
		Client(boost::asio::io_service& ios) : 
			Connection(ios) {
			static_assert(std::is_integral<SizeType>::value, "SizeType type parameter must be an integral type");
		}

		virtual void start(std::string host, int port, std::function<void()> connect_handler = NULL, std::function<void(boost::system::error_code&)> stop_handler = NULL) {
			stopped = false;
			onConnectHandler = connect_handler;
			onStopHandler = stop_handler;
			boost::asio::ip::address addr = boost::asio::ip::address::from_string(host, error_state);
			if (error_state) {
				return;
			}
			tcp::endpoint endpoint(addr, port);

			socket.async_connect(endpoint, boost::bind(&Client::handle_connect, this, _1));
		}
	};

	template <typename SizeType>
	class Server {
	public:
		typedef std::function<void(std::shared_ptr<Connection<SizeType> >&)> AcceptHandler;
	private:
		boost::asio::io_service& ios;
		tcp::acceptor acceptor;
		AcceptHandler onAcceptHandler;
	private:

		void handle_accept(std::shared_ptr<Connection<SizeType> > conn, const boost::system::error_code& err) {
			Logger::fatal("handle_accept called");
			if (!err) {
				conn->start();
				Logger::debug("Incoming connection occurred!");
				if (onAcceptHandler) {
					onAcceptHandler(conn);
				}
			} else {
				Logger::warn("Incoming connection failed with error %d: %s", err.value(), err.message());
			}
			std::shared_ptr<Connection<SizeType> > newConn = std::make_shared<Connection<SizeType> >(ios);
			acceptor.async_accept(newConn->get_socket(),
				boost::bind(&Server::handle_accept, this, newConn, boost::asio::placeholders::error));
		}

	public:
		Server(boost::asio::io_service& ios, short port, AcceptHandler accept_handler = NULL) :
			ios(ios),
			acceptor(ios, tcp::endpoint(tcp::v4(), port)),
			onAcceptHandler(accept_handler)
		{
			
		}

		void start() {
			std::shared_ptr<Connection<SizeType> > conn = std::make_shared<Connection<SizeType> >(ios);
			acceptor.async_accept(conn->get_socket(),
				boost::bind(&Server::handle_accept, this, conn, boost::asio::placeholders::error));
			Logger::debug("TCP server running!");
		}
	};
}