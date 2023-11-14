#pragma once

#include <minecraft/mc/miscellanious.h>

int __n = 0;

namespace xf {
    namespace Math {
        enum ERotation {
            X, Y, Z
        };

        class mat4 {
        public:
            mat4(float* mat) {
                for (int i = 0; i < 4; i++) row1[i] = mat[i + 0x0];
                for (int i = 0; i < 4; i++) row2[i] = mat[i + 0x4];
                for (int i = 0; i < 4; i++) row3[i] = mat[i + 0x8];
                for (int i = 0; i < 4; i++) row4[i] = mat[i + 0xC];
            }

            float row1[4];
            float row2[4];
            float row3[4];
            float row4[4];
        };

        class vec3 {
        public:
            vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {
                x = _x;
                y = _y;
                z = _z;
            }

            float getX() { return x; }
            float getY() { return y; }
            float getZ() { return z; }

            float distance(vec3& other) {
                return sqrtf(powf(getX() - other.getX(), 2) + powf(getY() - other.getY(), 2) + powf(getZ() - other.getZ(), 2));
            }

            static vec3 getLookAt(float yaw, float pitch) {
                return vec3(
                    fabs(sinf(degToRad(pitch - 90.0f))) * sinf(degToRad(yaw   - 180.0f)),
                                                          sinf(degToRad(pitch - 180.0f)),
                    fabs(sinf(degToRad(pitch - 90.0f))) * cosf(degToRad(yaw))
                );
            }
            
            vec3 cross(vec3 other) {
                return vec3(
                    y * other.getZ() - z * other.getY(),
                    z * other.getX() - x * other.getZ(),
                    x * other.getY() - y * other.getX()
                );  
            }

            vec3 normal() {
                float length = sqrtf(x*x + y*y + z*z);
                return vec3(x / length, y / length, z / length);
            }

            vec3 invert() {
                return vec3(-x, -y, -z);
            }

            vec3 operator+(vec3 add) {
                return vec3(x + add.getX(), y + add.getY(), z + add.getZ());
            }

            vec3 operator*(float mult) {
                return vec3(x * mult, y * mult, z * mult);
            }

            vec3 operator*(mat4& mat) {
                return vec3(
                    mat.row1[0]*x + mat.row1[1]*y + mat.row1[2]*z + mat.row1[3],
                    mat.row2[0]*x + mat.row2[1]*y + mat.row2[2]*z + mat.row2[3],
                    mat.row3[0]*x + mat.row3[1]*y + mat.row3[2]*z + mat.row3[3]
                );
            }
        private:
            float x;
            float y;
            float z;
        };
    }
}