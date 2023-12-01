#pragma once

#include <code/code.h>

#include "Level.h"

#include "../client/resource/shared_ptr.h"

namespace mc {
    class ServerLevel : public Level {
    public:
        void sendParticle(const struct ParticleType* type, double x, double y, double z, int amount, double unk_0, double unk_1, double unk_2, double unk_3, uint32_t n = 0x16600000) {
            uint32_t array[2]  = { 0x0000105F,       0x00000000 };
            uint32_t array2[2] = { (uint32_t) array, 0x00000001 };
            code::Func<void, 0x032BEFB8, ServerLevel*, const struct ParticleType*, double, double, double, int, double, double, double, double, uint32_t*, uint32_t>()(this, type, x, y, z, amount, unk_0, unk_1, unk_2, unk_3, array2, n);
        }

        void sendParticle(const struct ParticleType* type, double x, double y, double z, int amount, double unk_0, double unk_1, double unk_2, double unk_3, uint32_t n, double r, double g, double b) {
            uint32_t array[2]  = { 0x0000105F,       0x00000000 };
            uint32_t array2[2] = { (uint32_t) array, 0x00000001 };
            code::Func<void, 0x032bf004, ServerLevel*, const struct ParticleType*, double, double, double, int, double, double, double, double, uint32_t*, uint32_t, double, double, double>()(this, type, x, y, z, amount, unk_0, unk_1, unk_2, unk_3, array2, n, r, g, b);
        }

        void addEntity(const mc_boost::shared_ptr<struct Entity>& entity) {
            code::Func<void, 0x032C06DC, ServerLevel*, const mc_boost::shared_ptr<struct Entity>&>()(this, entity->this_shared);
        }

        void addGlobalEntity(const mc_boost::shared_ptr<struct Entity>& entity) {
            code::Func<void, 0x032ba450, ServerLevel*, const mc_boost::shared_ptr<struct Entity>&>()(this, entity->this_shared);
        }
    };
}