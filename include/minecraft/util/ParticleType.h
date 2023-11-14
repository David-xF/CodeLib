#pragma once

#include <code/code.h>

#include "ePARTICLE_TYPE.h"

namespace mc {
    class ParticleType {
    public:
        static ParticleType* byId(ePARTICLE_TYPE type) {
            return code::Func<ParticleType*, 0x26D9A54, ePARTICLE_TYPE>()(type);
        }
    };
}