#pragma once

#include <code/code.h>

#include "Item.h"
#include "../nbt/CompundTag.h"

namespace mc {
    class ItemInstance {
    public:
        ItemInstance(Item* item, int amount) {
            code::Func<void, 0x024861BC, ItemInstance*, Item*, int>()(this, item, amount);
        }

        ItemInstance(Item* item, int amount, int aux) {
            code::Func<void, 0x024862d0, ItemInstance*, Item*, int, int>()(this, item, amount, aux);
        }

        void setAuxValue(int val) {
            code::Func<void, 0x02488B2C, ItemInstance*, int>()(this, val);
        }

        CompoundTag* getTag() {
            return code::Func<CompoundTag*, 0x02488888, ItemInstance*>()(this);
        }

        void setTag(CompoundTag* _tag) {
            code::Func<void, 0x0248e080, ItemInstance*, CompoundTag*>()(this, _tag);
        }

        bool hasTag() {
            return code::Func<bool, 0x02488860, ItemInstance*>()(this);
        }

        int getCount() {
            return code::Func<int, 0x02479E14, ItemInstance*>()(this);
        }

        void setCount(int c) {
            code::Func<void, 0x02479e6c, ItemInstance*, int>()(this, c);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t count; // i think
        uint32_t field_0xC;
        Item* item;
        CompoundTag* tag;
        uint32_t field_0x18;
        uint32_t aux;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
    };
}