#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	InfernoModManager::MainForm form;
	Application::Run(%form);
	return 0;
}