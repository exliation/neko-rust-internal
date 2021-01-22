#pragma once
#include <cstdlib>

int _purecall(void);

namespace std
{

	[[noreturn]] inline void __cdecl _Xbad_function_call() { __ud2(); }
	[[noreturn]] inline void __cdecl _Xbad_alloc() { __ud2(); }
	[[noreturn]] inline void __cdecl _Xlength_error(char const*) { __ud2(); }
	[[noreturn]] inline void __cdecl _Xout_of_range(char const*) { __ud2(); }
	[[noreturn]] inline void __cdecl  __security_check_cookie() { __ud2(); }
} // namespace std

#ifndef _DEBUG
extern "C" void __chkstk() {} // Disables stack allocation size limits.
extern "C" void __CxxFrameHandler4() { __ud2(); }
extern "C" void __std_terminate() { __ud2(); }
extern "C" void _fltused() { __ud2(); }
#endif

#define _Xlength_error(x) __ud2()
#define ABS(N) ((N<0)?(-N):(N))

unsigned short lfsr = 0xACE1u;
unsigned int bit = 0;

unsigned my_rand()
{
	if (!lfsr) {
		lfsr = 0xACE1u; bit = 0;
	}
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}

float my_floor(float x)
{
	if (x == 0.0)
		return 0;

	union {
		float input;
		int   output;
	} data;

	data.input = x;

	int exp = data.output & (255 << 23);
	exp = exp >> 23;

	int man = data.output & ((1 << 23) - 1);

	int pow = exp - 127;
	int mulFactor = 1;

	int i = ABS(pow);
	while (i--)
		mulFactor *= 2;

	unsigned long long denominator = 1 << 23;
	unsigned long long numerator = man + denominator;

	bool negative = (data.output >> 31) != 0;

	if (pow < 0)
		denominator *= mulFactor;
	else
		numerator *= mulFactor;

	float res = 0.0;
	while (numerator >= denominator) {
		res++;
		numerator -= denominator;
	}

	if (negative) {
		res = -res;
		if (numerator != 0)
			res -= 1;
	}

	return res;
}

float my_fmod(float a, float b) { return (a - b * my_floor(a / b)); }

bool m_wcsicmp(wchar_t* a, const wchar_t* b) {
	if (!a)
		return false;
	int ret = 0;
	wchar_t* p1 = (wchar_t*)a;
	wchar_t* p2 = (wchar_t*)b;
	while (!(ret = *p1 - *p2) && *p2)
		++p1, ++p2;

	return ret == 0;
}

char* m_strstr(char* input, const char* find)
{
	do {
		const char* p, * q;
		for (p = input, q = find; *q != '\0' && *p == *q; p++, q++) {}
		if (*q == '\0') {
			return input;
		}
	} while (*(input++) != '\0');
	return 0;
}

bool m_strcmp(char* a, char* b) {
	if ((uintptr_t)a == 0x00000000ffffffff || (uintptr_t)b == 0x00000000ffffffff)
		return false;
	if ((uintptr_t)a == 0x000000000000007d || (uintptr_t)b == 0x000000000000007d)
		return false;

	if (!a || !b) return !a && !b;

	int ret = 0;
	unsigned char* p1 = (unsigned char*)a;
	unsigned char* p2 = (unsigned char*)b;
	while (!(ret = *p1 - *p2) && *p2)
		++p1, ++p2;

	return ret == 0;
}

unsigned int m_wcslen(wchar_t* str)
{
	int cnt = 0;
	if (!str)
		return 0;
	for (; *str != '\0'; ++str)
		++cnt;
	return cnt;
}