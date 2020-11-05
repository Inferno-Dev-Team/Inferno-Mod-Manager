#pragma once
namespace InfernoModManager {
	ref class Mod {
		public:
			System::String^ name;
			System::String^ author;
			System::String^ version;
			System::String^ tags;
			System::String^ description;
			System::String^ location;
			System::String^ base64png;
			System::Boolean^ status;
			Mod(array<System::Object^>^ data) : name((System::String^)data[0]), author((System::String^)data[1]), 
				version((System::String^)data[2]), tags((System::String^)data[3]), description((System::String^)data[4]),
				location((System::String^)data[5]), base64png((System::String^)data[6]), status((System::Boolean^)data[7]) { }
			~Mod() {
				delete name, author, version, tags, description, location, base64png, status;
			}
	};
}
