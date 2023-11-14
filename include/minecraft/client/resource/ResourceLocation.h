#pragma once

#include <code/code.h>

#include "wstring.h"

namespace mc {
    class ResourceLocation {
    public:
        ResourceLocation(const mstd::wstring& str1, const mstd::wstring& str2) {
            code::Func<void, 0x03250d30, ResourceLocation*, const mstd::wstring&, const mstd::wstring&>()(this, str1, str2);
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
    };
}