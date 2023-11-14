#pragma once

#include <code/code.h>

#include "../client/resource/shared_ptr.h"

namespace mc {
    class DamageSource {
    public:
        static DamageSource* CreatePlayerAttack(const mc_boost::shared_ptr<struct Player>& player) {
            return code::Func<DamageSource*, 0x02252ac4, const mc_boost::shared_ptr<struct Player>&>()(player);
        }
    };
}