#pragma once

#include <code/code.h>

#include "Vec3.h"

namespace mc {
    class AABB {
    public:
        AABB(double x1, double y1, double z1, double x2, double y2, double z2) {
            code::Func<void, 0x0200c920, AABB*, double, double, double, double, double, double>()(this, x1, y1, z1, x2, y2, z2);
        }

        AABB(const AABB& aabb) {
            code::Func<void, 0x02ca58a8, AABB*, const AABB&>()(this, aabb);
        }

        AABB(int x1, int y1, int z1, int x2, int y2, int z2) {
            code::Func<void, 0x0200c920, AABB*, float, float, float, float, float, float>()(this, 
                toFloat(x1), toFloat(y1), toFloat(z1),
                toFloat(x2), toFloat(y2), toFloat(z2)
            );
        }

        void set(const AABB* aabb) {
            code::Func<void, 0x0200cf7c, AABB*, const AABB*>()(this, aabb);
        }

        AABB move(double x, double y, double z) {
            return code::Func<AABB, 0x0200d260, AABB*, double, double, double>()(this, x, y, z);
        }

        static void CreateNewThreadStorage() {
            code::Func<void, 0x0200C76C>()();
        }

        Vec3 min;
        Vec3 max;
    };
}