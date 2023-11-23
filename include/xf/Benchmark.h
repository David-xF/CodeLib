#pragma once

#include <minecraft/mc.h>

namespace xf {
    enum T_UNIT {
        MILLI, NANO
    };
    class Benchmark {
    public:
        template<typename T, typename... Args>
        static uint64_t measure(T* funcPtr, T_UNIT unit, Args... args) {
            switch (unit) {
            case MILLI:
                return measureMilli(funcPtr, args...);
                break;
            case NANO:
                return measureNano(funcPtr, args...);
                break;
            default:
                return measureMilli(funcPtr, args...);
                break;
            }
        }

        template<typename T, typename... Args>
        static uint64_t measureMilli(T* funcPtr, Args... args) {
            uint64_t startTime = mc::System::processTimeInMilliSecs();
            funcPtr(args...);
            return mc::System::processTimeInMilliSecs() - startTime;
        }

        template<typename T, typename... Args>
        static uint64_t measureNano(T* funcPtr, Args... args) {
            uint64_t startTime = mc::System::processTimeInNanoSecs();
            funcPtr(args...);
            return mc::System::processTimeInNanoSecs() - startTime;
        }
    };
}