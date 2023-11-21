#pragma once

#include <code/code.h>

#include "../client/resource/ResourceLocation.h"
#include "../client/resource/wstring.h"

namespace mc {
    class Item {
    public:
        Item() {
            code::Func<void, 0x024B65D8, Item*>()(this);
        }

        void HandEquipped() {
            code::Func<void, 0x024B6904, Item*>()(this);
        }

        void setMaxDamage(uint32_t arg1) {
            code::Func<void, 0x024B6910, Item*, uint32_t>()(this, arg1);
        }

        void setCraftingRemainingItem(uint32_t arg1) {
            code::Func<void, 0x024B6C40, Item*, uint32_t>()(this, arg1);
        }

        void setStackedByData(bool arg1) {
            code::Func<void, 0x024B6C48, Item*, uint8_t>()(this, arg1);
        }

        void setMaxStackSize(int size) {
            code::Func<void, 0x024b2bd8, Item*, int>()(this, size);
        }

        static bool isItemABlock(int id) {
            return code::Func<bool, 0x024cf838, int>()(id);
        }

        uint32_t getBaseItemType() {
            return code::Func<uint32_t, 0x024CFD24, Item*>()(this);
        }

        uint32_t getMaxStackSize() {
            return code::Func<uint32_t, 0x024CFFC4, Item*>()(this);
        }

        void setIconName(const mstd::wstring& name) {
            code::Func<void, 0x024b2b90, Item*, const mstd::wstring&>()(this, name);
        }

        void setAllowOffhand(bool allow) {
            code::Func<void, 0x024b63bc, Item*, bool>()(this, allow);
        }

        bool isHandEquipped() {
            return code::Func<uint8_t, 0x024D0030, Item*>()(this);
        }

        static Item* byId(int id) {
            return code::Func<Item*, 0x02486698, int>()(id);
        }

        static void registerItem(int id, const ResourceLocation& loc, Item* item) {
            code::Func<void, 0x24B3D60, int, const ResourceLocation&, Item*>()(id, loc, item);
        }

        int getId() {
            return code::Func<int, 0x02492100, Item*>()(this);
        }
    
        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t maxStackSize;
        uint32_t maxDamage;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        mstd::wstring unk_str;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        mstd::wstring iconName;
        uint32_t field_0x70;
        struct VTable_Item* vtbl;
    };
}