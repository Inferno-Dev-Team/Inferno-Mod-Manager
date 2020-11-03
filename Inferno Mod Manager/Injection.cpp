#include "Injection.h"

namespace InfernoModManager
{
#define CREATE_THREAD_ACCESS (PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ)

    bool Injection::injectDLL(System::String^ procName, char* dllName)
    {
        DWORD pId = Injection::GetTargetThreadIDFromProcName(procName);

        if (!pId)
            return false;

        HANDLE proc = 0;
        HMODULE hLib = 0;

        char buf[50] = { 0 };

        LPVOID RemoteString, LoadLibAddy;

        proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);

        if (!proc)
            return false;

        //GetProcAddress :: Retrieves the address of an exported function or variable from the specified dynamic-link library (DLL).
        LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");

        //Allocate memory space for the dll name in the process space
        RemoteString = (LPVOID)VirtualAllocEx(proc, NULL, strlen(dllName), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

        //write the name of the dll in this address space
        WriteProcessMemory(proc, RemoteString, dllName, strlen(dllName), NULL);


        //Load our dll using loadlibrary
        CreateRemoteThread(proc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddy, (LPVOID)RemoteString, NULL, NULL);


        CloseHandle(proc);

        return TRUE;

    }

    DWORD Injection::GetTargetThreadIDFromProcName(System::String^ procName)
    {
        System::Diagnostics::Process^ proc = System::Diagnostics::Process::GetProcessesByName(procName)[0];
        System::Console::WriteLine(proc->Id);

    	if (proc != nullptr)
    	{
            return proc->Id;
    	}

        return 0;

    }
}