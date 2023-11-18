#pragma once

#include <code/code.h>

#include "BlockEntity.h"

namespace mc {
    class TheEndGatewayEntity : public BlockEntity {
    public:
        void save(struct CompoundTag* tag) {
            code::Func<void, 0x029ECA18, TheEndGatewayEntity*, struct CompoundTag*>()(this, tag);
        }

        void load(struct CompoundTag* tag) {
            code::Func<void, 0x029ECC54, TheEndGatewayEntity*, struct CompoundTag*>()(this, tag);
        }

        void SetExitPortal(struct BlockPos* pos) {
            code::Func<void, 0x0298B7E4, TheEndGatewayEntity*, struct BlockPos*>()(this, pos);
        }

        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        struct BlockPos* exitPortal;
        uint32_t field_0x38;
        uint32_t field_0x3C;
    };
}