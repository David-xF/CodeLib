#pragma once

#include <code/code.h>

namespace mc {
    class UIString {
    public:
        UIString(const wchar_t* str) {
            code::Func<void, 0x02f47938, UIString*, const wchar_t*>()(this, str);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
    };
}