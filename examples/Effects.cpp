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

DECL_FUNCTION(void, ServerPlayer_tick, mc::ServerPlayer* player) {
    real_ServerPlayer_tick(player);

    mc::MobEffect* effect = mc::MobEffect::byId(1); // Speed
    if (!player->hasEffect(effect)) {
        mc::MobEffectInstance* effectInstance = new mc::MobEffectInstance(effect);
        effectInstance->amplifier = 0; // 0 = Level 1 | 1 = Level 2... 
        effectInstance->duration = 30 * 20; // 30 Seconds
        effectInstance->visible = false; // Not Visible

        // Must be ServerPlayer (NOT LocalPlayer)
        player->addEffect(effectInstance, nullptr);
        
        wchar_t temp[0xA0];
        mc_swprintf(temp, 0xA0, L"Gave you Effect %ls", getEffectName(effect->getId()));
        player->listener->send(new mc::ClientboundChatPacket(temp));
    }
}

int c_main(void*) {
    init();

    REPLACE(mc::ServerPlayer::_tick.addr(), ServerPlayer_tick);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}