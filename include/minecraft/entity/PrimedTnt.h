#pragma once

#include <code/code.h>

#include "Entity.h"

namespace mc {
    class PrimedTnt : public Entity {
    public:
        PrimedTnt(struct Level* _level) {
            code::Func<void, 0x027E80E0, PrimedTnt*, struct Level*>()(this, _level);
        }
        
        void setFuse(int fuse) {
            code::Func<void, 0x027e826c, PrimedTnt*, int>()(this, fuse);
        }

        DEFINE_STATIC_VAR(struct VTable_Entity*, vtbl, 0x10225758);
        DEFINE_STATIC_VAR(uint32_t, something_important_with_spawning, 0x100CA7B4);

        uint32_t field_0x350;
        uint32_t field_0x354;
        uint32_t field_0x358;
        uint32_t field_0x35C;
    };
}