#pragma once

#include <code/code.h>

#include "../resource/wstring.h"
#include "../resource/vector.h"

namespace mc {
    class File {
    public:
        File(const mstd::wstring& path) {
            code::Func<void, 0x023237c0, File*, const mstd::wstring&>()(this, path);
        }
        
        File() = default;

        bool exists() {
            return code::Func<bool, 0x023209b8, File*>()(this);
        }

        void _delete() {
            code::Func<void, 0x023238e4, File*>()(this);
        }

        void getPath(const mstd::wstring& str) {
            code::Func<void, 0x0232042C, File*, const mstd::wstring&>()(this, str);
        }

        mstd::vector<File*>& getFiles() {
            return code::Func<mstd::vector<File*>&, 0x02324220, File*>()(this); 
        }

        void getName(const mstd::wstring& name) {
            code::Func<void, 0x02324904, File*, const mstd::wstring&>()(this, name);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
    };
}