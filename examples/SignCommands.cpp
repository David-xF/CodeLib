#include <code/code.h>

#include <minecraft/mc.h>

DECL_FUNCTION(bool, executeClickCommands__15SignBlockEntityFQ2_5boost25shared_ptr__tm__8_6Player, mc::SignBlockEntity* sign, mc_boost::shared_ptr<mc::Player> player) {
    mc::ServerPlayer* sPlayer = nullptr;;
    for (mc_boost::shared_ptr<mc::ServerPlayer>& s_player : mc::MinecraftServer::getInstance()->getPlayers()->players) {
        if (player->colourIndex == s_player->colourIndex) {
            sPlayer = s_player.get();
        }
    }

    if (!sPlayer) return true;
    
    // What to do when the Sign gets clicked
    sPlayer->listener->send(new mc::ClientboundChatPacket(sign->line1));
    sPlayer->listener->send(new mc::ClientboundChatPacket(sign->line2));
    sPlayer->listener->send(new mc::ClientboundChatPacket(sign->line3));
    sPlayer->listener->send(new mc::ClientboundChatPacket(sign->line4));

    return true;
}

int c_main(void*) {
    code::init();

    REPLACE(mc::SignBlockEntity::_executeClickCommands.addr(), executeClickCommands__15SignBlockEntityFQ2_5boost25shared_ptr__tm__8_6Player);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}