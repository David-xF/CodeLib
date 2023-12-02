#pragma once

#include <code/code.h>

#include "../../../client/resource/wstring.h"
#include "../../../client/resource/vector.h"

#include "../Packet.h"
#include "../../../util/Other.h"

namespace mc {
    class ClientboundChatPacket : public Packet {
    public:
        ClientboundChatPacket(const mstd::wstring& str) {
            uint32_t temp[20]; 
            code::Func<void, 0x021b7408, ClientboundChatPacket*, const mstd::wstring&, uint32_t[], int>()(this, str, temp, 0x46);
        }

        template<typename... Args>
        ClientboundChatPacket(const mstd::wstring& str, Args... args) {
            wchar_t _temp[0xA0];
            mc_swprintf(_temp, 0xA0, str.c_str(), args...);
            uint32_t temp[20];
            code::Func<void, 0x021b7408, ClientboundChatPacket*, const mstd::wstring&, uint32_t[], int>()(this, _temp, temp, 0x46);
        }

        mstd::vector<mstd::wstring> str_v;
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
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
        uint32_t field_0x5C;
        uint32_t field_0x60;
        uint32_t field_0x64;
    };
}