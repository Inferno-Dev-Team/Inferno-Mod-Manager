#include "WebDownloader.h"

#include <iostream>
#include <msclr\marshal.h>
#include <string>

namespace InfernoModManager {
	std::vector<const char*> WebDownloader::getAllData(bool forcePull, bool log)
	{
		if (AllData.size() == 0 || forcePull) {
			std::vector<const char*> compList = std::vector<const char*>();
			msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
			System::Net::WebClient^ web = gcnew System::Net::WebClient();
			web->Headers->Add("user-agent", "Inferno Mod Manager");
			for each (const char* addr in WebDownloader::Repos)
			{
				System::String^ address = ctx->marshal_as<System::String^>(addr);
				if (address) {
					if (address->Replace("н", ""))
					try {
						System::String^ data = web->DownloadString(address);
						data->Replace("\r", "");
						for each (System::String ^ section in data->Split('\n'))
						{
							msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
							const char* tmp = ctx->marshal_as<const char*>(section);
							compList.push_back(tmp);
							if (log) std::cout << tmp << "\n";
						}
					} catch (System::Exception^) {}
				}
			}
			AllData = compList;
		}

		return AllData;
	}

	void WebDownloader::downloadFile(System::String^ fileloc, System::String^ filename)
	{
		System::Net::WebClient^ web = gcnew System::Net::WebClient();
		web->Headers->Add("user-agent", "Inferno Mod Manager");
		web->DownloadFile(fileloc, filename);
	}

}
