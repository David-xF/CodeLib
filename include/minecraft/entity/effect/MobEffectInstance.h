#pragma once

#include <code/code.h>

namespace mc {
    class MobEffectInstance {
    public:
        MobEffectInstance(struct MobEffect* eff) {
            code::Func<void, 0x02692ac4, MobEffectInstance*, struct MobEffect*>()(this, eff);
        }

        int getDuration() {
            return code::Func<int, 0x02691790, MobEffectInstance*>()(this);
        }

        int getAmplifier() {
            return code::Func<int, 0x02692df0, MobEffectInstance*>()(this);
        }

        uint32_t field_0x0;
        uint32_t duration;
        uint32_t amplifier;
        bool field_0xC;
        bool field_0xD;
        bool ambient;
        bool visible;
        uint32_t field_0x10;
    };
}