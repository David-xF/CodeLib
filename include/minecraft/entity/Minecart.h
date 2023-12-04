#pragma once

#include "Entity.h"

namespace mc {
    class Minecart : public Entity {
    public:
        Minecart(struct Level* _level) {
            code::Func<void, 0x0265261c, Minecart*, struct Level*>()(this, _level);
        }

        static code::Func<double, 0x02658a1c> _getMaxSpeed;
        static double getMaxSpeed() {
            return _getMaxSpeed();
        }

        static uint64_t GetType() {
            return code::Func<uint64_t, 0x026c4348>()();
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
    };
}