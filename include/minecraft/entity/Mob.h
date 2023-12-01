#pragma once

#include "LivingEntity.h"

namespace mc {
    class Mob : public LivingEntity {
    public:
        void setNoAi(bool state) {
            code::Func<void, 0x02651ec4, Mob*, bool>()(this, state);
        }

        uint32_t field_0x5F0;
        uint32_t field_0x5F4;
        uint32_t field_0x5F8;
        uint32_t field_0x5FC;
        uint32_t field_0x600;
        uint32_t field_0x604;
        uint32_t field_0x608;
        uint32_t field_0x60C;
        uint32_t field_0x610;
        uint32_t field_0x614;
        uint32_t field_0x618;
        uint32_t field_0x61C;
        uint32_t field_0x620;
        uint32_t field_0x624;
        uint32_t field_0x628;
        uint32_t field_0x62C;
        uint32_t field_0x630;
        uint32_t field_0x634;
        uint32_t field_0x638;
        uint32_t field_0x63C;
        uint32_t field_0x640;
        uint32_t field_0x644;
        uint32_t field_0x648;
        uint32_t field_0x64C;
        uint32_t field_0x650;
        uint32_t field_0x654;
        uint32_t field_0x658;
        uint32_t field_0x65C;
        uint32_t field_0x660;
        uint32_t field_0x664;
        uint32_t field_0x668;
        uint32_t field_0x66C;
        uint32_t field_0x670;
        uint32_t field_0x674;
        uint32_t field_0x678;
        uint32_t field_0x67C;
        uint32_t field_0x680;
        uint32_t field_0x684;
        uint32_t field_0x688;
        uint32_t field_0x68C;
        uint32_t field_0x690;
        uint32_t field_0x694;
        uint32_t field_0x698;
        uint32_t field_0x69C;
        uint32_t field_0x6A0;
        uint32_t field_0x6A4;
        uint32_t field_0x6A8;
        uint32_t field_0x6AC;
        uint32_t field_0x6B0;
        uint32_t field_0x6B4;
        uint32_t field_0x6B8;
        uint32_t field_0x6BC;
        uint32_t field_0x6C0;
        uint32_t field_0x6C4;
        uint32_t field_0x6C8;
        uint32_t field_0x6CC;
        uint32_t field_0x6D0;
        uint32_t field_0x6D4;
        uint32_t field_0x6D8;
        uint32_t field_0x6DC;
        uint32_t field_0x6E0;
        uint32_t field_0x6E4;
        uint32_t field_0x6E8;
        uint32_t field_0x6EC;
        uint32_t field_0x6F0;
        uint32_t field_0x6F4;
        uint32_t field_0x6F8;
        uint32_t field_0x6FC;
        uint32_t field_0x700;
        uint32_t field_0x704;
    };
}