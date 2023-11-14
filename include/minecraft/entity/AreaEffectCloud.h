#pragma once

#include "Entity.h"

namespace mc {
    class AreaEffectCloud : public Entity {
    public:
        static AreaEffectCloud* create(struct Level* level) {
            return code::Func<AreaEffectCloud*, 0x02085B3C, struct Level*>()(level);
        }

        static uint64_t GetType() {
            return code::Func<uint64_t, 0x020b3cdc>()();
        }

        int getDuration() {
            return code::Func<int, 0x02086C14, AreaEffectCloud*>()(this);
        }

        void setDuration(int dur) {
            code::Func<void, 0x02086C1C, AreaEffectCloud*, int>()(this, dur);
        }

        void setParticle(struct ParticleType* type) {
            code::Func<void, 0x02086658, AreaEffectCloud*, struct ParticleType*>()(this, type);
        }
    };
}