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

DECL_FUNCTION(void, ServerPlayerGameMode_breakBlock, mc::ServerPlayerGameMode* gameMode, const mc::BlockPos& pos) {
    mc_boost::shared_ptr<mc::ServerPlayer> player;
    gameMode->getServerPlayer(player);
    
    mc::ServerLevel* level = mc::MinecraftServer::getInstance()->getLevel(0);
    int radius = 1;
    for (int x = -radius; x < (radius + 1); x++) {
        for (int y = -radius; y < (radius + 1); y++) {
            for (int z = -radius; z < (radius + 1); z++) {
                // Send an Update Packet back to let the Player know that the block is still there
                mc_boost::shared_ptr<mc::Packet> packet(new mc::ClientboundBlockUpdatePacket(level, {pos.x + x, pos.y + y, pos.z + z}));
                player->listener->send(packet);
            }
        }
    }
}

int c_main(void*) {
    init();

    REPLACE(mc::ServerPlayerGameMode::_destroyBlock.addr(), ServerPlayerGameMode_breakBlock);
    
    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}