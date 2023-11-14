#pragma once

#include <code/code.h>

#include "../../client/resource/shared_ptr.h"

namespace mc {
    class ServerPlayerGameMode {
    public:
        void getServerPlayer(const mc_boost::shared_ptr<struct ServerPlayer>& player) {
            code::Func<void, 0x032DE5D8, ServerPlayerGameMode*, const mc_boost::shared_ptr<struct ServerPlayer>&>()(this, player);
        }
    };
}