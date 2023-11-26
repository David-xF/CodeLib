#pragma once

#include <code/code.h>

#include "../Packet.h"

#include "../../../util/BlockPos.h"

namespace mc {
    class ClientboundBlockUpdatePacket : public Packet {
    public:
        ClientboundBlockUpdatePacket(struct Level* level, const BlockPos& pos) {
            code::Func<void, 0x021DF3C8, ClientboundBlockUpdatePacket*, struct Level*, const BlockPos&>()(this, level, pos);
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