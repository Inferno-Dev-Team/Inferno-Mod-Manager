#include "MainForm.h"
#include "SupportedGames.cpp"
#include "Injection.h"
#include "WebDownloader.h"
#include "InfernoModAttribute.h"
#include "Mod.h"
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
std::map<long long, const char*> InfernoModManager::Games::GameLocs = {};

std::vector<const char*> InfernoModManager::WebDownloader::Repos = {
	"https://github.com/KosmicShovel/BTD6-Mods/raw/master/tmp/git.yo"
};
std::vector<const char*> InfernoModManager::WebDownloader::AllData = {};

[InfernoModAttribute("tmp", "kosmic", "other", "null", "1.0")]
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