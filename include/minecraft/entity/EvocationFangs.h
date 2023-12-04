#pragma once

#include "Entity.h"

namespace mc {
    class EvocationFangs : public Entity {
    public:
        EvocationFangs(struct Level* _level) {
            code::Func<void, 0x023ab89c, EvocationFangs*, struct Level*>()(this, _level);
        }

        void setOwner(const mc_boost::shared_ptr<struct LivingEntity>& entity) {
            code::Func<void, 0x023ba764, EvocationFangs*, const mc_boost::shared_ptr<struct LivingEntity>&>()(this, entity);
        }

        static uint64_t GetType() {
            return code::Func<uint64_t, 0x023e6fd8>()();
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
    };
}