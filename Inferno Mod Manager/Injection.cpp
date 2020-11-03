#include "Injection.h"

namespace InfernoModManager
{
    void Injection::injectDLL(System::String^ location, System::String^ processName)
	{
		System::Diagnostics::Process^ processToInject = System::Diagnostics::Process::GetProcessesByName(processName)[0];
        HANDLE h = OpenProcess(PROCESS_ALL_ACCESS, false, processToInject->Id);
        if (h)
        {
            LPVOID LoadLibAddr = (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
            LPVOID dereercomp = VirtualAllocEx(h, NULL, location->Length, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            WriteProcessMemory(h, dereercomp, &location, location->Length, NULL);
            HANDLE asdc = CreateRemoteThread(h, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddr, dereercomp, 0, NULL);
            WaitForSingleObject(asdc, INFINITE);
            VirtualFreeEx(h, dereercomp, location->Length, MEM_RELEASE);
            CloseHandle(asdc);
            CloseHandle(h);
            return;
        }
        System::Console::WriteLine("Error in inject DLL");
	}
}