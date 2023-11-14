#pragma once

#include <code/code.h>

#define GET_LR(valName)                       \
    uint32_t valName;                         \
    asm volatile("mflr %0" : "=r" (valName)); 


wchar_t* getEffectName(int id) {
    const wchar_t* names[] = {
        L"NULL", L"Speed", L"Slowness", L"Haste", L"Mining Fatigue", L"Strength", L"Instant Health", L"Instant Damage", L"Jump Boost", 
        L"Nausea", L"Regeneration", L"Resistance", L"Fire Resistance", L"Water Breathing", L"Invisibility", L"Blindness", L"Night Vision",
        L"Hunger", L"Weakness", L"Poison", L"Wither", L"Health Boost", L"Absorption", L"Saturation", L"Glowing", L"Levitation", L"Luck",
        L"Bad Luck"
    };

    int size = sizeof(names) / sizeof(names[0]);
    if (id >= size) return (wchar_t*) L"NULL";
    return (wchar_t*) names[id % size];
}

void mc_wcscpy(const wchar_t* out, const wchar_t* in) {
	code::Func<void, 0x0382C734, const wchar_t*, const wchar_t*>()(out, in);
}

int mc_wcslen(const wchar_t* in) {
	return code::Func<int, 0x0382c718, const wchar_t*>()(in);
}

template<typename... Args>
static void mc_swprintf(const wchar_t* outputPointer, uint32_t size, const wchar_t* __format, Args... args) {
	code::Func<void, 0x382C8C0, const wchar_t*, uint32_t, const wchar_t*, Args...>()(outputPointer, size, __format, args...);
}

static float degToRad(float deg) {
    return (deg * M_PI / 180.0f);
}

static float radToDeg(float rad) {
    return (rad * 180.0f / M_PI);
}

char* wcharToChar(const wchar_t* str, int length = 0) {
	bool found = length != 0;
	while (!found) {
		if (str[length++] == 0x0) {
			found = true;
			length--;
		}
		if (length >= 250) return (char*) "";
	}

	char* newStr = _new<char>(length + 1);
	for (int i = 0; i < length; i++) {
		newStr[i] = str[i];
	}

	newStr[length] = 0;
	return newStr;
}

wchar_t* charToWChar(const char* str, int length = 0) {
	bool found = length != 0;
	while (!found) {
		if (str[length++] == 0x0) {
			found = true;
			length--;
		}
		if (length >= 250) return (wchar_t*) L"";
	}

	wchar_t* newStr = _new<wchar_t>(length + 1);
	for (int i = 0; i < length; i++) {
		newStr[i] = str[i];
	}

	newStr[length] = 0;
	return newStr;
}

// https://stackoverflow.com/questions/2249110/how-do-i-make-a-portable-isnan-isinf-function
int isinf(double x) {
    union { uint64_t u; double f; } ieee754;
    ieee754.f = x;
    return ((unsigned) (ieee754.u >> 32) & 0x7fffffff) == 0x7ff00000 &&
           ((unsigned)  ieee754.u == 0 );
}

// https://stackoverflow.com/questions/2249110/how-do-i-make-a-portable-isnan-isinf-function
int isnan(double x) {
    union { uint64_t u; double f; } ieee754;
    ieee754.f = x;
    return ((unsigned) (ieee754.u >> 32) & 0x7fffffff) +
           ((unsigned)  ieee754.u !=  0) > 0x7ff00000;
}

char* toCStr(float input, int decimalPlaces = 5) {
	uint32_t a0 = *(uint32_t*) &input;
    bool isNegative = (a0 & 0x80000000) == 0x80000000;
    if (isNegative) a0 -= 0x80000000;
    float a1 = *(float*) &a0;
	uint32_t multip = 1;
	for (int i = 0; i < decimalPlaces; i++) multip *= 10;
    uint32_t a = static_cast<uint32_t>(a1 * mc::toFloat(multip));
    uint32_t a_dec = a % multip;
    a = (a - a_dec) / multip;
    wchar_t strTemp[0x20];
    if (isnan(input)) {
        mc_swprintf(strTemp, 0x20, L"NaN");
	} else if (isinf(input)) {
		mc_swprintf(strTemp, 0x20, L"Inf"); 
	} else if (isNegative) {
		wchar_t strTemp2[0x20];
		mc_swprintf(strTemp2, 0x20, L"-%d.%s0%dd", a, "%", decimalPlaces);
        mc_swprintf(strTemp, 0x20, strTemp2, a_dec);
    } else {
		wchar_t strTemp2[0x20];
		mc_swprintf(strTemp2, 0x20, L"%d.%s0%dd", a, "%", decimalPlaces);
        mc_swprintf(strTemp, 0x20, strTemp2, a_dec);
    }
    return wcharToChar(strTemp, 0x20);
}