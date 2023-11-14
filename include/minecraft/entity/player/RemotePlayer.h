#pragma once

#include <code/code.h>

#include "Player.h"

// 0318ABFC
namespace mc {
    class RemotePlayer : public Player {
    public:
        static uint64_t GetType() {
            return code::Func<uint64_t, 0x0332d9f4>()();
        }

        struct GameType* GetGameType() {
			return code::Func<struct GameType*, 0x032692f8, RemotePlayer*>()(this);
		}

        uint32_t field_0x868;
        uint32_t field_0x86C;
        uint32_t field_0x870;
        uint32_t field_0x874;
        uint32_t field_0x878;
        uint32_t field_0x87C;
        uint32_t field_0x880;
        struct GameType* gameType;
    };
};