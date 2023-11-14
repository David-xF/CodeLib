#pragma once

#include <code/code.h>

#include "File.h"

namespace mc {
    class FileOutputStream {
    public:
        FileOutputStream(const File& file) {
            code::Func<void, 0x02320b24, FileOutputStream*, const File&>()(this, file);
        }

        void write(char c) {
            code::Func<void, 0x02320CC0, FileOutputStream*, char>()(this, c);
        }

        void close() {
            code::Func<void, 0x02320d8c, FileOutputStream*>()(this);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
    };
}