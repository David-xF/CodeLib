#pragma once

#include <code/code.h>

namespace mc {
    class MobEffectInstance {
    public:
        int getDuration() {
            return code::Func<int, 0x02691790, MobEffectInstance*>()(this);
        }

        int getAmplifier() {
            return code::Func<int, 0x02692df0, MobEffectInstance*>()(this);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
    };
}