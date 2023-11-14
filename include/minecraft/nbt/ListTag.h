#pragma once

#include "Tag.h"
#include "../client/resource/vector.h"
#include "../client/resource/wstring.h"

namespace mc {
    class ListTag : public Tag {
    public:
        ListTag(int i) {
            code::Func<void, 0x02573958, ListTag*, int>()(this, i);
        }

        void add(Tag* tag) {
            code::Func<void, 0x02573F8C, ListTag*, Tag*>()(this, tag);
        }

        void getString(int index, const mstd::wstring& str) {
            code::Func<void, 0x02590594, ListTag*, int, const mstd::wstring&>()(this, index, str);
        }

        int size() {
            return code::Func<int, 0x02574f24, ListTag*>()(this);
        }

        void toString(const mstd::wstring& output_str) {
            code::Func<void, 0x0258eee4, ListTag*, const mstd::wstring&>()(this, output_str);
        }

        mstd::vector<Tag*> tags;
        uint32_t maxSize; // I think
    };
}