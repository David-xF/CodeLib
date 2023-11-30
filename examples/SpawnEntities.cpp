#include <code/code.h>

#include <minecraft/mc.h>

mc::Vec3 getLookAt(float yaw, float pitch) {
    return mc::Vec3(
        fabs(sinf(degToRad(pitch - 90.0f))) * sinf(degToRad(yaw   - 180.0f)),
                                              sinf(degToRad(pitch - 180.0f)),
        fabs(sinf(degToRad(pitch - 90.0f))) * cosf(degToRad(yaw))
    );
}

DECL_FUNCTION(void, ServerPlayer_swing, mc::ServerPlayer* player, mc::InteractionHand::EInteractionHand hand) {
    mc::PrimedTnt* prevTnt = nullptr;
    for (int i = 0; i < 20; i++) {
        // Create a new Entity
        mc::PrimedTnt* tnt = new mc::PrimedTnt(player->lvl);

        // Setup to be Spawned
        tnt->setupForSpawn(L"", player);

        // Move to the Player
        tnt->moveTo(player->position.x, player->position.y, player->position.z, 0.0f, 0.0f);
        
        // Add to ServerLevel (must be ServerLevel (Host Only))
        player->listener->server->getLevel(0)->addEntity(tnt->this_shared);
        
        if (prevTnt == nullptr) {
            mc::Vec3 motion = getLookAt(player->yaw, player->pitch) * (4.0f / 3.0f);
            tnt->push(motion.x, motion.y, motion.z);
        } else {
            tnt->startRiding(prevTnt->this_shared, false);
        } 

        prevTnt = tnt;
    }

    player->startRiding(prevTnt);
   
    real_ServerPlayer_swing(player, hand);
}

int c_main(void*) {
    code::init();

    REPLACE(mc::ServerPlayer::_swing.addr(), ServerPlayer_swing);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}