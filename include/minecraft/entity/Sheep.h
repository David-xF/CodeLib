#pragma once

#include <code/code.h>

#include "Animal.h"

namespace mc {
    class Sheep : public Animal {
    public:
        Sheep(struct Level* _level) {
            code::Func<void, 0x0287f8b8, Sheep*, struct Level*>()(this, _level);
        }

        void registerGoals() {
            code::Func<void, 0x028802C0, Sheep*>()(this);
        }

        DEFINE_STATIC_DEF_VAR(struct VTable_Entity*, vtbl, 0x10242E30);

        uint32_t field_0x780;
        uint32_t field_0x784;
        uint32_t field_0x788;
        uint32_t field_0x78C;
        uint32_t field_0x790;
        uint32_t field_0x794;
    };
}