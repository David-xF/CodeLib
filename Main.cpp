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

    mc::ServerLevel* level = mc::MinecraftServer::getInstance()->getLevel(0);
    mc::Sheep* sheep = new mc::Sheep(player->lvl);
    sheep->registerGoals();
    sheep->moveTo(player->position.x, player->position.y, player->position.z, player->yaw, player->pitch);
    level->addEntity(sheep);
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