#pragma once

#include <cmath>

#include "FloatConverter.h"

namespace mc {
    template<typename T>
    class Matrix4 {
    public:
        Matrix4(T standartVal) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    data[i][j] = standartVal;
                }
            }
        }

        Matrix4() = default;

        T getData(int a, int b) {
            return data[a][b];
        }

        void copy(Matrix4 other) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    data[i][j] = other.getData(i, j);
                }
            }
        }

        Matrix4 operator=(Matrix4 other) {
            copy(other);
            return *this;
        }

        T data[4][4];
    };
}