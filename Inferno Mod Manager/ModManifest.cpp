#include "ModManifest.h"
#include "Mod.h"

using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;
using namespace Newtonsoft::Json;

namespace InfernoModManager
{
	void ModManifest::Add(Mod^ m)
	{
		if (!File::Exists("mods.json")) {
			FileStream^ fs = File::Create("mods.json");
			fs->Close();
		}

		List<Mod^>^ mods = nullptr;
		try {
			mods = JsonConvert::DeserializeObject<List<Mod^>^>(File::ReadAllText("mods.json"));
		} catch (System::Exception^) {}

		if (!mods)
			mods = gcnew List<Mod^>;

		mods->Add(m);
		File::WriteAllText("mods.json", JsonConvert::SerializeObject(mods, Formatting::Indented));
	}

	Mod^ ModManifest::GetModFromName(System::String^ s)
	{
		if (!File::Exists("mods.json"))
			return nullptr;

		List<Mod^>^ mods = GetMods();

		if (mods)
		{
			for each (Mod^ m in mods)
			{
				if (m->Name->Equals(s)) {
					return m;
				}
			}
		}

		return nullptr;
	}

	List<Mod^>^ ModManifest::GetMods()
	{
		if (!File::Exists("mods.json"))
			return nullptr;

		List<Mod^>^ mods = nullptr;
		try {
			mods = JsonConvert::DeserializeObject<List<Mod^>^>(File::ReadAllText("mods.json"));
		}
		catch (System::Exception^) {}
		return mods;
	}

	void ModManifest::Sub(Mod^ m)
	{
		if (!File::Exists("mods.json"))
			return;

		List<Mod^>^ mods = GetMods();

		if (mods)
		{
			mods->Remove(m);
			Mod^ tried = GetModFromName(m->Name);
			if (tried) {
				List<Mod^>^ newMods = gcnew List<Mod^>;

				for each (Mod^ m in mods)
				{
					if (!m->Name->Equals(tried->Name))
					{
						newMods->Add(m);
					}
				}
				File::WriteAllText("mods.json", JsonConvert::SerializeObject(newMods, Formatting::Indented));
			}
		}
	}
}
