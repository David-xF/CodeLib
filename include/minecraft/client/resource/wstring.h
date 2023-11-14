#pragma once

#include <code/code.h>
#include <inttypes.h>

namespace mstd {
    class wstring {
    public:
        wstring(const wchar_t* str) {
            code::Func<void, 0x020B08D4, wstring*, const wchar_t*>()(this, str);
        }

        wstring() = default;
        
        const wchar_t* c_str() const {
            return (length > 7) ? pointer : str;
        }

        const wstring& assign(const wchar_t* _str, int _length) {
            return code::Func<const mstd::wstring&, 0x030E8BC4, wstring*, const wchar_t*, int>()(this, _str, _length);
        }

        bool operator==(const wchar_t* _str) {
            const wchar_t* __str = c_str();
            return wcscmp(__str, _str);
        }

        uint32_t unk_0x0; // 0x00
        wchar_t str[8];   // 0x04
        wchar_t* pointer; // 0x14
        uint32_t length;  // 0x18
        uint32_t length2; // 0x1C
    };
}