#pragma once

namespace mc {
    template<typename T>
    class NonNullList {
    public:
        void* field_0x0;
        int size;
        T* start;
        T* finish;

        typedef       T*  iter;
        typedef const T* citer;

        iter  begin()       { return start; }
        citer begin() const { return start; }
        iter  end()       { return finish; }
        citer end() const { return finish; }
    };
}