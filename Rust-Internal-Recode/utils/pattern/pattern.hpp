#pragma once

namespace rb {
	namespace pattern
	{
		uintptr_t find(uintptr_t range_start, uintptr_t range_end, const char* pattern);
		uintptr_t find(const char* mod, const char* pattern);

		uintptr_t find_rel(const char* mod, const char* pattern, ptrdiff_t position = 0, ptrdiff_t jmp_size = 3, ptrdiff_t instruction_size = 7);
		uint32_t find_offset32(const char* mod, const char* pattern, ptrdiff_t position = 0);
		uint32_t find_offset32_rel(const char* mod, const char* pattern, ptrdiff_t position = 0, ptrdiff_t jmp_size = 3, ptrdiff_t instruction_size = 7);
	}
}