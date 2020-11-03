#include "EncryptionManager.h"

namespace InfernoModManager
{
	System::String^ EncryptionManager::decrypt(System::String^ encrypted)
	{
		System::String^ ret = System::String::Empty;

		System::IO::BinaryReader^ reader = gcnew System::IO::BinaryReader(GenerateStreamFromString(encrypted));
		System::String^ bits = System::String::Empty;
		bits += "Inferno 128 5 ";
		//this error below is retarded so just ignore it
		System::Security::Cryptography::SHA512^ sha512 = System::Security::Cryptography::SHA512::Create(bits);
		System::Security::Cryptography::CryptoStream^ cs = gcnew System::Security::Cryptography::CryptoStream(
			reader->BaseStream, sha512, System::Security::Cryptography::CryptoStreamMode::Read);
		return ret;
	}

	System::String^ EncryptionManager::encrypt(System::String^ toEncrypt)
	{
		System::String^ ret = System::String::Empty;
		return ret;
	}

	System::IO::Stream^ EncryptionManager::GenerateStreamFromString(System::String^ s)
	{
		System::IO::MemoryStream^ stream = gcnew System::IO::MemoryStream();
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(stream);
		writer->Write(s);
		writer->Flush();
		stream->Position = 0;
		return stream;
	}
}
