#pragma once

#include <code/code.h>

#include "BlockPos.h"

namespace mc {
    class EntityTickCache {
    public:
        uint32_t field_0x0;
		uint32_t field_0x4;
		uint32_t field_0x8;
		uint32_t field_0xC;
		uint32_t field_0x10;
		uint32_t field_0x14;
		uint32_t field_0x18;
		uint32_t field_0x1C;
		uint32_t field_0x20;
		BlockPos pos1;
		BlockPos pos2;
		uint32_t field_0x3C; 
        uint32_t field_0x40;
		uint32_t field_0x44;
        uint32_t field_0x48;
		uint32_t field_0x4C; 
    };
}