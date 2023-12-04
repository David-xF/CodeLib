#pragma once

#include <code/code.h>

#include "../client/resource/wstring.h"

namespace mc {
    class EquipmentSlot {
    public:
        static EquipmentSlot* RIGHT_HAND asm("0x104C2778");
        static EquipmentSlot* LEFT_HAND  asm("0x104C277C");
        static EquipmentSlot* BOOTS      asm("0x104C2780");
        static EquipmentSlot* LEGGINGS   asm("0x104C2784");
        static EquipmentSlot* CHEST      asm("0x104C2788");
        static EquipmentSlot* HEAD       asm("0x104C278C");

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        mstd::wstring str;
    };
}