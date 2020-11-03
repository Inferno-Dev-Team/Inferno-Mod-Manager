#include "MainForm.h"

#include "Injection.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main()
{
	InfernoModManager::Injection::injectDLL("D:\\Inferno-Mod-Manager\\LoggingDLL\\x64\\Release\\LoggingDLL.dll", "BloonsTD6");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InfernoModManager::MainForm form;
	Application::Run(%form);
	return 0;
}