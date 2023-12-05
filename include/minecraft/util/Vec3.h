#pragma once

#include <cmath>

#include "FloatConverter.h"

namespace mc {
    class Vec3 {
    public:
        Vec3(double _x, double _y, double _z) {
            x = _x;
            y = _y;
            z = _z;
        }
        
        Vec3() = default;

        double distance(Vec3 other) {
            return sqrt(
                pow(x - other.x, 2.0) + 
                pow(y - other.y, 2.0) + 
                pow(z - other.z, 2.0)
            );
        }

        Vec3 operator+(Vec3 other) {
            return Vec3(x + other.x, y + other.y, z + other.z);
        }

        Vec3 operator+(double amt) {
            return Vec3(x + amt, y + amt, z + amt);
        }

        Vec3 operator+(float amt) {
            return Vec3(x + amt, y + amt, z + amt);
        }

        Vec3 operator-(Vec3 other) {
            return Vec3(x - other.x, y - other.y, z - other.z);
        }

        Vec3 operator-(double amt) {
            return Vec3(x - amt, y - amt, z - amt);
        }

        Vec3 operator-(float amt) {
            return Vec3(x - amt, y - amt, z - amt);
        }

        Vec3 operator*(Vec3 other) {
            return Vec3(x * other.x, y * other.y, z * other.z);
        }

        Vec3 operator*(double amt) {
            return Vec3(x * amt, y * amt, z * amt);
        }

        Vec3 operator*(float mult) {
            return Vec3(x * mult, y * mult, z * mult);
        }

        Vec3 operator/(Vec3 other) {
            return Vec3(x / other.x, y / other.y, z / other.z);
        }

        Vec3 operator/(double amt) {
            return Vec3(x / amt, y / amt, z / amt);
        }

        Vec3 operator/(float mult) {
            return Vec3(x / mult, y / mult, z / mult);
        }

        Vec3 operator=(Vec3 other) {
            x = other.x;
            y = other.y;
            z = other.z;

            return *this;
        }

        Vec3 operator*=(double amt) {
            x *= amt;
            y *= amt;
            z *= amt;
        
            return *this;
        }

        bool operator==(Vec3 other) {
            bool b_x = x == other.x;
            bool b_y = y == other.y;
            bool b_z = z == other.z;

            return b_x && b_y && b_z;
        }

        bool operator!=(Vec3 other) {
            bool b_x = x != other.x;
            bool b_y = y != other.y;
            bool b_z = z != other.z;

            return b_x && b_y && b_z;
        }

        double x;
        double y;
        double z;
    };
}