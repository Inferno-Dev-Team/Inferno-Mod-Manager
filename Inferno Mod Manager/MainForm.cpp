#include "MainForm.h"
#include "SupportedGames.cpp"
#include "Injection.h"
#include "WebDownloader.h"
#include "InfernoModAttribute.h"
#include "Mod.h"
#include "Helpers.h"
#include <map>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

std::map<long long, const char*> InfernoModManager::Games::GameInfo = {
	{960090, "BloonsTD6"}
};
std::vector<const char*> InfernoModManager::Games::Types = {
	".dll",
};
std::map<long long, const char*> InfernoModManager::Games::GameLocs = {};

std::vector<const char*> InfernoModManager::WebDownloader::Repos = {
	"https://pastebin.com/raw/mmsZH6UC", "https://raw.githubusercontent.com/KosmicShovel/BTD6-Mods/master/tmp/git.yo"
};
std::vector<const char*> InfernoModManager::WebDownloader::AllData = {};

[InfernoModAttribute("tmp", "kosmic", "other", "null", "1.0")]
[STAThread]
int main()
{
	freopen("log.log", "w", stdout);
	//Why no work
	/*if (!IO::File::Exists("repos.json"))
	{
		IO::File::Create("repos.json")->Close();
		IO::File::WriteAllText("repos.json", Newtonsoft::Json::JsonConvert::SerializeObject(InfernoModManager::Helpers::VectorToList(InfernoModManager::WebDownloader::Repos)));
	} else
	{
		Collections::Generic::List<String^>^ list = Newtonsoft::Json::JsonConvert::DeserializeObject<Collections::Generic::List<String^>^>(IO::File::ReadAllText("repos.json")->Replace("\n", ""));
		InfernoModManager::WebDownloader::Repos = InfernoModManager::Helpers::ListToVector(list);
		for each (const char * t in InfernoModManager::WebDownloader::Repos)
		{
			std::cout << t << std::endl;
		}
	}*/
	InfernoModManager::WebDownloader::getAllData();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InfernoModManager::MainForm form;
	Application::Run(%form);
	return 0;
}