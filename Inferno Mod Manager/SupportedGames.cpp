#include <map>
#include <msclr\marshal.h>

#pragma once
namespace InfernoModManager
{

	class Games
	{
		public:
			static std::map<long long, const char*> GameInfo;

			static bool IsGameInstalled(const __int64 id)
			{
				System::Object^ installed = Microsoft::Win32::Registry::GetValue(Microsoft::Win32::Registry::CurrentUser + "\\Software\\Valve\\Steam\\Apps\\" + id, "Installed", nullptr);

				if (!installed)
					return 0;
				return (int)installed == 1;
			}

			static System::String^ GetSteamDir()
			{
				return (System::String^)Microsoft::Win32::Registry::GetValue(Microsoft::Win32::Registry::CurrentUser + "\\Software\\Valve\\Steam", "SteamPath", nullptr);
			}

			static System::String^ GetGameDir(const __int64 id)
			{
				System::String^ steamDir = GetSteamDir();
				if (System::String::IsNullOrEmpty(steamDir))
					throw gcnew System::Exception("Steam Directory invalid!");

				if (!IsGameInstalled(id))
					throw gcnew System::Exception("You don't have that game installed!");

				System::Collections::Generic::List<System::String^>^ allPossible = gcnew System::Collections::Generic::List<System::String^>();
				System::String^ config = steamDir + "\\steamapps\\libraryfolders.vdf";
				allPossible->Add(config);
				array<System::String^>^ configFile = System::IO::File::ReadAllLines(config);
				for each (System::String^ configPart in configFile)
				{
					System::Text::RegularExpressions::Regex^ reg = gcnew System::Text::RegularExpressions::Regex("\".?\"");
					for (int i = 0; i < reg->Matches(configPart)->Count; ++i)
					{
						int tmp;

						if (i == 1)
							allPossible->Add(reg->Matches(configPart)[i]->Value->ToString());
						if (i == 0)
							if (!int::TryParse(reg->Matches(configPart)[i]->Value->ToString(), tmp))
								break;
					}
				}

				System::String^ gameName;

				for each (std::pair<long long, const char*> pair in GameInfo)
				{
					if (pair.first == id)
					{
						gameName = msclr::interop::marshal_as<System::String^>(pair.second);
					}
				}

				for each (System::String^ possible in allPossible)
				{
					System::String^ gameFolder = possible + "\\steamapps\\common\\" + gameName;
					if (System::IO::Directory::Exists(gameFolder))
					{
						return gameFolder;
					}
				}
				return "ERROR CANT FIND GAME";
			}
	};
}
