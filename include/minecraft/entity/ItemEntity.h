#pragma once

#include <code/code.h>

namespace mc {
    class ItemEntity {
    public:
        static uint64_t GetType() {
            return code::Func<uint64_t, 0x0252d668>()();
        }
    };
}