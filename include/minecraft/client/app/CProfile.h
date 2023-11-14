#pragma once

#include <code/code.h>

#include "../resource/wstring.h"

namespace mc {
    class CProfile {
    public:
        static CProfile* GetProfile() {
            return code::Mem(0x10AD1C58 - 0x502200).as<CProfile*>();
        }

        void CreatePresenceString(uint32_t id, const mstd::wstring& wcstr) {
            code::Func<void, 0x0341118C, CProfile*, uint32_t, const mstd::wstring&>()(this, id, wcstr);
        }

        void SetPresenceString(uint32_t id) {
            code::Func<void, 0x034114F4, CProfile*, uint32_t>()(this, id);
        }
    };
}