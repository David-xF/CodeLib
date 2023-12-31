#pragma once

#include "LivingEntity.h"

namespace mc {
    class ArmorStand : public LivingEntity {
    public:
        ArmorStand(struct Level* _level) {
            code::Func<void, 0x0208bad4, ArmorStand*, struct Level*>()(this, _level);
        }

        void setShorArms(bool state) {
            code::Func<void, 0x0202ece8, ArmorStand*, bool>()(this, state);
        }

        void setItemSlot(struct EquipmentSlot* slot, const mc_boost::shared_ptr<struct ItemInstance>& item) {
            code::Func<void, 0x0208c018, ArmorStand*, struct EquipmentSlot*, const mc_boost::shared_ptr<struct ItemInstance>&>()(this, slot, item);
        }

        static uint64_t GetType() {
            return code::Func<uint64_t, 0x020b3dbc>()();
        }

        uint32_t field_0x5F0;
        uint32_t field_0x5F4;
        uint32_t field_0x5F8;
        uint32_t field_0x5FC;
        uint32_t field_0x600;
        uint32_t field_0x604;
        uint32_t field_0x608;
        uint32_t field_0x60C;
        uint32_t field_0x610;
        uint32_t field_0x614;
        uint32_t field_0x618;
        uint32_t field_0x61C;
        uint32_t field_0x620;
        uint32_t field_0x624;
    };
}