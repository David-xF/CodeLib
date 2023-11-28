#include <code/code.h>

#include <minecraft/mc.h>

// Works only as Host (Other People can also send Messages)
DECL_FUNCTION(void, ServerGamePacketListenerImpl_handleChat, mc::ServerGamePacketListenerImpl* listener, const mc_boost::shared_ptr<mc::ClientboundChatPacket>& packet) {
    if (packet->str_v[0].length == 0) return; // No Empty Message
    mstd::wstring msg = packet->str_v[0];
    memset((void*) &msg.c_str()[msg.length], 0x0, sizeof(wchar_t)); // I don't know why

    bool isOnlyWhiteSpace = true;
    for (int i = 0; i < msg.length; i++) {
        wchar_t _char = msg.c_str()[i];
        if (_char != L' ') {
            isOnlyWhiteSpace = false;
            break;
        }
    }

    if (isOnlyWhiteSpace) return; // No Empty Message

    wchar_t temp[150];
    mstd::wstring playerName;
    listener->player->getDisplayName(playerName);
    mc_swprintf(temp, 150, L"<%ls> %ls", playerName.c_str(), msg.c_str());
    mc::MinecraftServer::getInstance()->getPlayers()->broadcastAll(new mc::ClientboundChatPacket(temp));
    mc::MinecraftServer::getInstance()->getPlayers()->broadcastAll(new mc::ClientboundSoundPacket(mc::SoundEvent::note_hat, 1.0f, 1.0f));
}

void openKeyboard() {
    mc::CInput::GetInput()->RequestKeyboard(L"", L"", 0, 140, [](void*, bool) -> int {
        wchar_t temp[141];
        mc::CInput::GetInput()->GetText(temp, 141);

        mc::Minecraft::getInstance()->getConnection(0)->send(new mc::ClientboundChatPacket(temp));
        return 0; 
    }, nullptr, mc::CInput::KeyboardMode::FULL);
}

DECL_HOOK(onFrameInGame, void) {
    START_BUTTONCHECK(button & VPAD_BUTTON_RIGHT, openKeyboard(), button)
    END_BUTTONCHECK()
}

int c_main(void*) {
    code::init();

    REPLACE(mc::ServerGamePacketListenerImpl::_handleChat.addr(), ServerGamePacketListenerImpl_handleChat);
    HOOK(0x02D9CAD0, onFrameInGame, 0);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}