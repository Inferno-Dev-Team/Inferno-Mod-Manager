#include <windows.h>

#pragma once
namespace InfernoModManager {
	ref class EncryptionManager
	{
	public:
		static System::String^ decrypt(System::String^ o);
		static System::String^ encrypt(System::String^ o);
		static System::IO::Stream^ GenerateStreamFromString(System::String^ s);
	};
}