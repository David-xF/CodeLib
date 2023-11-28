#include <code/code.h>

#include <minecraft/mc.h>

DECL_FUNCTION(void, ServerPlayerGameMode_breakBlock, mc::ServerPlayerGameMode* gameMode, const mc::BlockPos& pos) {
    mc_boost::shared_ptr<mc::ServerPlayer> player;
    gameMode->getServerPlayer(player);
    
    mc::ServerLevel* level = mc::MinecraftServer::getInstance()->getLevel(0);
    int radius = 1;
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            for (int z = -radius; z <= radius; z++) {
                // Send an Update Packet back to let the Player know that the block is still there
                mc_boost::shared_ptr<mc::Packet> packet(new mc::ClientboundBlockUpdatePacket(level, {pos.x + x, pos.y + y, pos.z + z}));
                player->listener->send(packet);
            }
        }
    }

    // No real_ServerPlayerGameMode_breakBlock Because we don't want to break the Block (It gets Canceled)
}

int c_main(void*) {
    code::init();

    REPLACE(mc::ServerPlayerGameMode::_destroyBlock.addr(), ServerPlayerGameMode_breakBlock);
    
    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}