#pragma once

#include <inttypes.h>

namespace mc {
    class FoodData {
    public:
        uint32_t foodLevel;
        float saturationLevel;
        uint32_t exhaustion;
        uint32_t field_0xC;
        uint32_t lastFoodLevel;
    };
}