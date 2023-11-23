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

DECL_FUNCTION(void, ServerPlayer_Swing, mc::ServerPlayer* player, mc::InteractionHand::EInteractionHand eHand) {
    real_ServerPlayer_Swing(player, eHand);

    // Creates a Container with the Name "Menu" and sets its size to 27
    mc::SimpleContainer* cont = new mc::SimpleContainer(0, 0, L"Menu", 27);
    mc_boost::shared_ptr<mc::SimpleContainer> shared;
    // I don't know why this is needded, but it is
    mc::SimpleContainer::toShared(shared, cont);
    
    // Set every Item to Stone with the Amount of i + 1
    for (int i = 0; i < 27; i++) shared->setItem(i, new mc::ItemInstance(mc::Item::byId(1), i + 1));
    
    // Opens Container for Player (Must be ServerPlayer if you want it to work with other Players)
    player->openContainer(&shared->container);
}

int c_main(void*) {
    init();

    REPLACE(0x032d8b5c, ServerPlayer_Swing);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}