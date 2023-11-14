#pragma once

#include <code/code.h>

namespace mc {
    class C4JThreadImpl {
    public:
        C4JThreadImpl(int(*func)(void*), void* data, const char* name, int stack_size) {
            code::Func<void, 0x034acac0, C4JThreadImpl*, int(*)(void*), void*, const char*, int>()(this, func, data, name, stack_size);
        }

        void SetDeleteOnExit(bool ex) {
            code::Func<void, 0x034ad0b0, C4JThreadImpl*, bool>()(this, ex);
        }

        void Run() {
            code::Func<void, 0x034acf6c, C4JThreadImpl*>()(this);
        }

        bool isRunning() {
            return code::Func<bool, 0x034acfcc, C4JThreadImpl*>()(this);
        }

        uint8_t data[0x78];
    };
}