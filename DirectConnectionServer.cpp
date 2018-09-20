#include "DirectConnectionServer.h"

DCServer::Server g_DCServer;

namespace DCServer {

	void Server::start(short port) {
		TCP::Server<uint32_t>::AcceptHandler acceptHandler = [this](ConnectionPtr& conn) {
			handler_acceptConnection(conn);
		};

		server = std::make_shared<TCP::Server<uint32_t> >(ios, port, 
			acceptHandler);
		iosThread = std::make_shared<std::thread>([&] {
			boost::asio::io_service::work work(ios);
			server->start();

			ios.run();
		});
		
	}

	void Server::applyHandlersToConnection(std::shared_ptr<PlayerConnection> pconn) {
		pconn->conn->set_stop_handler([this, pconn](boost::system::error_code& err) {
			// Run the server-level stop connection handler
			// `this` will be the server, pconn is the player connection object (captured here)
			// the point being, this runs inside the Connection but has access to the Server and PlayerConnection
			handler_stopConnection(pconn, err);
		});

		pconn->conn->add_handler(DVSRV_MSG_KIND_PLAYER_CONNECTION, [this, pconn](const json& j) {
			Logger::debug("HANDLER FOR PLAYER CONNECTION MESSAGE CALLED");
			Logger::debug("JSON OF MESSAGE: %s", j.dump().c_str());
			//Logger::debug("Handler: %d", &handler_PlayerConnectionMessage);
			handler_PlayerConnectionMessage(pconn, j);
			Logger::debug("POST HANDLER");
		});
	}

	void Server::handler_acceptConnection(ConnectionPtr& conn) {
		// Counter used for temporary IDs
		static int uniquePendingId = 0;

		std::shared_ptr<PlayerConnection> pconn = std::make_shared<PlayerConnection>(conn);
		pconn->validated = false;
		applyHandlersToConnection(pconn);

		// Use a temporary ID until we know the ID of this player
		// Mutex to prevent race condition in ID assignment
		std::lock_guard<std::mutex> lock(pendingConnectionsMutex);
		pconn->playerId = uniquePendingId++;
		pendingConnections.push_back(conn);
	}

	void Server::handler_stopConnection(std::shared_ptr<PlayerConnection> pconn, boost::system::error_code& err) {
		Logger::debug("[Connection Stopped with code %d]", pconn->conn->get_error_state().value());

		// Delete from pending connections if there
		{
			std::lock_guard<std::mutex> lock(pendingConnectionsMutex);
			for (unsigned int i = 0; i < pendingConnections.size(); ++i) {
				if (pendingConnections[i].playerId == pconn->playerId) {
					// Remove this from pending connections
					pendingConnections.erase(pendingConnections.begin() + i);
					break;
				}
			}
		}

		// Delete from map if there
		{
			std::lock_guard<std::mutex> lock(knownPlayerConnectionsMutex);
			auto& it = knownPlayerConnections.find(pconn->playerId);
			if (it != knownPlayerConnections.end()) {
				knownPlayerConnections.erase(pconn->playerId);
			}
		}
	}

	//void Server::handler_PlayerConnectionMessage(std::shared_ptr<PlayerConnection> pconn, const json& j) {
	//	Logger::debug("Got PlayerConnectionMessage");
	//}

	void Server::handler_PlayerConnectionMessage(std::shared_ptr<PlayerConnection> pconn, const json& j) {
		PlayerConnectionMessage msg;
		if (!msg.fromJson(j)) {
			// Failed to parse
			Logger::warn("Failed to parse connection message from player: %s", j.dump().c_str());
			return;
		}

		// TODO: Validate protocol version

		// Check if player was already validated
		if (pconn->validated) {
			Logger::warn("Duplicate connection message for connection %ld: %s", pconn->playerId, j.dump().c_str());
			return;
		}

		// Not validated, so the playerId currently refers to a temporary ID
		// Find and remove it in the pending connections
		{
			std::lock_guard<std::mutex> lock(pendingConnectionsMutex);
			for (unsigned int i = 0; i < pendingConnections.size(); ++i) {
				if (pendingConnections[i].playerId == pconn->playerId) {
					// Remove this from pending connections
					pendingConnections.erase(pendingConnections.begin() + i);
					break;
				}
			}
		}

		// Add the player to the map of known players
		pconn->playerId = TAServer::netIdToLong(msg.uniquePlayerId);
		{
			std::lock_guard<std::mutex> lock(knownPlayerConnectionsMutex);
			knownPlayerConnections[pconn->playerId] = pconn;
		}
		pconn->validated = true;
	}

}