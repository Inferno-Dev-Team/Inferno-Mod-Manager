#include "MainForm.h"
#include "SupportedGames.cpp"
#include "Injection.h"
#include "WebDownloader.h"
#include "InfernoModAttribute.h"
#include "Mod.h"
#include "Helpers.h"
#include "WebDownloader.h"
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;

std::map<long long, const char*> InfernoModManager::Games::GameInfo = {
	{960090, "BloonsTD6"}
};
std::vector<const char*> InfernoModManager::Games::Types = {
	".dll",
};
std::map<long long, const char*> InfernoModManager::Games::GameLocs = {};

[InfernoModAttribute("tmp", "kosmic", "other", "null", "1.0")]
[STAThread]
int main()
{
	freopen_s((FILE**)stdout, "log.log", "w", stdout);

	//Why no work
	InfernoModManager::WebDownloader::ifBlankSet();
	InfernoModManager::WebDownloader::getAllData();
	if (!IO::File::Exists("repos.json"))
	{
		IO::File::Create("repos.json")->Close();
		IO::File::WriteAllText("repos.json", Newtonsoft::Json::JsonConvert::SerializeObject(InfernoModManager::WebDownloader::Repos));
	} else
	{
		Collections::Generic::List<String^>^ list = Newtonsoft::Json::JsonConvert::DeserializeObject<Collections::Generic::List<String^>^>(IO::File::ReadAllText("repos.json"));
		InfernoModManager::WebDownloader::Repos = list;
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InfernoModManager::MainForm form;
	Application::Run(%form);
	return 0;
}