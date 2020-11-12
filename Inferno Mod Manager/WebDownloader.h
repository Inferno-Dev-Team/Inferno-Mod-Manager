#include <vector>

#pragma once
namespace InfernoModManager {
	class WebDownloader
	{
		public:
			static std::vector<const char*> Repos;
			static std::vector<const char*> AllData;
		    static std::vector<const char*> getAllData(bool forcePull = false, bool log = false);
			static void downloadFile(System::String^ fileloc, System::String^ filename);
	};
}
