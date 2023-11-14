#pragma once

namespace mstd {
    template<typename T>
    class vector {
    public:
        typedef       T*  iter;
        typedef const T* citer;

        iter  begin()       { return &start[0]; }
        citer begin() const { return &start[0]; }
        iter  end()       { return &start[size()]; }
        citer end() const { return &start[size()]; }
        
        T operator[](int i) {
            return this->start[i];
        }
        
        int size() {
            return ((int) finish - (int) start) / sizeof(T);
        }

        uint32_t unk_0x0;
        T* start;
        T* finish;
        T* end_of_storage;
    };
}