#include "Tags.h"

#pragma once
ref class InfernoModAttribute : public System::Attribute
{
	public:
		System::String ^name, ^description, ^tags, ^base64png, ^version;

		InfernoModAttribute(System::String^ Name, System::String^ Description, System::String^ Tags, System::String^ Base64PNG, System::String^ Version) : name(Name), description(Description), tags(Tags), base64png(Base64PNG), version(Version){}

		~InfernoModAttribute()
		{
			delete name, description, tags, base64png, version;
		}
};