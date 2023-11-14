#pragma once

#include "Item.h"

#include "../util/BlockPos.h"
#include "../client/resource/shared_ptr.h"

namespace mc {
    class BlockItem : public Item {
    public:
        BlockItem(struct Block* block) {
            code::Func<void, 0x02171ecc, BlockItem*, struct Block*>()(this, block);
        }

        bool mayPlace(struct Level* level, const BlockPos& pos, struct Direction* dir, const mc_boost::shared_ptr<struct Player>& player, const mc_boost::shared_ptr<struct ItemInstance>& item) {
            return code::Func<bool, 0x02173C88, BlockItem*, struct Level*, const BlockPos&, struct Direction*, const mc_boost::shared_ptr<struct Player>&, const mc_boost::shared_ptr<struct ItemInstance>&>()(this, level, pos, dir, player, item);
        }

        uint32_t field_0x78;
    };
}