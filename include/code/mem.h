#pragma once

#include <inttypes.h>

namespace code {
    class Mem {
    private:
        uint32_t base;

    public:
        Mem(uint32_t addr) { base = addr; }

        Mem operator[](int offset) {
            return Mem(as<uint32_t>() + offset);
        }

        template<typename T>
        T& as() {
            return *reinterpret_cast<T*>(base);
        }
    };
}