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
	private: System::Windows::Forms::TableLayoutPanel^ DownloadManager;
	private: System::Windows::Forms::LinkLabel^ DownloadUrl;
	private: System::Windows::Forms::Label^ DownloadName;
	private: System::Windows::Forms::Label^ DownloadAuthor;
	private: System::Windows::Forms::Label^ DownloadTags;
	private: System::Windows::Forms::PictureBox^ DownloadImage;









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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->ModManager = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ModName = (gcnew System::Windows::Forms::Label());
			this->ModsList = (gcnew System::Windows::Forms::DataGridView());
			this->EnabledColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->NameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ModDescription = (gcnew System::Windows::Forms::Label());
			this->ModType = (gcnew System::Windows::Forms::Label());
			this->ModEnabled = (gcnew System::Windows::Forms::Label());
			this->DoModsButton = (gcnew System::Windows::Forms::Button());
			this->BTD6FolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->CheckBTD6Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Tabs = (gcnew System::Windows::Forms::TabControl());
			this->ManagerTab = (gcnew System::Windows::Forms::TabPage());
			this->DownloadTab = (gcnew System::Windows::Forms::TabPage());
			this->DownloadManager = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DownloadUrl = (gcnew System::Windows::Forms::LinkLabel());
			this->DownloadName = (gcnew System::Windows::Forms::Label());
			this->DownloadAuthor = (gcnew System::Windows::Forms::Label());
			this->DownloadTags = (gcnew System::Windows::Forms::Label());
			this->DownloadImage = (gcnew System::Windows::Forms::PictureBox());
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			label6 = (gcnew System::Windows::Forms::Label());
			this->ModManager->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->BeginInit();
			this->Tabs->SuspendLayout();
			this->ManagerTab->SuspendLayout();
			this->DownloadTab->SuspendLayout();
			this->DownloadManager->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadImage))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label1->Location = System::Drawing::Point(877, 91);
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
			label2->Location = System::Drawing::Point(877, 74);
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
			label3->Location = System::Drawing::Point(877, 128);
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
			label4->Location = System::Drawing::Point(877, 63);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(431, 2);
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
			label6->Location = System::Drawing::Point(877, 117);
			label6->Name = L"label6";
			label6->Size = System::Drawing::Size(431, 2);
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
			this->ModManager->Controls->Add(this->ModsList, 0, 1);
			this->ModManager->Controls->Add(label3, 1, 6);
			this->ModManager->Controls->Add(this->ModDescription, 1, 7);
			this->ModManager->Controls->Add(label4, 1, 2);
			this->ModManager->Controls->Add(label1, 1, 4);
			this->ModManager->Controls->Add(label2, 1, 3);
			this->ModManager->Controls->Add(this->ModType, 2, 4);
			this->ModManager->Controls->Add(this->ModEnabled, 2, 3);
			this->ModManager->Controls->Add(this->DoModsButton, 0, 0);
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
			this->ModManager->Size = System::Drawing::Size(1311, 721);
			this->ModManager->TabIndex = 0;
			// 
			// ModName
			// 
			this->ModName->AutoSize = true;
			this->ModManager->SetColumnSpan(this->ModName, 2);
			this->ModName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ModName->Location = System::Drawing::Point(877, 29);
			this->ModName->Name = L"ModName";
			this->ModName->Size = System::Drawing::Size(108, 25);
			this->ModName->TabIndex = 4;
			this->ModName->Text = L"Mod Name";
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
			this->ModManager->SetRowSpan(this->ModsList, 7);
			this->ModsList->RowTemplate->Height = 24;
			this->ModsList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ModsList->ShowCellErrors = false;
			this->ModsList->ShowEditingIcon = false;
			this->ModsList->ShowRowErrors = false;
			this->ModsList->Size = System::Drawing::Size(868, 715);
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
			// ModDescription
			// 
			this->ModDescription->AutoSize = true;
			this->ModDescription->Location = System::Drawing::Point(877, 145);
			this->ModDescription->Name = L"ModDescription";
			this->ModDescription->Size = System::Drawing::Size(110, 17);
			this->ModDescription->TabIndex = 11;
			this->ModDescription->Text = L"Mod Description";
			// 
			// ModType
			// 
			this->ModType->AutoSize = true;
			this->ModType->Location = System::Drawing::Point(1095, 91);
			this->ModType->Name = L"ModType";
			this->ModType->Size = System::Drawing::Size(71, 17);
			this->ModType->TabIndex = 7;
			this->ModType->Text = L"Mod Type";
			// 
			// ModEnabled
			// 
			this->ModEnabled->AutoSize = true;
			this->ModEnabled->Location = System::Drawing::Point(1095, 74);
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
			// 
			// CheckBTD6Timer
			// 
			this->CheckBTD6Timer->Enabled = true;
			this->CheckBTD6Timer->Interval = 1000;
			this->CheckBTD6Timer->Tick += gcnew System::EventHandler(this, &MainForm::CheckBTD6Open);
			// 
			// Tabs
			// 
			this->Tabs->Controls->Add(this->ManagerTab);
			this->Tabs->Controls->Add(this->DownloadTab);
			this->Tabs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Tabs->Location = System::Drawing::Point(0, 0);
			this->Tabs->Name = L"Tabs";
			this->Tabs->SelectedIndex = 0;
			this->Tabs->Size = System::Drawing::Size(1319, 750);
			this->Tabs->TabIndex = 1;
			// 
			// ManagerTab
			// 
			this->ManagerTab->Controls->Add(this->ModManager);
			this->ManagerTab->Location = System::Drawing::Point(4, 25);
			this->ManagerTab->Name = L"ManagerTab";
			this->ManagerTab->Size = System::Drawing::Size(1311, 721);
			this->ManagerTab->TabIndex = 1;
			this->ManagerTab->Text = L"Manager";
			this->ManagerTab->UseVisualStyleBackColor = true;
			// 
			// DownloadTab
			// 
			this->DownloadTab->Controls->Add(this->DownloadManager);
			this->DownloadTab->Location = System::Drawing::Point(4, 25);
			this->DownloadTab->Name = L"DownloadTab";
			this->DownloadTab->Size = System::Drawing::Size(1311, 721);
			this->DownloadTab->TabIndex = 0;
			this->DownloadTab->Text = L"Download";
			this->DownloadTab->UseVisualStyleBackColor = true;
			// 
			// DownloadManager
			// 
			this->DownloadManager->ColumnCount = 1;
			this->DownloadManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->DownloadManager->Controls->Add(this->DownloadUrl, 0, 0);
			this->DownloadManager->Controls->Add(this->DownloadName, 0, 1);
			this->DownloadManager->Controls->Add(this->DownloadAuthor, 0, 2);
			this->DownloadManager->Controls->Add(this->DownloadTags, 0, 3);
			this->DownloadManager->Controls->Add(this->DownloadImage, 0, 4);
			this->DownloadManager->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadManager->Location = System::Drawing::Point(0, 0);
			this->DownloadManager->Name = L"DownloadManager";
			this->DownloadManager->RowCount = 5;
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->Size = System::Drawing::Size(1311, 721);
			this->DownloadManager->TabIndex = 0;
			// 
			// DownloadUrl
			// 
			this->DownloadUrl->AutoSize = true;
			this->DownloadUrl->Location = System::Drawing::Point(3, 0);
			this->DownloadUrl->Name = L"DownloadUrl";
			this->DownloadUrl->Size = System::Drawing::Size(92, 17);
			this->DownloadUrl->TabIndex = 0;
			this->DownloadUrl->TabStop = true;
			this->DownloadUrl->Text = L"Download Url";
			// 
			// DownloadName
			// 
			this->DownloadName->AutoSize = true;
			this->DownloadName->Location = System::Drawing::Point(3, 17);
			this->DownloadName->Name = L"DownloadName";
			this->DownloadName->Size = System::Drawing::Size(111, 17);
			this->DownloadName->TabIndex = 1;
			this->DownloadName->Text = L"Download Name";
			// 
			// DownloadAuthor
			// 
			this->DownloadAuthor->AutoSize = true;
			this->DownloadAuthor->Location = System::Drawing::Point(3, 34);
			this->DownloadAuthor->Name = L"DownloadAuthor";
			this->DownloadAuthor->Size = System::Drawing::Size(116, 17);
			this->DownloadAuthor->TabIndex = 2;
			this->DownloadAuthor->Text = L"Download Author";
			// 
			// DownloadTags
			// 
			this->DownloadTags->AutoSize = true;
			this->DownloadTags->Location = System::Drawing::Point(3, 51);
			this->DownloadTags->Name = L"DownloadTags";
			this->DownloadTags->Size = System::Drawing::Size(106, 17);
			this->DownloadTags->TabIndex = 3;
			this->DownloadTags->Text = L"Download Tags";
			// 
			// DownloadImage
			// 
			this->DownloadImage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DownloadImage.Image")));
			this->DownloadImage->Location = System::Drawing::Point(3, 71);
			this->DownloadImage->Name = L"DownloadImage";
			this->DownloadImage->Size = System::Drawing::Size(1305, 647);
			this->DownloadImage->TabIndex = 4;
			this->DownloadImage->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1319, 750);
			this->Controls->Add(this->Tabs);
			this->Name = L"MainForm";
			this->Text = L"Inferno Mod Manager";
			this->ModManager->ResumeLayout(false);
			this->ModManager->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->EndInit();
			this->Tabs->ResumeLayout(false);
			this->ManagerTab->ResumeLayout(false);
			this->DownloadTab->ResumeLayout(false);
			this->DownloadManager->ResumeLayout(false);
			this->DownloadManager->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadImage))->EndInit();
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
