#pragma once

#include <code/code.h>

namespace mc {
    class PlayerUID {
    public:
        bool operator==(const PlayerUID& playerUID) {
            return code::Func<bool, 0x034a39c8, PlayerUID*, const PlayerUID&>()(this, playerUID);
        }

        bool operator!=(const PlayerUID& playerUID) {
            return code::Func<bool, 0x034a3a80, PlayerUID*, const PlayerUID&>()(this, playerUID);
        }

        uint32_t uid[5]; 
    };
}