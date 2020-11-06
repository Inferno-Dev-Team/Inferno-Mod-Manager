#include "Injection.h"
#include <msclr/marshal.h>

namespace InfernoModManager
{
#define CREATE_THREAD_ACCESS (PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ)

    bool Injection::injectDLL(System::String^ procName, char* dllName)
    {
        if (dllName) {
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

            //Allocate memory space for the dll name in the process space
            RemoteString = (LPVOID)VirtualAllocEx(proc, NULL, strlen(dllName), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
            HMODULE dllModule = LoadLibraryA(dllName);
            //write the name of the dll in this address space
            if (RemoteString) {
                CreateRemoteThread(proc, NULL, NULL, (LPTHREAD_START_ROUTINE)dllModule, (LPVOID)RemoteString, NULL, NULL);

                CloseHandle(proc);

                return true;
            }
        }
        return false;
    }

    DWORD Injection::GetTargetThreadIDFromProcName(System::String^ procName)
    {
        array<System::Diagnostics::Process^>^ procs = System::Diagnostics::Process::GetProcessesByName(procName);
        if (procs->Length > 0) {
            System::Diagnostics::Process^ proc = procs[0];
            System::Console::WriteLine(proc->Id);

            if (proc != nullptr)
            {
                return proc->Id;
            }
        }

        return -1;

    }
}
