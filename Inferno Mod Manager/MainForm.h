#include <iostream>

#include "SupportedGames.cpp"

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
			ModsList->GetType()->GetProperty("DoubleBuffered",
				System::Reflection::BindingFlags::Instance | System::Reflection::BindingFlags::NonPublic)
				->SetValue(this->ModsList, true);
			btd6Install = InfernoModManager::Games::GetGameDir(960090);
			PopulateModsList();

			for each (const char* type in InfernoModManager::Games::Types) {
				System::IO::FileSystemWatcher^ typeWatcher = gcnew System::IO::FileSystemWatcher();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(typeWatcher))->BeginInit();
				typeWatcher->EnableRaisingEvents = true;
				typeWatcher->NotifyFilter = static_cast<System::IO::NotifyFilters>(
					System::IO::NotifyFilters::FileName | System::IO::NotifyFilters::LastWrite | System::IO::NotifyFilters::CreationTime);
				typeWatcher->SynchronizingObject = this;
				typeWatcher->Changed += gcnew System::IO::FileSystemEventHandler(this, &MainForm::FolderUpdate);
				typeWatcher->Created += gcnew System::IO::FileSystemEventHandler(this, &MainForm::FolderUpdate);
				typeWatcher->Deleted += gcnew System::IO::FileSystemEventHandler(this, &MainForm::FolderUpdate);
				typeWatcher->Renamed += gcnew System::IO::RenamedEventHandler(this, &MainForm::FolderUpdate);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(typeWatcher))->EndInit();
				typeWatcher->Path = btd6Install;
			}
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


		private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
		private: System::Windows::Forms::DataGridView^ ModsList;
		private: System::Windows::Forms::DataGridViewCheckBoxColumn^ EnabledColumn;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameColumn;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ TypeColumn;








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
			this->BTD6FolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ModsList = (gcnew System::Windows::Forms::DataGridView());
			this->EnabledColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->NameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->BeginInit();
			this->SuspendLayout();
			//
			// tableLayoutPanel2
			//
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->Controls->Add(this->ModsList, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1000, 750);
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
				this->EnabledColumn,
					this->NameColumn, this->TypeColumn
			});
			this->tableLayoutPanel2->SetColumnSpan(this->ModsList, 3);
			this->ModsList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModsList->Location = System::Drawing::Point(3, 23);
			this->ModsList->MultiSelect = false;
			this->ModsList->Name = L"ModsList";
			this->ModsList->RowHeadersVisible = false;
			this->ModsList->RowHeadersWidth = 51;
			this->ModsList->RowTemplate->Height = 24;
			this->ModsList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ModsList->ShowCellErrors = false;
			this->ModsList->ShowEditingIcon = false;
			this->ModsList->ShowRowErrors = false;
			this->ModsList->Size = System::Drawing::Size(994, 724);
			this->ModsList->TabIndex = 3;
			this->ModsList->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::ModsList_CellContentClick);
			this->ModsList->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::ModsList_CellContentClick);
			this->ModsList->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::ModsList_CellEndEdit);
			//
			// EnabledColumn
			//
			this->EnabledColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->EnabledColumn->HeaderText = L"Enabled";
			this->EnabledColumn->MinimumWidth = 6;
			this->EnabledColumn->Name = L"EnabledColumn";
			this->EnabledColumn->Width = 66;
			//
			// NameColumn
			//
			this->NameColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->NameColumn->HeaderText = L"Name";
			this->NameColumn->MinimumWidth = 6;
			this->NameColumn->Name = L"NameColumn";
			this->NameColumn->ReadOnly = true;
			//
			// TypeColumn
			//
			this->TypeColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->TypeColumn->HeaderText = L"Type";
			this->TypeColumn->MinimumWidth = 6;
			this->TypeColumn->Name = L"TypeColumn";
			this->TypeColumn->ReadOnly = true;
			this->TypeColumn->Width = 69;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::String^ btd6Install = nullptr;

		private: System::Void ModsList_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
			if (btd6Install != nullptr) {
				//bool toggle =
			}
		}

		private: System::Void FolderUpdate(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
			PopulateModsList();
		}
		private: System::Void FolderUpdate(System::Object^ sender, System::IO::RenamedEventArgs^ e) {
			FolderUpdate(sender, (System::IO::FileSystemEventArgs^)e);
		}

		//you gotta do this because microsoft forgot about the checkboxes, I have this tied to content click and double click
		private: System::Void ModsList_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->ColumnIndex == EnabledColumn->Index)
				ModsList->EndEdit();
		}

		private: System::Void ModsList_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->ColumnIndex == EnabledColumn->Index)
				System::Console::WriteLine("hello");
		}

		private: bool IsEnabled(System::String^ file) {
			return !file->EndsWith(".disabled");
		}

		private: System::Void PopulateModsList() {
			array<System::String^>^ files = System::IO::Directory::GetFiles(btd6Install + "\\Mods");
			ModsList->Rows->Clear();
			for each (System::String ^ file in files)
				if (InfernoModManager::Games::IsCompatibleType(file))
					ModsList->Rows->Add(IsEnabled(file), NameOf(file), TypeOf(file));
			ModsList->Sort(NameColumn, System::ComponentModel::ListSortDirection::Ascending);
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
