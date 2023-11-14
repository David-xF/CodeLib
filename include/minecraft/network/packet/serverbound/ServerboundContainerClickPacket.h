#pragma once

#include <code/code.h>

#include "../Packet.h"

#include "../../../client/resource/vector.h"
#include "../../../client/resource/shared_ptr.h"

#include "../../../util/ClickType.h"

namespace mc { 
    class ServerboundContainerClickPacket : public Packet {
    public:
        ServerboundContainerClickPacket(int a, int b, int c, ClickType::eClickType type, const mc_boost::shared_ptr<struct ItemInstance>& item, short s) {
            code::Func<void, 0x028aaafc, ServerboundContainerClickPacket*, 
                int, int, int, ClickType::eClickType, const mc_boost::shared_ptr<struct ItemInstance>&, short>()(this, a, b, c, type, item, s);
        }

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t containerId;
        uint32_t slotNum;
        uint32_t buttonNum;
        uint32_t uid;
        mstd::vector<mc_boost::shared_ptr<struct ItemInstance>> items;
        ClickType::eClickType clickType;
        uint32_t numSlots;
    };
}