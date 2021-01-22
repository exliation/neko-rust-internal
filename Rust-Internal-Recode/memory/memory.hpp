#pragma once
#include "lazy_importer.hpp"

#include "../utils/xorstr.hpp"

#include "../utils/pattern/pattern.hpp"

namespace mem {
	uintptr_t game_assembly_base = LI_MODULE_SAFE_(_("GameAssembly.dll"));
	uintptr_t unity_player_base = LI_MODULE_SAFE_(_("UnityPlayer.dll"));
	template<typename t>
	t read(uintptr_t addr) {
		if (addr < 0xffffff)
			return t();
		if (addr > 0x7fffffff0000)
			return t();

		return *reinterpret_cast<t*>(addr);
	}

	template<typename t>
	bool write(uintptr_t addr, t buffer) {
		*reinterpret_cast<t*>(addr) = buffer;
		return true;
	}
	
	uintptr_t hook_virtual_function(const char* classname, const char* function_to_hook, void* target, const char* name_space);
}