#pragma once

#include <cmath>

#include "FloatConverter.h"

namespace mc {
    class Vec3 {
    public:
        Vec3(int _x, int _y, int _z) {
            x = toFloat(_x) + 0.5f;
            y = toFloat(_y);
            z = toFloat(_z) + 0.5f;
        }

        Vec3(double _x, double _y, double _z) {
            x = _x;
            y = _y;
            z = _z;
        }

        Vec3() = default;

        float distance(Vec3 other) {
            return sqrtf(
                powf(x - other.x, 2) + 
                powf(y - other.y, 2) + 
                powf(z - other.z, 2)
            );
        }

        void operator*=(double amt) {
            x *= amt;
            y *= amt;
            z *= amt;
        }

        Vec3 operator*(double amt) {
            return Vec3(x * amt, y * amt, z * amt);
        }

        Vec3 operator+(Vec3 other) {
            return Vec3(x + other.x, y + other.y, z + other.z);
        }

        bool operator==(Vec3 other) {
            bool b_x = x == other.x;
            bool b_y = y == other.y;
            bool b_z = z == other.z;

            return b_x && b_y && b_z;
        }

        double x;
        double y;
        double z;
    };
}