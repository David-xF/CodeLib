#pragma once

#include "Entity.h"

namespace mc {
    class ItemFrame : public Entity {
    public:
        static uint64_t GetType() {
            return code::Func<uint64_t, 0x0252cc3c>()();
        }
    };
}