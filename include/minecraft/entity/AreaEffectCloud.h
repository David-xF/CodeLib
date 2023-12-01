#pragma once

#include "Entity.h"

namespace mc {
    class AreaEffectCloud : public Entity {
    public:
        AreaEffectCloud(struct Level* _level) {
            code::Func<void, 0x02085B3C, AreaEffectCloud*, struct Level*>()(this, _level);
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

        void setRadius(float r) {
            code::Func<void, 0x02082644, AreaEffectCloud*, float>()(this, r);
        }

        void particleSpawnRateOnTick(int rate) {
            code::Func<void, 0x020869cc, AreaEffectCloud*, int>()(this, rate);
        }

        void setPotion(struct Potion* potion) {
            code::Func<void, 0x020864b0, AreaEffectCloud*, struct Potion*>()(this, potion);
        }

        void setRadiusPerTick(float r) {
            code::Func<void, 0x02086ea0, AreaEffectCloud*, float>()(this, r);
        }

        void setRadiusOnUse(float r) {
            code::Func<void, 0x02086e98, AreaEffectCloud*, float>()(this, r);
        }

        uint32_t field_0x350;
        uint32_t field_0x354;
        uint32_t field_0x358;
        uint32_t field_0x35C;
        uint32_t field_0x360;
        uint32_t field_0x364;
        uint32_t field_0x368;
        uint32_t field_0x36C;
        uint32_t field_0x370;
        uint32_t field_0x374;
        uint32_t field_0x378;
        uint32_t field_0x37C;
        uint32_t field_0x380;
        uint32_t field_0x384;
        uint32_t field_0x388;
        uint32_t field_0x38C;
        uint32_t field_0x390;
        uint32_t field_0x394;
        uint32_t field_0x398;
        uint32_t field_0x39C;
        uint32_t field_0x3A0;
        uint32_t field_0x3A4;
        uint32_t field_0x3A8;
        uint32_t field_0x3AC;
        uint32_t field_0x3B0;
        uint32_t field_0x3B4;
        uint32_t field_0x3B8;
        uint32_t field_0x3BC;
    };
}