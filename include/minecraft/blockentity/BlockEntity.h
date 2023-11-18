#pragma once

#include "../util/BlockPos.h"

namespace mc {
    class BlockEntity {
    public:
        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        mc::BlockPos position;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
    };
}