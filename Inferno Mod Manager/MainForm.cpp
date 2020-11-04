#include "MainForm.h"
#include "SupportedGames.cpp"
#include "Injection.h"
#include <map>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

std::map<long long, const char*> InfernoModManager::Games::GameInfo = {
	{960090, "BloonsTD6"}
};
// make sure we keep this sorted so that we can use the binary search on it O(n) vs O(lgn)
std::vector<const char*> InfernoModManager::Games::Types = {
	".btd6mod",
	".dll",
	".dll.disabled"
};

[STAThread]
int main()
{
	InfernoModManager::Injection::injectDLL("BloonsTD6", "D:\\Inferno-Mod-Manager\\LoggingDLL\\x64\\Release\\LoggingDLL.dll");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InfernoModManager::MainForm form;
	Application::Run(%form);
	return 0;
}