#pragma once

#include <code/code.h>

namespace mc {
    class GameType {
    public:
        static GameType* byId(int id) {
            return code::Func<GameType*, 0x02457008, int>()(id);
        }

        int getId() {
            return code::Func<int, 0x02456dcc, GameType*>()(this);
        }
    };
}