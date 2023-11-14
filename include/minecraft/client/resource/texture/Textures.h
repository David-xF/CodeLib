#pragma once

#include <code/code.h>

#include "../wstring.h"

namespace mc {
    class Textures {
    public:
        void loadTexture(struct BufferedImage* img, int id)  {
            code::Func<void, 0x0338f694, Textures*, struct BufferedImage*, int>()(this, img, id);
        }

        void bind(int id) {
            code::Func<void, 0x0338ee78, Textures*, int>()(this, id);
        }

        uint32_t loadMemTexture(const mstd::wstring& str, int unk) {
            return code::Func<uint32_t, 0x03391f7c, Textures*, const mstd::wstring&, int>()(this, str, unk);
        } 

        void reloadall() {
            code::Func<void, 0x03392de0, Textures*>()(this);
        }

        void releaseTexture(int id) {
            code::Func<void, 0x03390cd4, Textures*, int>()(this, id);
        }
    };
}