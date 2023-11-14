#pragma once

#include <code/code.h>

namespace mc {
    class MinecraftServer {
    public:
        static MinecraftServer* getInstance() {
            return code::Mem(0x104CB6FC).as<MinecraftServer*>();
        }

        struct ServerLevel* getLevel(int i) {
            return code::Func<struct ServerLevel*, 0x03222954, MinecraftServer*, int>()(this, i);
        }

        struct PlayerList* getPlayers() {
            return code::Func<struct PlayerList*, 0x03225F74, MinecraftServer*>()(this);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        struct PlayerList* field_0x14;
        uint32_t field_0x18;

    };
}