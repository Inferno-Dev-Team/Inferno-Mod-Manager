#include <windows.h>

#pragma once
namespace InfernoModManager {
	ref class Injection
	{
	public:
		static bool injectDLL(System::String^ procName, char* dllName);
		static DWORD GetTargetThreadIDFromProcName(System::String^ procName);
	};
}