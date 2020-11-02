
#include "MainForm.h"
using namespace std;

int main()
{
	InfernoModManager::MainForm^ mainform = gcnew InfernoModManager::MainForm();
	mainform->Activate();
	while (true);
	mainform->Close();
}