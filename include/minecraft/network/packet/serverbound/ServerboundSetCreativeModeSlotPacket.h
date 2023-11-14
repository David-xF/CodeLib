#pragma once

#include <code/code.h>

#include "../Packet.h"

#include "../../../client/resource/shared_ptr.h"

namespace mc {
    class ServerboundSetCreativeModeSlotPacket : public Packet {
    public:
        ServerboundSetCreativeModeSlotPacket(int slot, const mc_boost::shared_ptr<struct ItemInstance>& item) {
            code::Func<void, 0x028B09F8, ServerboundSetCreativeModeSlotPacket*, int, const mc_boost::shared_ptr<struct ItemInstance>&>()(this, slot, item);
        }

        uint32_t field_0x10;
        uint32_t field_0x14;
        int slotNum;
        mc_boost::shared_ptr<struct ItemInstance> iteminstance;
        uint32_t field_0x24;
    };
}