#pragma once

#include <code/code.h>

#include "../wstring.h"

namespace mc {
    class TextureAtlas {
    public:
        void addIcon(uint32_t x, uint32_t y, mstd::wstring iconName)  {
            code::Func<void, 0x03366AD4, TextureAtlas*, uint32_t, uint32_t, uint32_t, mstd::wstring>()(this, 0, y, x, iconName);
        }
    };
}