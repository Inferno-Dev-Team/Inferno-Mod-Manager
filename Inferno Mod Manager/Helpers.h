#pragma once
#include <vector>

namespace InfernoModManager
{

	ref class Helpers
	{
		public:
			static System::Collections::Generic::List<System::String^>^ VectorToList(std::vector<const char *> vector);
			static std::vector<const char* > ListToVector(System::Collections::Generic::List<System::String^>^ list);
	};

}
