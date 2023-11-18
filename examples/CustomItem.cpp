#include <code/code.h>

#include <code/tcpgecko.h>
#include <code/wups.h>

#include <exports/curl_functions.h>
#include <exports/socket_functions.h>
#include <exports/vpad_functions.h>
#include <exports/gx2_functions.h>
#include <exports/kernel.h>
#include <exports/os_functions.h>
#include <exports/memory.h>

#include <minecraft/mc.h>

void init() {
    InitTCPGecko();
    InitWups();

    InitSocketFunctionPointers();
    InitKernelFunctionPointers();
    InitVPadFunctionPointers();
    InitMemoryFunctionPointers();
    InitOSFunctionPointers();
    InitGX2FunctionPointers();
    InitLibCurlFunctionPointers();

    memoryInitialize();
}

namespace mc {
    VTable_Item* TestItem_default_vtbl;
    class TestItem : public BowItem {
    public:
        TestItem() : BowItem() {
            if (!TestItem_default_vtbl) {
                TestItem_default_vtbl = (VTable_Item*) new uint8_t[sizeof(VTable_Item)];
                memcpy(TestItem_default_vtbl, BowItem::default_vtbl, sizeof(VTable_Item));
                writeMem(((uint32_t) TestItem_default_vtbl + offsetof(VTable_Item, releaseUsing)), (uint32_t) ((void*) &TestItem::_releaseUsing));
                TestItem_default_vtbl->releaseUsing = &TestItem::_releaseUsing;
            }

            vtbl = TestItem_default_vtbl;
            wchar_t _iconName[0x40];
            mc_swprintf(_iconName, 0x40, L"%ls", Item::byId(BowItem::default_itemId)->iconName.c_str());
            iconName = _iconName;
        }

        static void _releaseUsing(mc::Item* _this, const mc_boost::shared_ptr<struct ItemInstance>& instance, struct Level* level, const mc_boost::shared_ptr<struct LivingEntity>& entity, int duration) {
            mc_printf(L"Release Using");
        }
    };
}

DECL_FUNCTION(void, MinecraftWorld_RunStaticCtors__Fv, void) {
    real_MinecraftWorld_RunStaticCtors__Fv();
    mc::ResourceLocation loc(L"modded", L"custom_item");
    mc::TestItem* testItem = new mc::TestItem();
    mc::Item::registerItem(1, loc, testItem);
}

int c_main(void*) {
    init();

    REPLACE(0x026112C0, MinecraftWorld_RunStaticCtors__Fv);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}