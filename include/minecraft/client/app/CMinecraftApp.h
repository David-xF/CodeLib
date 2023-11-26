#pragma once

#include "../resource/wstring.h"

namespace mc {
    class CMinecraftApp {
    public:
        void AddMemoryTextureFile(const mstd::wstring& name, uint8_t* data, uint32_t size) {
            code::Func<void, 0x02F5DF50, CMinecraftApp*, const mstd::wstring&, uint8_t*, uint32_t>()(this, name, data, size);
        }

        static const mstd::wstring& getSkinPathFromId(void* ptr, uint32_t id) {
            return code::Func<const mstd::wstring&, 0x02f6d438, void*, uint32_t>()(ptr, id);
        }

        void SetAppPaused(bool b) {
            code::Func<void, 0x02f2bf6c, CMinecraftApp*, bool>()(this, b);
        }

        bool isAppPaused()  {
            return code::Func<bool, 0x02f36eec, CMinecraftApp*>()(this);
        }

        static CMinecraftApp* getInstance() {
            #ifdef CEMU
                return code::Mem(0x10528DC0).as<CMinecraftApp*>();
            #else
                return code::Mem(0x10A2AFC0).as<CMinecraftApp*>();
            #endif
        }
    };
}