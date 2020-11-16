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
			if (!System::IO::File::Exists("LuckiestGuy.ttf"))
			{
				InfernoModManager::WebDownloader::downloadFile("https://github.com/Inferno-Dev-Team/Assets/blob/main/Luckiest_Guy/LuckiestGuy-Regular.ttf?raw=true", "LuckiestGuy.ttf");
			}
			fontCollection = gcnew System::Drawing::Text::PrivateFontCollection();
			fontCollection->AddFontFile(System::IO::Path::GetFullPath("LuckiestGuy.ttf"));

			InitializeComponent();

			//double buffered renders all at once, therefore faster
			System::Windows::Forms::DataGridView::typeid->GetProperty("DoubleBuffered",
				System::Reflection::BindingFlags::Instance | System::Reflection::BindingFlags::NonPublic)
				->SetValue(this->ModsList, true);
			btd6Install = InfernoModManager::Games::GetGameDir(960090);
			System::IO::Directory::CreateDirectory(GetDisabledDir());
			GetInstalled();
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

	private: System::Drawing::Text::PrivateFontCollection^ fontCollection;
		private: System::Windows::Forms::FolderBrowserDialog^ BTD6FolderDialog;

		private: System::Windows::Forms::DataGridView^ ModsList;

	private: System::Windows::Forms::Button^ DoModsButton;
	private: System::Windows::Forms::Timer^ CheckBTD6Timer;

	private: System::Windows::Forms::Label^ ModType;
	private: System::Windows::Forms::Label^ ModEnabled;
	private: System::Windows::Forms::Label^ ModDescription;
	private: System::Windows::Forms::TabControl^ Tabs;
	private: System::Windows::Forms::TabPage^ DownloadTab;

	private: System::Windows::Forms::TableLayoutPanel^ ModManager;
	private: System::Windows::Forms::TabPage^ ManagerTab;
	private: System::Windows::Forms::TableLayoutPanel^ DownloadManager;
	private: System::Windows::Forms::DataGridView^ DownloadsList;

	private: System::Windows::Forms::CheckBox^ ShowInstalledCheck;

	private: System::Windows::Forms::Label^ DownloadDescription;
	private: System::Windows::Forms::Label^ DownloadInstalled;
	private: System::Windows::Forms::Label^ DownloadType;
	private: System::Windows::Forms::Button^ DownloadMod;



	private: System::Windows::Forms::PictureBox^ DownloadImage;
	private: System::Windows::Forms::Label^ DownloadName;
	private: System::Windows::Forms::LinkLabel^ DownloadUrl;

	private: System::Windows::Forms::Label^ DownloadAuthor;
	private: System::Windows::Forms::Label^ DownloadTags;




	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ InstalledColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DownloadNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DownloadTypeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DownloadInfoColumn;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ EnabledColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ModNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ModTypeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ModInfoColumn;
	private: System::Windows::Forms::PictureBox^ ModImage;

	private: System::Windows::Forms::Label^ ModName;
	private: System::Windows::Forms::Button^ RemoveMod;









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
			System::Windows::Forms::Label^ label7;
			System::Windows::Forms::Label^ label8;
			System::Windows::Forms::Label^ label9;
			System::Windows::Forms::Label^ label10;
			System::Windows::Forms::Label^ label11;
			System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
			System::Windows::Forms::Label^ label5;
			System::Windows::Forms::Label^ label12;
			System::Windows::Forms::Label^ label13;
			System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->DownloadImage = (gcnew System::Windows::Forms::PictureBox());
			this->DownloadName = (gcnew System::Windows::Forms::Label());
			this->DownloadMod = (gcnew System::Windows::Forms::Button());
			this->ModName = (gcnew System::Windows::Forms::Label());
			this->ModImage = (gcnew System::Windows::Forms::PictureBox());
			this->RemoveMod = (gcnew System::Windows::Forms::Button());
			this->ModManager = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ModDescription = (gcnew System::Windows::Forms::Label());
			this->ModType = (gcnew System::Windows::Forms::Label());
			this->ModEnabled = (gcnew System::Windows::Forms::Label());
			this->DoModsButton = (gcnew System::Windows::Forms::Button());
			this->ModsList = (gcnew System::Windows::Forms::DataGridView());
			this->EnabledColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->ModNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ModTypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ModInfoColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DownloadsList = (gcnew System::Windows::Forms::DataGridView());
			this->InstalledColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->DownloadNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DownloadTypeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DownloadInfoColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Tabs = (gcnew System::Windows::Forms::TabControl());
			this->ManagerTab = (gcnew System::Windows::Forms::TabPage());
			this->DownloadTab = (gcnew System::Windows::Forms::TabPage());
			this->DownloadManager = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DownloadDescription = (gcnew System::Windows::Forms::Label());
			this->DownloadInstalled = (gcnew System::Windows::Forms::Label());
			this->DownloadType = (gcnew System::Windows::Forms::Label());
			this->ShowInstalledCheck = (gcnew System::Windows::Forms::CheckBox());
			this->DownloadUrl = (gcnew System::Windows::Forms::LinkLabel());
			this->DownloadAuthor = (gcnew System::Windows::Forms::Label());
			this->DownloadTags = (gcnew System::Windows::Forms::Label());
			this->BTD6FolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->CheckBTD6Timer = (gcnew System::Windows::Forms::Timer(this->components));
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			label6 = (gcnew System::Windows::Forms::Label());
			label7 = (gcnew System::Windows::Forms::Label());
			label8 = (gcnew System::Windows::Forms::Label());
			label9 = (gcnew System::Windows::Forms::Label());
			label10 = (gcnew System::Windows::Forms::Label());
			label11 = (gcnew System::Windows::Forms::Label());
			tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			label5 = (gcnew System::Windows::Forms::Label());
			label12 = (gcnew System::Windows::Forms::Label());
			label13 = (gcnew System::Windows::Forms::Label());
			tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadImage))->BeginInit();
			tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModImage))->BeginInit();
			this->ModManager->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadsList))->BeginInit();
			this->Tabs->SuspendLayout();
			this->ManagerTab->SuspendLayout();
			this->DownloadTab->SuspendLayout();
			this->DownloadManager->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label1->Location = System::Drawing::Point(877, 134);
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
			label2->Location = System::Drawing::Point(877, 117);
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
			label3->Location = System::Drawing::Point(877, 171);
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
			label4->Location = System::Drawing::Point(877, 106);
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
			label6->Location = System::Drawing::Point(877, 160);
			label6->Name = L"label6";
			label6->Size = System::Drawing::Size(431, 2);
			label6->TabIndex = 14;
			label6->Text = L"label6";
			// 
			// label7
			// 
			label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			label7->BackColor = System::Drawing::SystemColors::ActiveBorder;
			label7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DownloadManager->SetColumnSpan(label7, 2);
			label7->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			label7->Location = System::Drawing::Point(876, 102);
			label7->Name = L"label7";
			label7->Size = System::Drawing::Size(432, 2);
			label7->TabIndex = 13;
			label7->Text = L"label7";
			// 
			// label8
			// 
			label8->AutoSize = true;
			label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label8->Location = System::Drawing::Point(876, 113);
			label8->Name = L"label8";
			label8->Size = System::Drawing::Size(74, 1);
			label8->TabIndex = 14;
			label8->Text = L"Installed:";
			// 
			// label9
			// 
			label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			label9->AutoSize = true;
			label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label9->Location = System::Drawing::Point(876, 113);
			label9->Name = L"label9";
			label9->Size = System::Drawing::Size(212, 17);
			label9->TabIndex = 1;
			label9->Text = L"Type:";
			// 
			// label10
			// 
			label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			label10->BackColor = System::Drawing::SystemColors::ActiveBorder;
			label10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DownloadManager->SetColumnSpan(label10, 2);
			label10->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			label10->Location = System::Drawing::Point(876, 139);
			label10->Name = L"label10";
			label10->Size = System::Drawing::Size(432, 2);
			label10->TabIndex = 15;
			label10->Text = L"label10";
			// 
			// label11
			// 
			label11->AutoSize = true;
			label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label11->Location = System::Drawing::Point(876, 184);
			label11->Name = L"label11";
			label11->Size = System::Drawing::Size(95, 17);
			label11->TabIndex = 16;
			label11->Text = L"Description:";
			// 
			// tableLayoutPanel1
			// 
			tableLayoutPanel1->AutoSize = true;
			tableLayoutPanel1->ColumnCount = 3;
			this->DownloadManager->SetColumnSpan(tableLayoutPanel1, 2);
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			tableLayoutPanel1->Controls->Add(this->DownloadImage, 0, 0);
			tableLayoutPanel1->Controls->Add(this->DownloadName, 1, 0);
			tableLayoutPanel1->Controls->Add(this->DownloadMod, 2, 0);
			tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			tableLayoutPanel1->Location = System::Drawing::Point(873, 25);
			tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			tableLayoutPanel1->Name = L"tableLayoutPanel1";
			tableLayoutPanel1->RowCount = 1;
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			tableLayoutPanel1->Size = System::Drawing::Size(438, 68);
			tableLayoutPanel1->TabIndex = 21;
			// 
			// DownloadImage
			// 
			this->DownloadImage->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DownloadImage.ErrorImage")));
			this->DownloadImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DownloadImage.Image")));
			this->DownloadImage->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DownloadImage.InitialImage")));
			this->DownloadImage->Location = System::Drawing::Point(3, 2);
			this->DownloadImage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DownloadImage->Name = L"DownloadImage";
			this->DownloadImage->Size = System::Drawing::Size(64, 64);
			this->DownloadImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DownloadImage->TabIndex = 20;
			this->DownloadImage->TabStop = false;
			this->DownloadImage->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::Image_Paint);
			// 
			// DownloadName
			// 
			this->DownloadName->AutoSize = true;
			this->DownloadName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DownloadName->Location = System::Drawing::Point(73, 0);
			this->DownloadName->Name = L"DownloadName";
			this->DownloadName->Size = System::Drawing::Size(281, 68);
			this->DownloadName->TabIndex = 21;
			this->DownloadName->Text = L"Download Name";
			this->DownloadName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DownloadMod
			// 
			this->DownloadMod->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DownloadMod->Location = System::Drawing::Point(360, 22);
			this->DownloadMod->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DownloadMod->Name = L"DownloadMod";
			this->DownloadMod->Size = System::Drawing::Size(75, 23);
			this->DownloadMod->TabIndex = 1;
			this->DownloadMod->Text = L"Install";
			this->DownloadMod->UseVisualStyleBackColor = true;
			this->DownloadMod->Click += gcnew System::EventHandler(this, &MainForm::DownloadMod_Click);
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label5->Location = System::Drawing::Point(876, 150);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(61, 17);
			label5->TabIndex = 22;
			label5->Text = L"Author:";
			// 
			// label12
			// 
			label12->AutoSize = true;
			label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label12->Location = System::Drawing::Point(876, 704);
			label12->Name = L"label12";
			label12->Size = System::Drawing::Size(118, 17);
			label12->TabIndex = 23;
			label12->Text = L"Download Link:";
			// 
			// label13
			// 
			label13->AutoSize = true;
			label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label13->Location = System::Drawing::Point(876, 167);
			label13->Name = L"label13";
			label13->Size = System::Drawing::Size(49, 17);
			label13->TabIndex = 24;
			label13->Text = L"Tags:";
			// 
			// tableLayoutPanel2
			// 
			tableLayoutPanel2->AutoSize = true;
			tableLayoutPanel2->ColumnCount = 3;
			this->ModManager->SetColumnSpan(tableLayoutPanel2, 2);
			tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			tableLayoutPanel2->Controls->Add(this->ModName, 1, 0);
			tableLayoutPanel2->Controls->Add(this->ModImage, 0, 0);
			tableLayoutPanel2->Controls->Add(this->RemoveMod, 2, 0);
			tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			tableLayoutPanel2->Location = System::Drawing::Point(874, 27);
			tableLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
			tableLayoutPanel2->Name = L"tableLayoutPanel2";
			tableLayoutPanel2->RowCount = 1;
			tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			tableLayoutPanel2->Size = System::Drawing::Size(437, 70);
			tableLayoutPanel2->TabIndex = 15;
			// 
			// ModName
			// 
			this->ModName->AutoSize = true;
			this->ModName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ModName->Location = System::Drawing::Point(73, 0);
			this->ModName->Name = L"ModName";
			this->ModName->Size = System::Drawing::Size(280, 70);
			this->ModName->TabIndex = 22;
			this->ModName->Text = L"Mod Name";
			this->ModName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ModImage
			// 
			this->ModImage->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ModImage.ErrorImage")));
			this->ModImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ModImage.Image")));
			this->ModImage->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ModImage.InitialImage")));
			this->ModImage->Location = System::Drawing::Point(3, 3);
			this->ModImage->Name = L"ModImage";
			this->ModImage->Size = System::Drawing::Size(64, 64);
			this->ModImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ModImage->TabIndex = 0;
			this->ModImage->TabStop = false;
			this->ModImage->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::Image_Paint);
			// 
			// RemoveMod
			// 
			this->RemoveMod->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RemoveMod->Location = System::Drawing::Point(359, 23);
			this->RemoveMod->Name = L"RemoveMod";
			this->RemoveMod->Size = System::Drawing::Size(75, 23);
			this->RemoveMod->TabIndex = 23;
			this->RemoveMod->Text = L"Remove";
			this->RemoveMod->UseVisualStyleBackColor = true;
			this->RemoveMod->Click += gcnew System::EventHandler(this, &MainForm::RemoveMod_Click);
			// 
			// ModManager
			// 
			this->ModManager->ColumnCount = 3;
			this->ModManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 66.67F)));
			this->ModManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.665F)));
			this->ModManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.665F)));
			this->ModManager->Controls->Add(label6, 1, 5);
			this->ModManager->Controls->Add(label3, 1, 6);
			this->ModManager->Controls->Add(this->ModDescription, 1, 7);
			this->ModManager->Controls->Add(label4, 1, 2);
			this->ModManager->Controls->Add(label1, 1, 4);
			this->ModManager->Controls->Add(label2, 1, 3);
			this->ModManager->Controls->Add(this->ModType, 2, 4);
			this->ModManager->Controls->Add(this->ModEnabled, 2, 3);
			this->ModManager->Controls->Add(this->DoModsButton, 0, 0);
			this->ModManager->Controls->Add(this->ModsList, 0, 1);
			this->ModManager->Controls->Add(tableLayoutPanel2, 1, 1);
			this->ModManager->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModManager->Location = System::Drawing::Point(0, 0);
			this->ModManager->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->ModManager->Size = System::Drawing::Size(1311, 721);
			this->ModManager->TabIndex = 0;
			// 
			// ModDescription
			// 
			this->ModDescription->AutoSize = true;
			this->ModManager->SetColumnSpan(this->ModDescription, 2);
			this->ModDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModDescription->Location = System::Drawing::Point(877, 188);
			this->ModDescription->Name = L"ModDescription";
			this->ModDescription->Size = System::Drawing::Size(431, 533);
			this->ModDescription->TabIndex = 11;
			this->ModDescription->Text = L"Mod Description";
			// 
			// ModType
			// 
			this->ModType->AutoSize = true;
			this->ModType->Location = System::Drawing::Point(1095, 134);
			this->ModType->Name = L"ModType";
			this->ModType->Size = System::Drawing::Size(71, 17);
			this->ModType->TabIndex = 7;
			this->ModType->Text = L"Mod Type";
			// 
			// ModEnabled
			// 
			this->ModEnabled->AutoSize = true;
			this->ModEnabled->Location = System::Drawing::Point(1095, 117);
			this->ModEnabled->Name = L"ModEnabled";
			this->ModEnabled->Size = System::Drawing::Size(91, 17);
			this->ModEnabled->TabIndex = 9;
			this->ModEnabled->Text = L"Mod Enabled";
			// 
			// DoModsButton
			// 
			this->DoModsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DoModsButton->Location = System::Drawing::Point(3, 2);
			this->DoModsButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DoModsButton->Name = L"DoModsButton";
			this->DoModsButton->Size = System::Drawing::Size(75, 23);
			this->DoModsButton->TabIndex = 1;
			this->DoModsButton->Text = L"Launch";
			this->DoModsButton->UseVisualStyleBackColor = true;
			this->DoModsButton->Click += gcnew System::EventHandler(this, &MainForm::LaunchGame);
			// 
			// ModsList
			// 
			this->ModsList->AllowUserToAddRows = false;
			this->ModsList->AllowUserToDeleteRows = false;
			this->ModsList->AllowUserToResizeColumns = false;
			this->ModsList->AllowUserToResizeRows = false;
			this->ModsList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ModsList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->EnabledColumn,
					this->ModNameColumn, this->ModTypeColumn, this->ModInfoColumn
			});
			this->ModsList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ModsList->Location = System::Drawing::Point(3, 29);
			this->ModsList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->ModsList->Size = System::Drawing::Size(868, 690);
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
			// ModNameColumn
			// 
			this->ModNameColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ModNameColumn->HeaderText = L"Name";
			this->ModNameColumn->MinimumWidth = 6;
			this->ModNameColumn->Name = L"ModNameColumn";
			this->ModNameColumn->ReadOnly = true;
			// 
			// ModTypeColumn
			// 
			this->ModTypeColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->ModTypeColumn->HeaderText = L"Type";
			this->ModTypeColumn->MinimumWidth = 6;
			this->ModTypeColumn->Name = L"ModTypeColumn";
			this->ModTypeColumn->ReadOnly = true;
			this->ModTypeColumn->Width = 69;
			// 
			// ModInfoColumn
			// 
			this->ModInfoColumn->HeaderText = L"Mod";
			this->ModInfoColumn->MinimumWidth = 6;
			this->ModInfoColumn->Name = L"ModInfoColumn";
			this->ModInfoColumn->ReadOnly = true;
			this->ModInfoColumn->Visible = false;
			this->ModInfoColumn->Width = 125;
			// 
			// DownloadsList
			// 
			this->DownloadsList->AllowUserToAddRows = false;
			this->DownloadsList->AllowUserToDeleteRows = false;
			this->DownloadsList->AllowUserToResizeColumns = false;
			this->DownloadsList->AllowUserToResizeRows = false;
			this->DownloadsList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DownloadsList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->InstalledColumn,
					this->DownloadNameColumn, this->DownloadTypeColumn, this->DownloadInfoColumn
			});
			this->DownloadsList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadsList->Location = System::Drawing::Point(3, 27);
			this->DownloadsList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DownloadsList->MultiSelect = false;
			this->DownloadsList->Name = L"DownloadsList";
			this->DownloadsList->RowHeadersVisible = false;
			this->DownloadsList->RowHeadersWidth = 51;
			this->DownloadManager->SetRowSpan(this->DownloadsList, 10);
			this->DownloadsList->RowTemplate->Height = 24;
			this->DownloadsList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->DownloadsList->ShowCellErrors = false;
			this->DownloadsList->ShowEditingIcon = false;
			this->DownloadsList->ShowRowErrors = false;
			this->DownloadsList->Size = System::Drawing::Size(867, 692);
			this->DownloadsList->TabIndex = 3;
			this->DownloadsList->SelectionChanged += gcnew System::EventHandler(this, &MainForm::DownloadsList_SelectionChanged);
			// 
			// InstalledColumn
			// 
			this->InstalledColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->InstalledColumn->HeaderText = L"Installed";
			this->InstalledColumn->MinimumWidth = 6;
			this->InstalledColumn->Name = L"InstalledColumn";
			this->InstalledColumn->ReadOnly = true;
			this->InstalledColumn->Visible = false;
			this->InstalledColumn->Width = 125;
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
			// DownloadInfoColumn
			// 
			this->DownloadInfoColumn->HeaderText = L"Download";
			this->DownloadInfoColumn->MinimumWidth = 6;
			this->DownloadInfoColumn->Name = L"DownloadInfoColumn";
			this->DownloadInfoColumn->ReadOnly = true;
			this->DownloadInfoColumn->Visible = false;
			this->DownloadInfoColumn->Width = 125;
			// 
			// Tabs
			// 
			this->Tabs->Controls->Add(this->ManagerTab);
			this->Tabs->Controls->Add(this->DownloadTab);
			this->Tabs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Tabs->Location = System::Drawing::Point(0, 0);
			this->Tabs->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tabs->Name = L"Tabs";
			this->Tabs->SelectedIndex = 0;
			this->Tabs->Size = System::Drawing::Size(1319, 750);
			this->Tabs->TabIndex = 1;
			this->Tabs->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &MainForm::Tabs_Selected);
			// 
			// ManagerTab
			// 
			this->ManagerTab->Controls->Add(this->ModManager);
			this->ManagerTab->Location = System::Drawing::Point(4, 25);
			this->ManagerTab->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->DownloadTab->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DownloadTab->Name = L"DownloadTab";
			this->DownloadTab->Size = System::Drawing::Size(1311, 721);
			this->DownloadTab->TabIndex = 0;
			this->DownloadTab->Text = L"Download";
			this->DownloadTab->UseVisualStyleBackColor = true;
			// 
			// DownloadManager
			// 
			this->DownloadManager->ColumnCount = 3;
			this->DownloadManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				66.66336F)));
			this->DownloadManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66832F)));
			this->DownloadManager->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66832F)));
			this->DownloadManager->Controls->Add(this->DownloadDescription, 1, 9);
			this->DownloadManager->Controls->Add(label9, 1, 4);
			this->DownloadManager->Controls->Add(this->DownloadsList, 0, 1);
			this->DownloadManager->Controls->Add(label7, 1, 2);
			this->DownloadManager->Controls->Add(label8, 1, 3);
			this->DownloadManager->Controls->Add(label11, 1, 8);
			this->DownloadManager->Controls->Add(this->DownloadInstalled, 2, 3);
			this->DownloadManager->Controls->Add(this->DownloadType, 2, 4);
			this->DownloadManager->Controls->Add(label10, 1, 5);
			this->DownloadManager->Controls->Add(this->ShowInstalledCheck, 0, 0);
			this->DownloadManager->Controls->Add(tableLayoutPanel1, 1, 1);
			this->DownloadManager->Controls->Add(label5, 1, 6);
			this->DownloadManager->Controls->Add(this->DownloadUrl, 2, 10);
			this->DownloadManager->Controls->Add(this->DownloadAuthor, 2, 6);
			this->DownloadManager->Controls->Add(this->DownloadTags, 2, 7);
			this->DownloadManager->Controls->Add(label13, 1, 7);
			this->DownloadManager->Controls->Add(label12, 1, 10);
			this->DownloadManager->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadManager->Location = System::Drawing::Point(0, 0);
			this->DownloadManager->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DownloadManager->Name = L"DownloadManager";
			this->DownloadManager->RowCount = 11;
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 0)));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->DownloadManager->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->DownloadManager->Size = System::Drawing::Size(1311, 721);
			this->DownloadManager->TabIndex = 0;
			// 
			// DownloadDescription
			// 
			this->DownloadDescription->AutoSize = true;
			this->DownloadManager->SetColumnSpan(this->DownloadDescription, 2);
			this->DownloadDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadDescription->Location = System::Drawing::Point(876, 201);
			this->DownloadDescription->Name = L"DownloadDescription";
			this->DownloadDescription->Size = System::Drawing::Size(432, 503);
			this->DownloadDescription->TabIndex = 1;
			this->DownloadDescription->Text = L"Download Description";
			// 
			// DownloadInstalled
			// 
			this->DownloadInstalled->AutoSize = true;
			this->DownloadInstalled->Location = System::Drawing::Point(1094, 113);
			this->DownloadInstalled->Name = L"DownloadInstalled";
			this->DownloadInstalled->Size = System::Drawing::Size(126, 1);
			this->DownloadInstalled->TabIndex = 17;
			this->DownloadInstalled->Text = L"Download Installed";
			// 
			// DownloadType
			// 
			this->DownloadType->AutoSize = true;
			this->DownloadType->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadType->Location = System::Drawing::Point(1094, 113);
			this->DownloadType->Name = L"DownloadType";
			this->DownloadType->Size = System::Drawing::Size(214, 17);
			this->DownloadType->TabIndex = 18;
			this->DownloadType->Text = L"Download Type";
			// 
			// ShowInstalledCheck
			// 
			this->ShowInstalledCheck->AutoSize = true;
			this->ShowInstalledCheck->Checked = true;
			this->ShowInstalledCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ShowInstalledCheck->Location = System::Drawing::Point(3, 2);
			this->ShowInstalledCheck->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ShowInstalledCheck->Name = L"ShowInstalledCheck";
			this->ShowInstalledCheck->Size = System::Drawing::Size(155, 21);
			this->ShowInstalledCheck->TabIndex = 4;
			this->ShowInstalledCheck->Text = L"Don\'t show installed";
			this->ShowInstalledCheck->UseVisualStyleBackColor = true;
			// 
			// DownloadUrl
			// 
			this->DownloadUrl->AutoSize = true;
			this->DownloadUrl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadUrl->Location = System::Drawing::Point(1094, 704);
			this->DownloadUrl->Name = L"DownloadUrl";
			this->DownloadUrl->Size = System::Drawing::Size(214, 17);
			this->DownloadUrl->TabIndex = 25;
			this->DownloadUrl->TabStop = true;
			this->DownloadUrl->Text = L"https://www.Download Link.com";
			// 
			// DownloadAuthor
			// 
			this->DownloadAuthor->AutoSize = true;
			this->DownloadAuthor->Location = System::Drawing::Point(1094, 150);
			this->DownloadAuthor->Name = L"DownloadAuthor";
			this->DownloadAuthor->Size = System::Drawing::Size(116, 17);
			this->DownloadAuthor->TabIndex = 26;
			this->DownloadAuthor->Text = L"Download Author";
			// 
			// DownloadTags
			// 
			this->DownloadTags->AutoSize = true;
			this->DownloadTags->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DownloadTags->Location = System::Drawing::Point(1094, 167);
			this->DownloadTags->Name = L"DownloadTags";
			this->DownloadTags->Size = System::Drawing::Size(214, 17);
			this->DownloadTags->TabIndex = 27;
			this->DownloadTags->Text = L"Download Tags";
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
			this->Controls->Add(this->Tabs);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MainForm";
			this->Text = L"Inferno Mod Manager";
			tableLayoutPanel1->ResumeLayout(false);
			tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadImage))->EndInit();
			tableLayoutPanel2->ResumeLayout(false);
			tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModImage))->EndInit();
			this->ModManager->ResumeLayout(false);
			this->ModManager->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModsList))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DownloadsList))->EndInit();
			this->Tabs->ResumeLayout(false);
			this->ManagerTab->ResumeLayout(false);
			this->DownloadTab->ResumeLayout(false);
			this->DownloadManager->ResumeLayout(false);
			this->DownloadManager->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::String^ btd6Install = nullptr;

		private: System::Void FolderUpdate(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
			GetInstalled();
			PopulateModsList();
		}
		private: System::Void FolderUpdate(System::Object^ sender, System::IO::RenamedEventArgs^ e) {
			FolderUpdate(sender, (System::IO::FileSystemEventArgs^)e);
		}

		private: System::Void ModsList_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->ColumnIndex == EnabledColumn->Index) {
				ModsList->EndEdit(); //makes changes actually register
				if (e->RowIndex > -1) {
					InfernoModManager::Mod^ mod = (InfernoModManager::Mod^)ModsList->Rows[e->RowIndex]->Cells[ModInfoColumn->Index]->Value;
					mod->Status = !mod->Status;
					System::String^ newLoc = (mod->Status ? GetInstalledDir() : GetDisabledDir()) +
						"\\" + System::IO::Path::GetFileName(mod->Location);
					System::IO::File::Move(mod->Location, newLoc);
					mod->Location = newLoc;
					UpdateModStats(mod);
				}
			}
		}

		private: System::Void CheckBTD6Open(System::Object^ sender, System::EventArgs^ e) {
			CheckBTD6Open();
		}

		private: System::Void ModsList_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
			if(ModsList->SelectedRows->Count > 0)
				UpdateModStats(ModsList->SelectedRows[0]->Index);
		}

		private: System::Void DownloadsList_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
			if (DownloadsList->SelectedRows->Count > 0)
				UpdateDownloadStats(DownloadsList->SelectedRows[0]->Index);
		}

		private: System::Void LaunchGame(System::Object^ sender, System::EventArgs^ e)
		{
			System::Diagnostics::ProcessStartInfo^ psi = gcnew System::Diagnostics::ProcessStartInfo("steam://rungameid/960090");
			System::Diagnostics::Process::Start(psi);
			System::Threading::Thread::Sleep(5);
		}

		private: System::Void Tabs_Selected(System::Object^ sender, System::Windows::Forms::TabControlEventArgs^ e) {
			if(e->TabPageIndex == 1) {
				GetAvailable();
				PopulateDownloadsList();
			}
		}

		private: System::Void Image_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			e->Graphics->Clear(System::Drawing::SystemColors::Window);
			e->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
			e->Graphics->DrawImage(((System::Windows::Forms::PictureBox^)sender)->Image, e->ClipRectangle);
		}

		private: System::Void DownloadMod_Click(System::Object^ sender, System::EventArgs^ e) {
			InfernoModManager::Mod^ mod = (InfernoModManager::Mod^)DownloadsList->SelectedRows[0]->Cells[DownloadInfoColumn->Index]->Value;
			InfernoModManager::WebDownloader::downloadFile(mod->Location, GetInstalledDir() + mod->Name + mod->Type);
			GetInstalled();
			PopulateModsList();
		}

		private: System::Void RemoveMod_Click(System::Object^ sender, System::EventArgs^ e) {
			InfernoModManager::Mod^ mod = (InfernoModManager::Mod^)ModsList->SelectedRows[0]->Cells[ModInfoColumn->Index]->Value;
			System::IO::File::Delete(mod->Location);
			GetInstalled();
			PopulateModsList();
		}

		private: System::Void GetFiles(array<System::String^>^ files, bool enabled) {
			for each (System::String ^ file in files)
				if (InfernoModManager::Games::IsCompatibleType(file))
					InfernoModManager::Mod::Installed->Add(gcnew InfernoModManager::Mod(NameOf(file), "noone", "1.0", "other",
						System::IO::Path::GetExtension(file), "a mod", file, "", enabled));
		}

		private: System::Void GetInstalled() {
			InfernoModManager::Mod::Installed->Clear();
			GetFiles(System::IO::Directory::GetFiles(GetInstalledDir()), true);
			GetFiles(System::IO::Directory::GetFiles(GetDisabledDir()), false);
		}

		private: System::Void GetAvailable() {
			InfernoModManager::Mod::Available->Clear();
			std::vector<const char*> allData = InfernoModManager::WebDownloader::getAllData(true);
			for (int i = 0; i < allData.size(); i++) {
				array<System::String^>^ data = msclr::interop::marshal_as<System::String^>(allData[i])->Split('<');
				if (data->Length > 6) {
					bool isInstalled = false;
					for (int i = 0; i < InfernoModManager::Mod::Installed->Count; i++) {
						if (InfernoModManager::Mod::Installed[i]->Name->Equals(data[1])) {
							isInstalled = true;
							break;
						}
					}
					InfernoModManager::Mod::Available->Add(gcnew InfernoModManager::Mod(data[1], data[2], "1.0", data[4], data[5],
						data[3], data[0], data[6], isInstalled));
				}
			}
		}

		private: System::Void PopulateModsList() {
			ModsList->Rows->Clear();
			for each (InfernoModManager::Mod^ mod in InfernoModManager::Mod::Installed)
				ModsList->Rows->Add(mod->Status, mod->Name, mod->Type, mod);
			ModsList->Sort(ModNameColumn, System::ComponentModel::ListSortDirection::Ascending);
			UpdateModStats(0);
		}

		private: System::Void PopulateDownloadsList() {
			DownloadsList->Rows->Clear();
			for each (InfernoModManager::Mod ^ mod in InfernoModManager::Mod::Available)
				DownloadsList->Rows->Add(mod->Status, mod->Name, mod->Type, mod);
			DownloadsList->Sort(DownloadNameColumn, System::ComponentModel::ListSortDirection::Ascending);
			UpdateDownloadStats(0);
		}

		private: System::String^ NameOf(System::String^ file) {
			System::String^ name = System::IO::Path::GetFileName(file);
			int end = name->LastIndexOf('.');
			if(end > 0)
				name = name->Substring(0, end);
			return name;
		}

		private: System::Void CheckBTD6Open() {
			if (InfernoModManager::Injection::GetTargetThreadIDFromProcName("BloonsTD6") != -1)
				DoModsButton->Text = "Inject";
			else
				DoModsButton->Text = "Launch";
		}

		private: System::Void UpdateModStats(InfernoModManager::Mod^ mod) {
			ModName->Text = mod->Name;
			ModEnabled->Text = (gcnew System::Boolean(mod->Status))->ToString();
			ModType->Text = mod->Type;
			ModDescription->Text = mod->Description;
		}

		private: System::Void UpdateModStats(int index) {
			if (index > -1 && index < ModsList->Rows->Count)
				UpdateModStats((InfernoModManager::Mod^)ModsList->Rows[index]->Cells[ModInfoColumn->Index]->Value);
		}

		private: System::Void UpdateDownloadStats(InfernoModManager::Mod^ mod) {
			try {
				System::IO::MemoryStream^ img = gcnew System::IO::MemoryStream(System::Convert::FromBase64String(mod->Base64Png));
				DownloadImage->Image = System::Drawing::Image::FromStream(img);
				img->Close();
				delete img;
			} catch (System::Exception^ e) {}
			DownloadName->Text = mod->Name;
			DownloadInstalled->Text = (gcnew System::Boolean(mod->Status))->ToString();
			DownloadType->Text = mod->Type;
			DownloadAuthor->Text = mod->Author;
			DownloadTags->Text = mod->Tags;
			DownloadDescription->Text = mod->Description;
			DownloadUrl->Text = mod->Location;
		}

		private: System::Void UpdateDownloadStats(int index) {
			if (index > -1 && index < DownloadsList->Rows->Count)
				UpdateDownloadStats((InfernoModManager::Mod^)DownloadsList->Rows[index]->Cells[DownloadInfoColumn->Index]->Value);
		}

		private: System::String^ GetInstalledDir() {
			return btd6Install + "\\Mods";
		}

		private: System::String^ GetDisabledDir() {
			return btd6Install + "\\Mods\\Disabled";
		}
};
}
