#include "MainForm.h"
#include "SupportedGames.cpp"
#include "Injection.h"
#include <map>

using namespace System;
using namespace System::Windows::Forms;

std::map<long long, const char*> InfernoModManager::Games::GameInfo;

void init()
{
	auto inf = std::map<long long, const char*>();
	inf.insert( std::pair<long long, const char*>(960090, "BloonsTD6"));

	InfernoModManager::Games::GameInfo = inf;
}

[STAThread]
int main()
{
	init();
	InfernoModManager::Injection::injectDLL("BloonsTD6", "D:\\Inferno-Mod-Manager\\LoggingDLL\\x64\\Release\\LoggingDLL.dll");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InfernoModManager::MainForm form;
	Application::Run(%form);
	return 0;
}