// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cstdio>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD nReason, VOID* pvReserved)
{
    pvReserved;
    const char pszMessage[1024] = { 0 };
    printf(pszMessage, "GetCurrentProcessId() %d, hModule 0x%p, nReason %d\r\n", GetCurrentProcessId(), hModule, nReason);
    /*switch(nReason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }*/
    return TRUE;
}

