// dllmain.cpp : Defines the entry point for the DLL application.
#include "dllmain.h"

// Desired hooks should be added here
static void addHooks() {
}

void onDLLProcessAttach() {
#ifdef RELEASE
	Logger::setLevel(Logger::LOG_NONE);
#else
	Logger::setLevel(Logger::LOG_DEBUG);
#endif

	g_config.parseFile();
	Logger::debug("DLL Process Attach");

	addHooks();

	Hooks::init(true);
}

void onDLLProcessDetach() {
	Logger::debug("DLL Process Detach");
	Hooks::cleanup();
	Logger::cleanup();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)onDLLProcessAttach, NULL, 0, NULL);
		break;
    case DLL_PROCESS_DETACH:
		onDLLProcessDetach();
        break;
    }
    return TRUE;
}

