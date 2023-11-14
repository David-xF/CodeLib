#pragma once

#include <code/code.h>

#include "../client/resource/wstring.h"

#define FONT_CHAR_HEIGHT 8

namespace mc {
    class Font {
    public:
		int width(const mstd::wstring& wstr) {
			return code::Func<uint32_t, 0x30E919C, Font*, const mstd::wstring&>()(this, wstr);
		}

		void drawShadow(const mstd::wstring& wstr, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
			code::Func<void, 0x3126B88, Font*, const mstd::wstring&, uint32_t, uint32_t, uint32_t>()(this, wstr, arg1, arg2, arg3);
		}

		void draw(const mstd::wstring& wstr, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
			code::Func<void, 0x030E9A10, Font*, const mstd::wstring&, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>()(this, wstr, arg1, arg2, arg3, 0, 1);
		}
    };
}