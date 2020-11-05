#include <iostream>
#include <vector>

#include "SupportedGames.cpp"
#include "Injection.h"
#include "WebDownloader.h"
#include "Mod.h"

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
				System::IO::FileSystemWatcher^ typeWatcher =
					gcnew System::IO::FileSystemWatcher(btd6Install, '*' + msclr::interop::marshal_as<System::String^>(type));
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
			}

			CheckBTD6Open();

			UpdateDownloadTab(InfernoModManager::WebDownloader::getAllData()[0]);
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


		private: System::Windows::Forms::DataGridView^ ModsList;
		private: System::Windows::Forms::DataGridViewCheckBoxColumn^ EnabledColumn;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameColumn;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ TypeColumn;
	private: System::Windows::Forms::Button^ DoModsButton;
	private: System::Windows::Forms::Timer^ CheckBTD6Timer;
	private: System::Windows::Forms::Label^ ModName;
	private: System::Windows::Forms::Label^ ModType;
	private: System::Windows::Forms::Label^ ModEnabled;
	private: System::Windows::Forms::Label^ ModDescription;
	private: System::Windows::Forms::TabControl^ Tabs;
	private: System::Windows::Forms::TabPage^ DownloadTab;

	private: System::Windows::Forms::TableLayoutPanel^ ModManager;
	private: System::Windows::Forms::TabPage^ ManagerTab;
	private: System::Windows::Forms::DataGridView^ DownloadsList;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ InstalledColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DownloadNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DownloadTypeColumn;





















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
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ label4;
			System::Windows::Forms::Label^ label6;
			this->ModManager = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ModName = (gcnew System::Windows::Forms::Label());
			this->ModDescription = (gcnew System::Windows::Forms::Label());
			this->ModType = (gcnew System::Windows::Forms::Label());
			this->ModEnabled = (gcnew System::Windows::Forms::Label());
			this->DoModsButton = (gcnew System::Windows::Forms::Button());
			this->Tabs = (gcnew System::Windows::Forms::TabControl());
			this->ManagerTab = (gcnew System::Windows::Forms::TabPage());
			this->ModsList = (gcnew System::Windows::Forms::DataGridView());
			this->EnabledColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->NameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DownloadTab = (gcnew System::Windows::Forms::TabPage());
			this->DownloadsList = (gcnew System::Windows::Forms::DataGridView());
			this->BTD6FolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->CheckBTD6Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->InstalledColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->DownloadNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DownloadTypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			label6 = (gcnew System::Windows::Forms::Label());
			this->ModManager->SuspendLayout();
			this->Tabs->SuspendLayout();
			this->ManagerTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->BeginInit();
			this->DownloadTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadsList))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label1->Location = System::Drawing::Point(882, 91);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(49, 17);
			label1->TabIndex = 5;
			label1->Text = L"Type:";
			// 
			// label2
			// 
			label2->AutoSize = true;
			label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label2->Location = System::Drawing::Point(882, 74);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(72, 17);
			label2->TabIndex = 8;
			label2->Text = L"Enabled:";
			// 
			// label3
			// 
			label3->AutoSize = true;
			label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label3->Location = System::Drawing::Point(882, 128);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(95, 17);
			label3->TabIndex = 10;
			label3->Text = L"Description:";
			// 
			// label4
			// 
			label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			label4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ModManager->SetColumnSpan(label4, 2);
			label4->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			label4->Location = System::Drawing::Point(882, 63);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(434, 2);
			label4->TabIndex = 12;
			label4->Text = L"label4";
			// 
			// label6
			// 
			label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			label6->BackColor = System::Drawing::SystemColors::ActiveBorder;
			label6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ModManager->SetColumnSpan(label6, 2);
			label6->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			label6->Location = System::Drawing::Point(882, 117);
			label6->Name = L"label6";
			label6->Size = System::Drawing::Size(434, 2);
			label6->TabIndex = 14;
			label6->Text = L"label6";
			// 
			// ModManager
			// 
			this->ModManager->ColumnCount = 3;
			this->ModManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 66.67F)));
			this->ModManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.665F)));
			this->ModManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.665F)));
			this->ModManager->Controls->Add(label6, 1, 5);
			this->ModManager->Controls->Add(this->ModName, 1, 1);
			this->ModManager->Controls->Add(label3, 1, 6);
			this->ModManager->Controls->Add(this->ModDescription, 1, 7);
			this->ModManager->Controls->Add(label4, 1, 2);
			this->ModManager->Controls->Add(label1, 1, 4);
			this->ModManager->Controls->Add(label2, 1, 3);
			this->ModManager->Controls->Add(this->ModType, 2, 4);
			this->ModManager->Controls->Add(this->ModEnabled, 2, 3);
			this->ModManager->Controls->Add(this->DoModsButton, 0, 0);
			this->ModManager->Controls->Add(this->Tabs, 0, 1);
			this->ModManager->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModManager->Location = System::Drawing::Point(0, 0);
			this->ModManager->Name = L"ModManager";
			this->ModManager->RowCount = 7;
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->ModManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->ModManager->Size = System::Drawing::Size(1319, 750);
			this->ModManager->TabIndex = 0;
			// 
			// ModName
			// 
			this->ModName->AutoSize = true;
			this->ModManager->SetColumnSpan(this->ModName, 2);
			this->ModName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ModName->Location = System::Drawing::Point(882, 29);
			this->ModName->Name = L"ModName";
			this->ModName->Size = System::Drawing::Size(108, 25);
			this->ModName->TabIndex = 4;
			this->ModName->Text = L"Mod Name";
			// 
			// ModDescription
			// 
			this->ModDescription->AutoSize = true;
			this->ModDescription->Location = System::Drawing::Point(882, 145);
			this->ModDescription->Name = L"ModDescription";
			this->ModDescription->Size = System::Drawing::Size(110, 17);
			this->ModDescription->TabIndex = 11;
			this->ModDescription->Text = L"Mod Description";
			// 
			// ModType
			// 
			this->ModType->AutoSize = true;
			this->ModType->Location = System::Drawing::Point(1101, 91);
			this->ModType->Name = L"ModType";
			this->ModType->Size = System::Drawing::Size(71, 17);
			this->ModType->TabIndex = 7;
			this->ModType->Text = L"Mod Type";
			// 
			// ModEnabled
			// 
			this->ModEnabled->AutoSize = true;
			this->ModEnabled->Location = System::Drawing::Point(1101, 74);
			this->ModEnabled->Name = L"ModEnabled";
			this->ModEnabled->Size = System::Drawing::Size(91, 17);
			this->ModEnabled->TabIndex = 9;
			this->ModEnabled->Text = L"Mod Enabled";
			// 
			// DoModsButton
			// 
			this->DoModsButton->Location = System::Drawing::Point(3, 3);
			this->DoModsButton->Name = L"DoModsButton";
			this->DoModsButton->Size = System::Drawing::Size(75, 23);
			this->DoModsButton->TabIndex = 1;
			this->DoModsButton->Text = L"Launch";
			this->DoModsButton->UseVisualStyleBackColor = true;
			this->DoModsButton->Click += gcnew System::EventHandler(this, &MainForm::LaunchGame);
			// 
			// Tabs
			// 
			this->Tabs->Controls->Add(this->ManagerTab);
			this->Tabs->Controls->Add(this->DownloadTab);
			this->Tabs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Tabs->Location = System::Drawing::Point(3, 32);
			this->Tabs->Name = L"Tabs";
			this->ModManager->SetRowSpan(this->Tabs, 7);
			this->Tabs->SelectedIndex = 0;
			this->Tabs->Size = System::Drawing::Size(873, 715);
			this->Tabs->TabIndex = 1;
			// 
			// ManagerTab
			// 
			this->ManagerTab->Controls->Add(this->ModsList);
			this->ManagerTab->Location = System::Drawing::Point(4, 25);
			this->ManagerTab->Name = L"ManagerTab";
			this->ManagerTab->Size = System::Drawing::Size(865, 686);
			this->ManagerTab->TabIndex = 1;
			this->ManagerTab->Text = L"Manager";
			this->ManagerTab->UseVisualStyleBackColor = true;
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
			this->ModsList->Location = System::Drawing::Point(0, 0);
			this->ModsList->MultiSelect = false;
			this->ModsList->Name = L"ModsList";
			this->ModsList->RowHeadersVisible = false;
			this->ModsList->RowHeadersWidth = 51;
			this->ModsList->RowTemplate->Height = 24;
			this->ModsList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ModsList->ShowCellErrors = false;
			this->ModsList->ShowEditingIcon = false;
			this->ModsList->ShowRowErrors = false;
			this->ModsList->Size = System::Drawing::Size(865, 686);
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
			// DownloadTab
			// 
			this->DownloadTab->Controls->Add(this->DownloadsList);
			this->DownloadTab->Location = System::Drawing::Point(4, 25);
			this->DownloadTab->Name = L"DownloadTab";
			this->DownloadTab->Size = System::Drawing::Size(865, 686);
			this->DownloadTab->TabIndex = 0;
			this->DownloadTab->Text = L"Download";
			this->DownloadTab->UseVisualStyleBackColor = true;
			// 
			// DownloadsList
			// 
			this->DownloadsList->AllowUserToAddRows = false;
			this->DownloadsList->AllowUserToDeleteRows = false;
			this->DownloadsList->AllowUserToResizeColumns = false;
			this->DownloadsList->AllowUserToResizeRows = false;
			this->DownloadsList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DownloadsList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->InstalledColumn,
					this->DownloadNameColumn, this->DownloadTypeColumn
			});
			this->DownloadsList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadsList->Location = System::Drawing::Point(0, 0);
			this->DownloadsList->MultiSelect = false;
			this->DownloadsList->Name = L"DownloadsList";
			this->DownloadsList->RowHeadersVisible = false;
			this->DownloadsList->RowHeadersWidth = 51;
			this->DownloadsList->RowTemplate->Height = 24;
			this->DownloadsList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->DownloadsList->ShowCellErrors = false;
			this->DownloadsList->ShowEditingIcon = false;
			this->DownloadsList->ShowRowErrors = false;
			this->DownloadsList->Size = System::Drawing::Size(865, 686);
			this->DownloadsList->TabIndex = 4;
			// 
			// CheckBTD6Timer
			// 
			this->CheckBTD6Timer->Enabled = true;
			this->CheckBTD6Timer->Interval = 1000;
			this->CheckBTD6Timer->Tick += gcnew System::EventHandler(this, &MainForm::CheckBTD6Open);
			// 
			// InstalledColumn
			// 
			this->InstalledColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->InstalledColumn->HeaderText = L"Installed";
			this->InstalledColumn->MinimumWidth = 6;
			this->InstalledColumn->Name = L"InstalledColumn";
			this->InstalledColumn->Width = 66;
			// 
			// DownloadNameColumn
			// 
			this->DownloadNameColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->DownloadNameColumn->HeaderText = L"Name";
			this->DownloadNameColumn->MinimumWidth = 6;
			this->DownloadNameColumn->Name = L"DownloadNameColumn";
			this->DownloadNameColumn->ReadOnly = true;
			// 
			// DownloadTypeColumn
			// 
			this->DownloadTypeColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->DownloadTypeColumn->HeaderText = L"Type";
			this->DownloadTypeColumn->MinimumWidth = 6;
			this->DownloadTypeColumn->Name = L"DownloadTypeColumn";
			this->DownloadTypeColumn->ReadOnly = true;
			this->DownloadTypeColumn->Width = 69;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1319, 750);
			this->Controls->Add(this->ModManager);
			this->Name = L"MainForm";
			this->Text = L"Inferno Mod Manager";
			this->ModManager->ResumeLayout(false);
			this->ModManager->PerformLayout();
			this->Tabs->ResumeLayout(false);
			this->ManagerTab->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->EndInit();
			this->DownloadTab->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadsList))->EndInit();
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
				ModsList->EndEdit(); //makes changes actually register
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
			UpdateStats(ModsList->SelectedRows[0]->Index, false);
		}

		private: System::Void LaunchGame(System::Object^ sender, System::EventArgs^ e)
		{
			System::Diagnostics::ProcessStartInfo^ psi = gcnew System::Diagnostics::ProcessStartInfo("steam://rungameid/960090");
			System::Diagnostics::Process::Start(psi);
			System::Threading::Thread::Sleep(5);
		}

		private: bool IsEnabled(System::String^ file) {
			return !file->EndsWith(".disabled");
		}

		private: System::Void PopulateModsList() {
			array<System::String^>^ files = System::IO::Directory::GetFiles(btd6Install + "\\Mods");
			InfernoModManager::Mod::Installed->Clear();
			ModsList->Rows->Clear();
			for each (System::String ^ file in files) {
				if (InfernoModManager::Games::IsCompatibleType(file)) {
					System::String^ name = NameOf(file);
					System::String^ type = TypeOf(file);
					System::Boolean^ enabled = IsEnabled(file);
					ModsList->Rows->Add(enabled, name, type);
					InfernoModManager::Mod::Installed->Add(gcnew InfernoModManager::Mod(name, "noone", "1.0", "other", type, "a mod",
						file, "", enabled));
				}
			}
			ModsList->Sort(NameColumn, System::ComponentModel::ListSortDirection::Ascending);
			UpdateStats(0, false);
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

		private: System::Void UpdateStats(int index, bool isDownload) {
			InfernoModManager::Mod^ mod = (isDownload ? InfernoModManager::Mod::Available : InfernoModManager::Mod::Installed)[index];
			ModName->Text = mod->Name;
			ModEnabled->Text = mod->Status->ToString();
			ModType->Text = mod->Type;
			ModDescription->Text = mod->Description;
		}

		private: System::Void UpdateDownloadTab(const char* data) {
			array<System::String^>^ dataList = msclr::interop::marshal_as<System::String^>(data)->Split('<');
			/*DownloadUrl->Text = dataList[0];
			DownloadName->Text = dataList[1];
			DownloadAuthor->Text = dataList[2];
			DownloadDescription->Text = dataList[3];
			DownloadTags->Text = dataList[4];
			System::IO::MemoryStream^ img = gcnew System::IO::MemoryStream(System::Convert::FromBase64String(dataList[5]));
			DownloadImage->Image = System::Drawing::Image::FromStream(img);
			img->Close();
			delete img;*/
		}
};
}
