#pragma once

#include <code/code.h>

#include "Item.h"

namespace mc {
    class BowItem : public Item {
    public:
        BowItem() {
            code::Func<void, 0x02162460, BowItem*>()(this);
        }

        Item* releaseUsing(const mc_boost::shared_ptr<struct ItemInstance>& instance, struct Level* level, const mc_boost::shared_ptr<struct LivingEntity>& entity, int idk) {
            return code::Func<Item*, 0x02164810, BowItem*, const mc_boost::shared_ptr<struct ItemInstance>&, struct Level*, const mc_boost::shared_ptr<struct LivingEntity>&, int>()(this, instance, level, entity, idk);
        }

        #ifdef CEMU
            DEFINE_STATIC_DEF_VAR(struct VTable_Item*, vtbl, 0x10061554);
        #else
            DEFINE_STATIC_DEF_VAR(struct VTable_Item*, vtbl, 0x10563754);
        #endif
        DEFINE_STATIC_DEF_VAR(int, itemId, 261);

        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
    };
}