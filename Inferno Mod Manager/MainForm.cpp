#include "MainForm.h"

#include "Injection.h"

using namespace System;
using namespace System::Windows::Forms;


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