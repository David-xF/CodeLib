#pragma once

#include <code/code.h>

#include "File.h"

namespace mc {
    class FileInputStream {
    public:
        FileInputStream(const File& file) {
            code::Func<void, 0x023204a4, FileInputStream*, const File&>()(this, file);
        }

        char read() {
            return code::Func<char, 0x023206ac, FileInputStream*>()(this);
        }

        void read(void* unk) {
            code::Func<void, 0x02320788, FileInputStream*, void*>()(this, unk);
        }

        void skip(int l) {
            code::Func<void, 0x02320984, FileInputStream*, int>()(this, l);
        }

        int filesize() {
            return code::Func<int, 0x02320990, FileInputStream*>()(this);
        }

        void close() {
            code::Func<void, 0x02320938, FileInputStream*>()(this);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
    };
}