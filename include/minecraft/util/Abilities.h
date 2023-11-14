#pragma once

#include <code/code.h>

namespace mc {
    class Abilities {
    public: 
        bool operator==(const Abilities& abilities) {
            return code::Func<bool, 0x0200e1f4, Abilities*, const Abilities&>()(this, abilities);
        }

        float getFlyingSpeed() {
            return code::Func<float, 0x0200ed38, Abilities*>()(this);
        }

        void setFlyingSpeed(float newSpeed) {
            code::Func<void, 0x0200ed40, Abilities*, float>()(this, newSpeed);
        }

        float getWalkingSpeed() {
            return code::Func<float, 0x0200ed48, Abilities*>()(this);
        }

        void setWalkingSpeed(float newSpeed) {
            code::Func<void, 0x0200ed50, Abilities*, float>()(this, newSpeed);
        }

        bool isInvulnerable;
        bool isFlying;
        bool canFly;
        bool canInstaBuild;
        float field_0x4;
        float flySpeed;
        float walkSpeed;
    };
}