#pragma once

#include "Mob.h"

namespace mc {
    class Slime : public Mob {
    public:
        Slime(struct Level* _level) {
            code::Func<void, 0x02940310, Slime*, struct Level*>()(this, _level);
        }

        void setSize(int size, bool unk) {
            code::Func<void, 0x029408a0, Slime*, int, bool>()(this, size, unk);
        }

        uint32_t field_0x708;
        uint32_t field_0x70C;
        uint32_t field_0x710;
        uint32_t field_0x714;
    };
}