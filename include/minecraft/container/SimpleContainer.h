#pragma once

#include <code/code.h>

#include "../client/resource/wstring.h"
#include "../client/resource/shared_ptr.h"
#include "../client/resource/vector.h"

#include "Container.h"

namespace mc {
    class SimpleContainer {
    public:
        SimpleContainer(int unk_0x0, int unk_0x1, const mstd::wstring& str, int size) {
            code::Func<void, 0x028f39dc, SimpleContainer*, int, int, const mstd::wstring&, int>()(this, unk_0x0, unk_0x1, str, size);
        }

        SimpleContainer() = default;

        static void toShared(const mc_boost::shared_ptr<SimpleContainer>& ret, SimpleContainer* src) {
            code::Func<void, 0x3065EE0, const mc_boost::shared_ptr<SimpleContainer>&, SimpleContainer*>()(ret, src);
        }

        void getItem(uint32_t slot, mc_boost::shared_ptr<struct ItemInstance> const & item) {
            code::Func<void, 0x028DCB78, SimpleContainer*, mc_boost::shared_ptr<struct ItemInstance> const &, uint32_t>()(this, item, slot);
        }

        void addItem(int slot, mc_boost::shared_ptr<struct ItemInstance> const & item) {
            code::Func<void, 0x028f4200, SimpleContainer*, int, mc_boost::shared_ptr<struct ItemInstance> const &>()(this, slot, item);
        }

        void setItem(int slot, mc_boost::shared_ptr<struct ItemInstance> const & item) {
            code::Func<void, 0x028DD3C8, SimpleContainer*, int, mc_boost::shared_ptr<struct ItemInstance> const &>()(this, slot, item);
        }

        void clearContent() {
            code::Func<void, 0x028DD90C, SimpleContainer*>()(this);
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
        uint32_t maxSlots; // I think
        uint32_t field_0x30;
        uint32_t field_0x34;
        mstd::vector<void*> listeners; // net_minecraft_ContainerListener*
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
        Container container;
    };
}