#pragma once
namespace InfernoModManager {
	ref class Mod sealed {
		private:
			System::String^ name;
			System::String^ author;
			System::String^ version;
			System::String^ tags;
			System::String^ type;
			System::String^ description;
			System::String^ location;
			System::String^ base64png;
			System::Boolean^ status;

		public:
			static System::Collections::Generic::List<Mod^>^ Installed = gcnew System::Collections::Generic::List<Mod^>();
			static System::Collections::Generic::List<Mod^>^ Available = gcnew System::Collections::Generic::List<Mod^>();

			property System::String^ Name { System::String^ get() { return name; } }
			property System::String^ Author { System::String^ get() { return author; } }
			property System::String^ Version { System::String^ get() { return version; } }
			property System::String^ Tags { System::String^ get() { return tags; } }
			property System::String^ Type { System::String^ get() { return type; } }
			property System::String^ Description { System::String^ get() { return description; } }
			property System::String^ Location { System::String^ get() { return location; } }
			property System::String^ Base64png { System::String^ get() { return base64png; } }
			property System::Boolean^ Status { System::Boolean^ get() { return status; } }

			Mod(System::String^ name, System::String^ author, System::String^ version, System::String^ tags, System::String^ type,
				System::String^ description, System::String^ location, System::String^ base64png, System::Boolean^ status) :
				name(name), author(author), version(version), tags(tags), type(type), description(description), location(location),
				base64png(base64png), status(status) { }
			~Mod() {
				delete name, author, version, tags, description, location, base64png, status;
			}
	};
}