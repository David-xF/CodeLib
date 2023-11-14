#pragma once

#include <code/code.h>

namespace mc {
    class CInput {
    public:
        enum KeyboardMode : int {
            FULL = 0,
            NUMPAD = 1,
            UTF8 = 2,
            NNID = 3
        };

        static inline CInput* GetInput() {
            return code::Mem(0x10A90E6C - 0x502200).as<CInput*>();
        }

        void GetText(const wchar_t* buffer, int32_t length) {
            code::Func<void, 0x0340A480, CInput*, const wchar_t*, uint32_t>()(this, buffer, length);
        }

        bool RequestKeyboard(const wchar_t* nothing, const wchar_t* default_text, uint32_t unk_Ui0, uint32_t max_size, int(*call_back)(void *, bool), void* arg1, KeyboardMode eKeyboardMode) {
            return code::Func<bool, 0x0340A33C, CInput*, const wchar_t*, const wchar_t*, uint32_t, uint32_t, int(*)(void*, bool), void*, KeyboardMode>()(this, nothing, default_text, unk_Ui0, max_size, call_back, arg1, eKeyboardMode);
        }

    };
}