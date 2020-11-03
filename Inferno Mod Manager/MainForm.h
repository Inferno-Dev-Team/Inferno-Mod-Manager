#pragma once

namespace InfernoModManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^ BTD6FolderInput;

	private: System::Windows::Forms::Button^ BTD6FolderBrowseButton;
	private: System::Windows::Forms::FolderBrowserDialog^ BTD6FolderDialog;
	private: System::Windows::Forms::CheckedListBox^ ModsList;











	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Label^ label1;
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->BTD6FolderInput = (gcnew System::Windows::Forms::TextBox());
			this->BTD6FolderBrowseButton = (gcnew System::Windows::Forms::Button());
			this->ModsList = (gcnew System::Windows::Forms::CheckedListBox());
			this->BTD6FolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			label1->AutoSize = true;
			label1->Location = System::Drawing::Point(3, 0);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(146, 33);
			label1->TabIndex = 1;
			label1->Text = L"BTD6 Install Location:";
			label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->Controls->Add(this->BTD6FolderInput, 1, 0);
			this->tableLayoutPanel2->Controls->Add(label1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->BTD6FolderBrowseButton, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->ModsList, 0, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(976, 726);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// BTD6FolderInput
			// 
			this->BTD6FolderInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->BTD6FolderInput->Location = System::Drawing::Point(155, 5);
			this->BTD6FolderInput->Name = L"BTD6FolderInput";
			this->BTD6FolderInput->Size = System::Drawing::Size(782, 22);
			this->BTD6FolderInput->TabIndex = 0;
			this->BTD6FolderInput->TextChanged += gcnew System::EventHandler(this, &MainForm::BTD6FolderInput_TextChanged);
			// 
			// BTD6FolderBrowseButton
			// 
			this->BTD6FolderBrowseButton->AutoSize = true;
			this->BTD6FolderBrowseButton->Location = System::Drawing::Point(943, 3);
			this->BTD6FolderBrowseButton->Name = L"BTD6FolderBrowseButton";
			this->BTD6FolderBrowseButton->Size = System::Drawing::Size(30, 27);
			this->BTD6FolderBrowseButton->TabIndex = 2;
			this->BTD6FolderBrowseButton->Text = L"...";
			this->BTD6FolderBrowseButton->UseVisualStyleBackColor = true;
			this->BTD6FolderBrowseButton->Click += gcnew System::EventHandler(this, &MainForm::BTD6FileBrowseButton_Click);
			// 
			// ModsList
			// 
			this->tableLayoutPanel2->SetColumnSpan(this->ModsList, 3);
			this->ModsList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModsList->FormattingEnabled = true;
			this->ModsList->Location = System::Drawing::Point(3, 36);
			this->ModsList->Name = L"ModsList";
			this->ModsList->Size = System::Drawing::Size(970, 687);
			this->ModsList->TabIndex = 3;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 750);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Name = L"MainForm";
			this->Text = L"Inferno Mod Manager";
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BTD6FileBrowseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		BTD6FolderDialog->SelectedPath = System::Windows::Forms::Application::StartupPath;
		if (BTD6FolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::String^ folderPath = BTD6FolderDialog->SelectedPath;
			BTD6FolderInput->Text = folderPath;
		}
	}
	private: System::Void BTD6FolderInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		// Get mods in selected folder
		System::Collections::Generic::List<String^>^ files = gcnew System::Collections::Generic::List<String^>(
			System::IO::Directory::EnumerateFiles(BTD6FolderDialog->SelectedPath + "\\Mods", "*.btd6mod"));
		files->AddRange(System::IO::Directory::EnumerateFiles(BTD6FolderDialog->SelectedPath + "\\Mods", "*.dll"));
		if (files->Count > 0) {
			ModsList->Visible = true;
			PopulateModsList(files->ToArray());
		} else ModsList->Visible = false;
	}

	private: System::Void PopulateModsList(array<System::String^>^ files) {
		ModsList->Items->Clear();
		ModsList->Items->AddRange(files);
	}
};
}
