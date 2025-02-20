// dllmain.cpp : Defines the entry point for the DLL application.
#include <iostream>
#include "startup.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		FILE* f1;
		FILE* f2;
		FILE* f3;
		freopen_s(&f1, "CONOUT$", "wb", stdout);
		freopen_s(&f2, "CONOUT$", "wb", stderr);
		freopen_s(&f3, "CONIN$", "rb", stdin);	
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Startup::Start, 0, 0, 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

