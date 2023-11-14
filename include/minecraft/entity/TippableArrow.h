#pragma once

#include "Entity.h"

namespace mc {
    class TippableArrow : public Entity {
    public:
        static uint64_t GetType() {
            return code::Func<uint64_t, 0x02a131a4>()();
        }
    };
}