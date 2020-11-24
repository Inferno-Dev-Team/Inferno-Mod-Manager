#ifndef _PROTECTHEADER_H
#define _PROTECTHEADER_H
#include "Mod.h"
#pragma once
namespace InfernoModManager {
	ref class ModManifest
	{
		public:
			static void Add(Mod^ m);
			static Mod^ GetModFromName(System::String^ s);
			static void Sub(Mod^ m);
	};
}
#endif
