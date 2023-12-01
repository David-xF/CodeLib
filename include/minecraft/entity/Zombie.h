#pragma once

#include "Monster.h"

namespace mc {
    class Zombie : public Monster {
    public:
        Zombie(struct Level* _level) {
            code::Func<void, 0x02a3a914, Zombie*, struct Level*>()(this, _level);
        }

        uint32_t field_0x730;
        uint32_t field_0x734;
        uint32_t field_0x738;
        uint32_t field_0x73C;
        uint32_t field_0x740;
        uint32_t field_0x744;
        uint32_t field_0x748;
        uint32_t field_0x74C;
    };
}