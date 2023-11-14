#pragma once

namespace xf {
    template<typename T, typename U>
    class Pair {
    public:
        Pair(T a, U b) {
            valT = a;
            valU = b;
        }

    private:
        T valT;
        U valU;
    };

    template<typename T, typename U>
    class Map {
    public:
        Map() {
            pairs = nullptr;
            length = 0;
        }

        U& operator[](T t) {
            
        }
    
    private:
        Pair* pairs;        
        int length;
    };
}