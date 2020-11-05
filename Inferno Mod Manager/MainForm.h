#include <iostream>

#include "SupportedGames.cpp"
#include "Injection.h"

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
				typeWatcher->Filter = '*' + msclr::interop::marshal_as<System::String^>(type);
				typeWatcher->SynchronizingObject = this;
				typeWatcher->Changed += gcnew System::IO::FileSystemEventHandler(this, &MainForm::FolderUpdate);
				typeWatcher->Created += gcnew System::IO::FileSystemEventHandler(this, &MainForm::FolderUpdate);
				typeWatcher->Deleted += gcnew System::IO::FileSystemEventHandler(this, &MainForm::FolderUpdate);
				typeWatcher->Renamed += gcnew System::IO::RenamedEventHandler(this, &MainForm::FolderUpdate);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(typeWatcher))->EndInit();
				typeWatcher->Path = btd6Install;
			}

			CheckBTD6Open();
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
	private: System::Windows::Forms::Button^ DoModsButton;
	private: System::Windows::Forms::Timer^ CheckBTD6Timer;
	private: System::Windows::Forms::Label^ ModName;
	private: System::Windows::Forms::Label^ ModType;
	private: System::Windows::Forms::Label^ ModEnabled;




	private: System::ComponentModel::IContainer^ components;








		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label2;
			this->BTD6FolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ModName = (gcnew System::Windows::Forms::Label());
			this->DoModsButton = (gcnew System::Windows::Forms::Button());
			this->ModsList = (gcnew System::Windows::Forms::DataGridView());
			this->EnabledColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->NameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ModType = (gcnew System::Windows::Forms::Label());
			this->ModEnabled = (gcnew System::Windows::Forms::Label());
			this->CheckBTD6Timer = (gcnew System::Windows::Forms::Timer(this->components));
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Location = System::Drawing::Point(1003, 71);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(44, 17);
			label1->TabIndex = 5;
			label1->Text = L"Type:";
			// 
			// label2
			// 
			label2->AutoSize = true;
			label2->Location = System::Drawing::Point(1003, 54);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(64, 17);
			label2->TabIndex = 8;
			label2->Text = L"Enabled:";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->Controls->Add(this->ModName, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->DoModsButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->ModsList, 0, 1);
			this->tableLayoutPanel2->Controls->Add(label1, 1, 3);
			this->tableLayoutPanel2->Controls->Add(label2, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->ModType, 2, 3);
			this->tableLayoutPanel2->Controls->Add(this->ModEnabled, 2, 2);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1319, 750);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// ModName
			// 
			this->ModName->AutoSize = true;
			this->tableLayoutPanel2->SetColumnSpan(this->ModName, 2);
			this->ModName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ModName->Location = System::Drawing::Point(1003, 29);
			this->ModName->Name = L"ModName";
			this->ModName->Size = System::Drawing::Size(108, 25);
			this->ModName->TabIndex = 4;
			this->ModName->Text = L"Mod Name";
			// 
			// DoModsButton
			// 
			this->DoModsButton->Location = System::Drawing::Point(3, 3);
			this->DoModsButton->Name = L"DoModsButton";
			this->DoModsButton->Size = System::Drawing::Size(75, 23);
			this->DoModsButton->TabIndex = 1;
			this->DoModsButton->Text = L"Launch";
			this->DoModsButton->UseVisualStyleBackColor = true;
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
			this->ModsList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModsList->Location = System::Drawing::Point(3, 32);
			this->ModsList->MultiSelect = false;
			this->ModsList->Name = L"ModsList";
			this->ModsList->RowHeadersVisible = false;
			this->ModsList->RowHeadersWidth = 51;
			this->tableLayoutPanel2->SetRowSpan(this->ModsList, 3);
			this->ModsList->RowTemplate->Height = 24;
			this->ModsList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ModsList->ShowCellErrors = false;
			this->ModsList->ShowEditingIcon = false;
			this->ModsList->ShowRowErrors = false;
			this->ModsList->Size = System::Drawing::Size(994, 715);
			this->ModsList->TabIndex = 3;
			this->ModsList->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::ModsList_CellContentClick);
			this->ModsList->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::ModsList_CellContentClick);
			this->ModsList->SelectionChanged += gcnew System::EventHandler(this, &MainForm::ModsList_SelectionChanged);
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
			// ModType
			// 
			this->ModType->AutoSize = true;
			this->ModType->Location = System::Drawing::Point(1073, 71);
			this->ModType->Name = L"ModType";
			this->ModType->Size = System::Drawing::Size(71, 17);
			this->ModType->TabIndex = 7;
			this->ModType->Text = L"Mod Type";
			// 
			// ModEnabled
			// 
			this->ModEnabled->AutoSize = true;
			this->ModEnabled->Location = System::Drawing::Point(1073, 54);
			this->ModEnabled->Name = L"ModEnabled";
			this->ModEnabled->Size = System::Drawing::Size(91, 17);
			this->ModEnabled->TabIndex = 9;
			this->ModEnabled->Text = L"Mod Enabled";
			// 
			// CheckBTD6Timer
			// 
			this->CheckBTD6Timer->Enabled = true;
			this->CheckBTD6Timer->Interval = 1000;
			this->CheckBTD6Timer->Tick += gcnew System::EventHandler(this, &MainForm::CheckBTD6Open);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1319, 750);
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

		private: System::Void ModsList_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->ColumnIndex == EnabledColumn->Index) {
				ModsList->EndEdit();
				System::Windows::Forms::DataGridViewRow^ row = ModsList->Rows[e->RowIndex];
				if (((System::String^)row->Cells[2]->Value)->Contains(".dll")) {
					System::String^ oldName;
					System::String^ newName;
					if ((bool)row->Cells[0]->Value) {
						oldName = btd6Install + "\\Mods\\" + row->Cells[1]->Value + ".dll.disabled";
						newName = System::IO::Path::ChangeExtension(oldName, "");
					}
					else {
						oldName = btd6Install + "\\Mods\\" + row->Cells[1]->Value + ".dll";
						newName = System::IO::Path::ChangeExtension(oldName, ".dll.disabled");
					}
					System::IO::File::Move(oldName, newName);
				}
			}
		}

		private: System::Void CheckBTD6Open(System::Object^ sender, System::EventArgs^ e) {
			CheckBTD6Open();
		}

		private: System::Void ModsList_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
			UpdateStats(ModsList->SelectedRows[0]->Index);
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
			UpdateStats(0);
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

		private: System::Void CheckBTD6Open() {
			if (InfernoModManager::Injection::GetTargetThreadIDFromProcName("BloonsTD6") != -1)
				DoModsButton->Text = "Inject";
			else
				DoModsButton->Text = "Launch";
		}

		private: System::Void UpdateStats(int rowIndex) {
			System::Windows::Forms::DataGridViewRow^ row = ModsList->Rows[rowIndex];
			ModName->Text = (System::String^)row->Cells[1]->Value;
			ModEnabled->Text = ((System::Boolean^)row->Cells[0]->Value)->ToString();
			ModType->Text = (System::String^)row->Cells[2]->Value;
		}
};
}
