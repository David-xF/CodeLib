#pragma once

#include <inttypes.h>

namespace xf {
    template<typename T>
    class Array {
    public:
        Array(T* array, int l) {
            arr = array;
            length = l;
        }

        T* arr;
        int length;

        // Used for 
        // for (T t : this) {}
        typedef       T*  iter;
        typedef const T* citer;

        iter  begin()       { return &arr[0]; }
        citer begin() const { return &arr[0]; }
        iter  end()       { return &arr[length]; }
        citer end() const { return &arr[length]; }
        

        T operator[](int index) {
            return arr[index];
        }
    };
}