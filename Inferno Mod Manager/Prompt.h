namespace InfernoModManager
{
	ref class Prompt
	{
		public:
			static System::Windows::Forms::Form^ prompt;

			static System::String^ Prompt::ShowDialog(System::String^ text, System::String^ caption)
			{
				prompt = gcnew System::Windows::Forms::Form();
				prompt->Width = 500;
				prompt->Height = 150;
				prompt->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				prompt->Text = caption;
				prompt->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				System::Windows::Forms::Label^ textLabel = gcnew System::Windows::Forms::Label();
				textLabel->Left = 50;
				textLabel->Top = 20;
				textLabel->Text = text;
				System::Windows::Forms::TextBox^ textBox = gcnew System::Windows::Forms::TextBox();
				textBox->Left = 50;
				textBox->Top = 20;
				textBox->Width = 400;
				System::Windows::Forms::Button^ confirmation = gcnew System::Windows::Forms::Button();
				confirmation->Text = "Ok";
				confirmation->Left = 350;
				confirmation->Width = 100;
				confirmation->Top = 70;
				confirmation->DialogResult = System::Windows::Forms::DialogResult::OK;
				confirmation->Click += gcnew System::EventHandler(&InfernoModManager::Prompt::OnClick);
				prompt->Controls->Add(textBox);
				prompt->Controls->Add(confirmation);
				prompt->Controls->Add(textLabel);
				prompt->AcceptButton = confirmation;

				return prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK ? textBox->Text : "";
			}
			static void OnClick(System::Object^ sender, System::EventArgs^ e);
	};
}


void InfernoModManager::Prompt::OnClick(System::Object^ sender, System::EventArgs^ e)
{
	InfernoModManager::Prompt::prompt->Close();
}
