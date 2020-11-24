#include <vector>

#pragma once
namespace InfernoModManager {
	ref class WebDownloader
	{
		public:
			static System::Collections::Generic::List<System::String^>^ Repos;
			static System::Collections::Generic::List<System::String^>^ AllData;
			static System::Collections::Generic::List<System::String^>^ getAllData();
			static void ifBlankSet();
			static void downloadFile(System::String^ fileloc, System::String^ filename);
	};
}
