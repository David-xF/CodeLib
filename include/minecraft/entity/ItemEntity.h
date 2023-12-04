#pragma once

#include <code/code.h>

namespace mc {
    class ItemEntity {
    public:
        ItemEntity(struct Level* _level) {
            code::Func<void, 0x024dc21c, ItemEntity*, struct Level*>()(this, _level);
        }

        ItemEntity(struct Level* _level, double x, double y, double z) {
            code::Func<void, 0x024dc0f8, ItemEntity*, struct Level*, double, double, double>()(this, _level, x, y, z);
        }

        ItemEntity(struct Level* _level, double x, double y, double z, const mc_boost::shared_ptr<struct ItemInstance>& item) {
            code::Func<void, 0x024d3b60, ItemEntity*, struct Level*, double, double, double, const mc_boost::shared_ptr<struct ItemInstance>&>()(this, _level, x, y, z, item);
        }

        void setItem(const mc_boost::shared_ptr<struct ItemInstance>& item) {
            code::Func<void, 0x024d3898, ItemEntity*, const mc_boost::shared_ptr<struct ItemInstance>&>()(this, item);
        }

        void setPickUpDelay(int delay) {
            code::Func<void, 0x024e113c, ItemEntity*, int>()(this, delay);
        }

        void setNeverPickUp() {
            code::Func<void, 0x024e1130, ItemEntity*>()(this);
        }

        void setDefaultPickUpDelay() {
            code::Func<void, 0x024d3d54, ItemEntity*>()(this);
        }

        void playerTouch(const mc_boost::shared_ptr<struct Player>& player) {
            code::Func<void, 0x024e0300, ItemEntity*, const mc_boost::shared_ptr<struct Player>&>()(this, player);
        }

        void setShortLifeTime() {
            code::Func<void, 0x024deb94, ItemEntity*>()(this);
        }

        static uint64_t GetType() {
            return code::Func<uint64_t, 0x0252d668>()();
        }

        int lifeTime;
        int pickUpDelay;
        uint32_t field_0x358;
        uint32_t field_0x35C;
        uint32_t field_0x360;
        uint32_t field_0x364;
        uint32_t field_0x368;
        uint32_t field_0x36C;
        uint32_t field_0x370;
        uint32_t field_0x374;
        uint32_t field_0x378;
        uint32_t field_0x37C;
        uint32_t field_0x380;
        uint32_t field_0x384;
        uint32_t field_0x388;
        uint32_t field_0x38C;
        uint32_t field_0x390;
        uint32_t field_0x394;
        uint32_t field_0x398;
        uint32_t field_0x39C;
        uint32_t field_0x3A0;
        uint32_t field_0x3A4;
        uint32_t field_0x3A8;
        uint32_t field_0x3AC;
        uint32_t field_0x3B0;
        uint32_t field_0x3B4;
        uint32_t field_0x3B8;
        uint32_t field_0x3BC;
    };
}