#include "Helpers.h"

#include <msclr/marshal.h>

namespace InfernoModManager
{
	System::Collections::Generic::List<System::String^>^ InfernoModManager::Helpers::VectorToList(std::vector<const char*> vector)
	{
		System::Collections::Generic::List<System::String^>^ list = gcnew System::Collections::Generic::List<System::String^>();
		msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
		for each (const char* t in vector)
		{
			System::String^ tmp = ctx->marshal_as<System::String^>(t);
			list->Add(tmp);
		}

		return list;
	}

	std::vector<const char* > InfernoModManager::Helpers::ListToVector(System::Collections::Generic::List<System::String^>^ list)
	{
		std::vector<const char*> vector = std::vector<const char*>();

		msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
		for each (System::String ^ t in list)
		{
			const char* tmp = ctx->marshal_as<const char*>(t);
			vector.push_back(tmp);
		}

		return vector;
	}
}
