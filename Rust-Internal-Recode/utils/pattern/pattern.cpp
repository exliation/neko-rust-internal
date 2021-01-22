#include <stdlib.h>
#include <stdarg.h>
#include <algorithm>
#include <cstdint>
#include <intrin.h>

#include "pattern.hpp"
#include "../../memory/lazy_importer.hpp"

#define in_range(x,a,b) (x>=a&&x<=b) 
#define get_bits(x) (in_range((x&(~0x20)),'A','F')?((x&(~0x20))-'A'+0xa):(in_range(x,'0','9')?x-'0':0))
#define get_byte(x) (get_bits(x[0])<<4|get_bits(x[1]))

uintptr_t rb::pattern::find(uintptr_t range_start, uintptr_t range_end, const char* pattern) {
	const char* pattern_bytes = pattern;

	uintptr_t first_match = 0;

	for (uintptr_t cur_byte = range_start; cur_byte < range_end; cur_byte++) {
		if (!*pattern_bytes)
			return first_match;

		if (*(uint8_t*)pattern_bytes == '\?' || *(uint8_t*)cur_byte == static_cast<uint8_t>(get_byte(pattern_bytes))) {
			if (!first_match)
				first_match = cur_byte;

			if (!pattern_bytes[2])
				return first_match;

			if (*(uint16_t*)pattern_bytes == '\?\?' || *(uint8_t*)pattern_bytes != '\?')
				pattern_bytes += 3;
			else
				pattern_bytes += 2;
		}
		else {
			pattern_bytes = pattern;
			first_match = 0;
		}
	}

	return 0;
}

uintptr_t rb::pattern::find(const char* mod, const char* pattern) {
	const char* pattern_bytes = pattern;

	uintptr_t range_start = (uintptr_t)LI_MODULE_SAFE_(mod);

	uintptr_t range_end = range_start + LI_MODULESIZE_SAFE_(mod);

	return find(range_start, range_end, pattern);
}

uintptr_t rb::pattern::find_rel(const char* mod, const char* pattern, ptrdiff_t position, ptrdiff_t jmp_size, ptrdiff_t instruction_size) {
	auto result = find(mod, pattern);

	if (!result) return 0;

	result += position;

	auto rel_addr = *reinterpret_cast<int32_t*>(result + jmp_size);
	auto abs_addr = result + instruction_size + rel_addr;

	return abs_addr;
}

uint32_t rb::pattern::find_offset32(const char* mod, const char* pattern, ptrdiff_t position) {
	auto result = find(mod, pattern);

	if (!result) return 0;

	result += position;

	auto mod_base = LI_MODULE_SAFE_(mod);

	return result - mod_base;
}

uint32_t rb::pattern::find_offset32_rel(const char* mod, const char* pattern, ptrdiff_t position, ptrdiff_t jmp_size, ptrdiff_t instruction_size) {
	auto result = find_rel(mod, pattern, position, jmp_size, instruction_size);

	if (!result) return 0;

	auto mod_base = LI_MODULE_SAFE_(mod);

	return result - mod_base;
}