#pragma once

#include <code/code.h>

namespace mc {
    class ItemInstance {
    public:
        ItemInstance(struct Item* item, int amount) {
            code::Func<void, 0x024861BC, ItemInstance*, struct Item*, int>()(this, item, amount);
        }

        ItemInstance(struct Item* item, int amount, int aux) {
            code::Func<void, 0x024862d0, ItemInstance*, struct Item*, int, int>()(this, item, amount, aux);
        }

        void setAuxValue(int val) {
            code::Func<void, 0x02488B2C, ItemInstance*, int>()(this, val);
        }

        struct CompoundTag* getTag() {
            return code::Func<struct CompoundTag*, 0x02488888, ItemInstance*>()(this);
        }

        void setTag(struct CompoundTag* _tag) {
            code::Func<void, 0x0248e080, ItemInstance*, struct CompoundTag*>()(this, _tag);
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
        int count; // i think
        uint32_t field_0xC;
        struct Item* item;
        struct CompoundTag* tag;
        uint32_t field_0x18;
        int aux;
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