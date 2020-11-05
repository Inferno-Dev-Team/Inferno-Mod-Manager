#include "MainForm.h"
#include "SupportedGames.cpp"
#include "Injection.h"
#include "WebDownloader.h"
#include <map>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

std::map<long long, const char*> InfernoModManager::Games::GameInfo = {
	{960090, "BloonsTD6"}
};
std::vector<const char*> InfernoModManager::Games::Types = {
	".btd6mod",
	".dll",
	".dll.disabled"
};
std::vector<const char*> InfernoModManager::WebDownloader::Repos = {
	"https://github.com/KosmicShovel/BTD6-Mods/raw/master/tmp/git.yo"
};
std::map<long long, const char*> InfernoModManager::Games::GameLocs = {};

[STAThread]
int main()
{
	InfernoModManager::WebDownloader::getAllData();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InfernoModManager::MainForm form;
	Application::Run(%form);
	return 0;
}