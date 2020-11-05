#include "WebDownloader.h"


#include <iostream>
#include <msclr\marshal.h>
#include <string>

namespace InfernoModManager {
	std::vector<const char*> WebDownloader::getAllData()
	{
		std::vector<const char*> compList = std::vector<const char*>();
		System::Net::WebClient^ web = gcnew System::Net::WebClient();
		for each (const char* addr in WebDownloader::Repos)
		{
			System::String^ address = msclr::interop::marshal_as<System::String^>(addr);
			System::String^ data = web->DownloadString(address);
			data->Replace("\r", "");
			for each (System::String^ section in data->Split('\n'))
			{
				msclr::interop::marshal_context^ ctx = gcnew msclr::interop::marshal_context();
				const char * tmp = ctx->marshal_as<const char*>(section);
				compList.push_back(tmp);
			}
		}

		return compList;
	}

	void WebDownloader::downloadFile(const char* fileloc, const char* filename)
	{
		System::Net::WebClient^ web = gcnew System::Net::WebClient();
		web->DownloadFile(msclr::interop::marshal_as<System::String^>(fileloc), msclr::interop::marshal_as<System::String^>(filename));
	}

}
