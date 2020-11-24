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
			System::String^ pngLoc;
			bool status;

		public:
			static System::Collections::Generic::List<Mod^>^ Installed = gcnew System::Collections::Generic::List<Mod^>();
			static System::Collections::Generic::List<Mod^>^ Available = gcnew System::Collections::Generic::List<Mod^>();

			property System::String^ Name { System::String^ get() { return name; } }
			property System::String^ Author { System::String^ get() { return author; } }
			property System::String^ Version { System::String^ get() { return version; } }
			property System::String^ Tags { System::String^ get() { return tags; } }
			property System::String^ Type { System::String^ get() { return type; } }
			property System::String^ Description { System::String^ get() { return description; } }
			property System::String^ Location {
				System::String^ get() { return location; }
				System::Void set(System::String^ value) { location = value; }
			}
			property System::String^ PNGLoc { System::String^ get() { return pngLoc; } }
			property bool Status {
				bool get() { return status; }
				System::Void set(bool value) { status = value; }
			}

			Mod(System::String^ name, System::String^ author, System::String^ version, System::String^ tags, System::String^ type,
				System::String^ description, System::String^ location, System::String^ pngLoc, bool status) :
				name(name), author(author), version(version), tags(tags), type(type), description(description), location(location),
				pngLoc(pngLoc), status(status) {
				// Makes sure that the base64png is the correct length
				/*int off = this->base64png->Length % 4;
				if (off != 0) {
					if (this->base64png->EndsWith(gcnew System::String('=', off)))
						this->base64png = this->base64png->Substring(0, this->base64png->Length - off);
					else
						this->base64png += gcnew System::String('=', 4 - off);
				}*/
			}
			~Mod() {
				delete name, author, version, tags, description, location, pngLoc, status;
			}
	};
}