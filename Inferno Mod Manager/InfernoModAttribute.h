#include "Tags.h"

#pragma once
ref class InfernoModAttribute : public System::Attribute
{
	public:
		System::String ^name, ^description, ^tags, ^base64png;

		InfernoModAttribute(System::String^ Name, System::String^ Description, System::String^ Tags, System::String^ Base64PNG) : name(Name), description(Description), tags(Tags), base64png(Base64PNG){}

		~InfernoModAttribute()
		{
			delete name, description, tags, base64png;
		}
};