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

#include <xf/ItemInstanceHelper.h>

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

    mc::ItemInstance* item = player->inventory->getSelected().get();
    if (item->item == mc::Item::byId(387) && item->hasTag() && item->getCount() != 0) {
        mstd::wstring strTitle; 
        mstd::wstring strAuthor; 
        item->tag->getString(strTitle, L"title");
        item->tag->getString(strAuthor, L"author");

        item->setTag(new mc::CompoundTag());
        item->item = mc::Item::byId(386);

        wchar_t temp[0x40];
        mc_swprintf(temp, 0x40, L"%s%ls: %ls", player->isModerator() ? "[Moderator] " : "[Not Moderator] ", strAuthor.c_str(),  strTitle.c_str());

        for (mc_boost::shared_ptr<mc::ServerPlayer>& _player : mc::MinecraftServer::getInstance()->getPlayers()->players) {
            _player->listener->send(new mc::ClientboundChatPacket(temp));
            _player->listener->send(new mc::ClientboundSoundPacket(mc::SoundEvent::note_hat));
        }
                
        int isEmpty = item->getCount() == 0;
        if (item->item != mc::Item::byId(386) || isEmpty) {
            mc::ItemInstance* chat = new mc::ItemInstance(mc::Item::byId(386), 1);
            xf::ItemInstanceHelper::setName(chat, L"Book Chat");
            item->item = mc::Item::byId(0);
            item->count = 0;
            player->inventory->setItem(player->inventory->selectedSlot, chat);
        }
    }
}

int c_main(void*) {
    init();

    REPLACE(mc::ServerPlayer::_tick.addr(), ServerPlayer_tick);

    return 0;
}

// Gets Called once at startup
void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}