#include <windows.h>

#pragma once
namespace InfernoModManager {
	ref class Injection
	{
	public:
		static void injectDLL(System::String^ location, System::String^ processName);
	};
}