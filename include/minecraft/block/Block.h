#pragma once

#include <code/code.h>

namespace mc {
    class Block {
    public:
        uint32_t defaultBlockState() {
            return code::Func<uint32_t, 0x020C9700, Block*>()(this);
        }

        static Block* byId(int id) {
            return code::Func<Block*, 0x02019F40, int>()(id);
        }

        static Block* byItem(struct Item* item) {
            return code::Func<Block*, 0x020e634c, struct Item*>()(item); 
        }

        bool isIndestructible() {
            return code::Func<bool, 0x020E75AC, Block*>()(this);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        float destroySpeed;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t baseItemType;
        uint32_t field_0x54;
        uint32_t field_0x58;
        struct SoundType* soundType;
        uint32_t field_0x60;
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
        uint32_t defBlockState;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88;
        uint32_t field_0x8C;
    };
}