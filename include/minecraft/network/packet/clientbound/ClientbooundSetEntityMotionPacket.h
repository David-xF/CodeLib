#pragma once

#include <code/code.h>

#include "../Packet.h"

namespace mc {
    class ClientboundSetEntityMotionPacket : public Packet {
    public:
        ClientboundSetEntityMotionPacket(int id, double x, double y, double z) {
            code::Func<void, 0x0221e214, ClientboundSetEntityMotionPacket*, int, double, double, double>()(this, id, x, y, z);
        }

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
    };
}