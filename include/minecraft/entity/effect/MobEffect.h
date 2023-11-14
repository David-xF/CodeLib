#pragma once

#include <code/code.h>

namespace mc {
    class MobEffect {
    public:
        static MobEffect* byId(int id) {
            return code::Func<MobEffect*, 0x026907a4, int>()(id);
        }
    };
}