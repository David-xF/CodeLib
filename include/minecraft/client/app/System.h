#pragma once

#include <code/code.h>

namespace mc {
    class System {
    public:
        static uint64_t processTimeInMilliSecs() {
            return code::Func<uint64_t, 0x02994408>()();
        }

        static uint64_t processTimeInNanoSecs() {
            return code::Func<uint64_t, 0x0299441c>()();
        }
    };
}