#pragma once

#include <code/code.h>

#include "Tag.h"
#include "ListTag.h"
#include "../client/resource/wstring.h"

namespace mc {
    class CompoundTag : public Tag {
    public:
        CompoundTag() {
            code::Func<void, 0x022182C0, CompoundTag*>()(this);
        }

        void putInt(const mstd::wstring& str, int b) {
            code::Func<void, 0x0221ae10, CompoundTag*, const mstd::wstring&, int>()(this, str, b);
        }

        void putFloat(const mstd::wstring& str, float f) {
            code::Func<void, 0x0221AF68, CompoundTag*, const mstd::wstring&, float>()(this, str, f);
        }

        void putDouble(const mstd::wstring& str, double f) {
            code::Func<void, 0x0221b01c, CompoundTag*, const mstd::wstring&, double>()(this, str, f);
        }

        void putString(const mstd::wstring& str, const mstd::wstring& str2) {
            code::Func<void, 0x022189dc, CompoundTag*, const mstd::wstring&, const mstd::wstring&>()(this, str, str2);
        }

        void putBoolean(const mstd::wstring& str, bool b) {
            code::Func<void, 0x0221B23C, CompoundTag*, const mstd::wstring&, bool>()(this, str, b);
        }

        void putShort(const mstd::wstring& str, int16_t b) {
            code::Func<void, 0x0221ad6c, CompoundTag*, const mstd::wstring&, int16_t>()(this, str, b);
        }

        void put(const mstd::wstring& str, Tag* tag) {
            code::Func<void, 0x02218A80, CompoundTag*, const mstd::wstring&, Tag*>()(this, str, tag);
        }

        void putByte(const mstd::wstring& str, uint8_t b) {
            code::Func<void, 0x0221acc8, CompoundTag*, const mstd::wstring&, uint8_t>()(this, str, b);
        }

        bool contains(const mstd::wstring& str) {
            return code::Func<bool, 0x02218400, CompoundTag*, const mstd::wstring&>()(this, str);
        }

        bool equals(Tag* tag) {
            return code::Func<bool, 0x0221c284, CompoundTag*, Tag*>()(this, tag);
        }

        void remove(const mstd::wstring& str) {
            code::Func<void, 0x0221be6c, CompoundTag*, const mstd::wstring&>()(this, str);
        } 

        ListTag* getList(const mstd::wstring& str, int unk) {
            return code::Func<ListTag*, 0x0221b99c, CompoundTag*, const mstd::wstring&, int>()(this, str, unk);
        }

        CompoundTag* getCompound(const mstd::wstring& str) {
            return code::Func<CompoundTag*, 0x02218350, CompoundTag*, const mstd::wstring&>()(this, str);
        }

        void getString(const mstd::wstring& ret, const mstd::wstring& str) {
            return code::Func<void, 0x02218874, CompoundTag*, const mstd::wstring&, const mstd::wstring&>()(this, ret, str);
        }

        void toString(const mstd::wstring& output_str) {
            code::Func<void, 0x0221c024, CompoundTag*, const mstd::wstring&>()(this, output_str);
        }

        int getInt(const mstd::wstring& str) {
            return code::Func<int, 0x0221b37c, CompoundTag*, const mstd::wstring&>()(this, str);
        }

        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t entries;
        uint32_t field_0x10;
        uint32_t field_0x14; 
        uint32_t field_0x18;

    };
}