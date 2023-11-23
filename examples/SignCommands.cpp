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

DECL_FUNCTION(bool, executeClickCommands__15SignBlockEntityFQ2_5boost25shared_ptr__tm__8_6Player, mc::SignBlockEntity* sign, mc_boost::shared_ptr<mc::Player> player) {
    mc::ServerPlayer* sPlayer = nullptr;;
    for (mc_boost::shared_ptr<mc::ServerPlayer>& s_player : mc::MinecraftServer::getInstance()->getPlayers()->players) {
        if (player->colourIndex == s_player->colourIndex) {
            sPlayer = s_player.get();
        }
    }

    if (!sPlayer) return true;
    
    // What to do when the Sign gets clicked

    return true;
}

int c_main(void*) {
    init();

    REPLACE(mc::SignBlockEntity::_executeClickCommands.addr(), executeClickCommands__15SignBlockEntityFQ2_5boost25shared_ptr__tm__8_6Player);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}