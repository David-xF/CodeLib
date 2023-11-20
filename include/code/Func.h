#pragma once

#include <inttypes.h>

namespace code {
    template <typename ret, uint32_t _addr, typename... Args>
    class Func {
    public:
        // Added this so i can Replace Stuff Easier
        inline constexpr uint32_t addr() { return _addr; }
        inline constexpr ret operator()(Args... args) {
            return ((ret(*)(Args...))(_addr))(args...);
        }
    };
}