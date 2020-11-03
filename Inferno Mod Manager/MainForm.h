#pragma once

namespace InfernoModManager {

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//double buffered renders all at once, therefore faster
			this->ModsList->GetType()->GetProperty("DoubleBuffered",
				System::Reflection::BindingFlags::Instance | System::Reflection::BindingFlags::NonPublic)
				->SetValue(this->ModsList, true);
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

		private: System::Windows::Forms::FolderBrowserDialog^ BTD6FolderDialog;
		private: System::Windows::Forms::Button^ BTD6FolderBrowseButton;
		private: System::Windows::Forms::TextBox^ BTD6FolderInput;
		private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
		private: System::Windows::Forms::DataGridView^ ModsList;
		private: System::Windows::Forms::DataGridViewCheckBoxColumn^ check;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;

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
			this->BTD6FolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->BTD6FolderBrowseButton = (gcnew System::Windows::Forms::Button());
			this->BTD6FolderInput = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ModsList = (gcnew System::Windows::Forms::DataGridView());
			this->check = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->BeginInit();
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
			// BTD6FolderInput
			// 
			this->BTD6FolderInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->BTD6FolderInput->Location = System::Drawing::Point(155, 5);
			this->BTD6FolderInput->Name = L"BTD6FolderInput";
			this->BTD6FolderInput->Size = System::Drawing::Size(782, 22);
			this->BTD6FolderInput->TabIndex = 0;
			this->BTD6FolderInput->TextChanged += gcnew System::EventHandler(this, &MainForm::BTD6FolderInput_TextChanged);
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
			// ModsList
			// 
			this->ModsList->AllowUserToAddRows = false;
			this->ModsList->AllowUserToDeleteRows = false;
			this->ModsList->AllowUserToResizeColumns = false;
			this->ModsList->AllowUserToResizeRows = false;
			this->ModsList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ModsList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->check, this->name,
					this->type
			});
			this->tableLayoutPanel2->SetColumnSpan(this->ModsList, 3);
			this->ModsList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModsList->Location = System::Drawing::Point(3, 36);
			this->ModsList->Name = L"ModsList";
			this->ModsList->RowHeadersVisible = false;
			this->ModsList->RowHeadersWidth = 51;
			this->ModsList->RowTemplate->Height = 24;
			this->ModsList->Size = System::Drawing::Size(970, 687);
			this->ModsList->TabIndex = 3;
			// 
			// check
			// 
			this->check->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->check->HeaderText = L"Enabled";
			this->check->MinimumWidth = 6;
			this->check->Name = L"check";
			this->check->Width = 66;
			// 
			// name
			// 
			this->name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->name->HeaderText = L"Name";
			this->name->MinimumWidth = 6;
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			// 
			// type
			// 
			this->type->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->type->HeaderText = L"Type";
			this->type->MinimumWidth = 6;
			this->type->Name = L"type";
			this->type->ReadOnly = true;
			this->type->Width = 69;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::String^ btd6Install = nullptr;

		private: System::Void BTD6FileBrowseButton_Click(System::Object^ sender, System::EventArgs^ e) {
			BTD6FolderDialog->SelectedPath = System::Windows::Forms::Application::StartupPath;
			if (BTD6FolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::String^ folderPath = BTD6FolderDialog->SelectedPath;
				BTD6FolderInput->Text = folderPath;
			}
		}
		private: System::Void BTD6FolderInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			btd6Install = BTD6FolderDialog->SelectedPath;
			array<System::String^>^ files = System::IO::Directory::GetFiles(btd6Install + "\\Mods");
			PopulateModsList(files);
		}

		private: System::Void PopulateModsList(array<System::String^>^ files) {
			ModsList->Rows->Clear();
			for each (System::String^ file in files) {
				if (file->EndsWith(".dll.disabled") || file->EndsWith(".dll") || file->EndsWith(".btd6mod")) {
					System::Windows::Forms::DataGridViewRow^ newRow = gcnew System::Windows::Forms::DataGridViewRow();
					ModsList->Rows->Add(IsEnabled(file), NameOf(file), TypeOf(file));
				}
			}
		}

		private: System::Void ModsList_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
			if (btd6Install != nullptr) {
				//bool toggle = 
			}
		}

		private: bool IsEnabled(System::String^ file) {
			return !file->EndsWith(".disabled");
		}

		private: System::String^ NameOf(System::String^ file) {
			System::String^ name = System::IO::Path::GetFileName(file);
			int end = name->IndexOf('.');
			if(end > 0)
				name = name->Substring(0, end);
			return name;
		}

		private: System::String^ TypeOf(System::String^ file) {
			if (file->EndsWith(".dll.disabled"))
				return ".dll";
			else
				return System::IO::Path::GetExtension(file);
		}
	};
}
