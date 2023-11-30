#include <code/code.h>

#include <minecraft/mc.h>

mc::Vec3 getLookAt(float yaw, float pitch) {
    return mc::Vec3(
        fabs(sinf(degToRad(pitch - 90.0f))) * sinf(degToRad(yaw   - 180.0f)),
                                              sinf(degToRad(pitch - 180.0f)),
        fabs(sinf(degToRad(pitch - 90.0f))) * cosf(degToRad(yaw))
    );
}

// Spawn PrimedTnt
mc::PrimedTnt* spawnTnt(mc::ServerPlayer* player) {
    // Create a new PrimedTnt Instance
    mc::PrimedTnt* tnt = new mc::PrimedTnt(player->lvl);
    
    // Its Important i think
    mstd::wstring playerUUID;
    player->getStringUUID(playerUUID);
    // aabbccdd is the name of the Entity, Change it if you want no name or something else
    tnt->setCustomName(L"aabbccdd", playerUUID, true);

    // Also Important
    uint32_t* idk = new uint32_t[4];
    idk[0] = 1; // idk 1
    idk[1] = 1; // idk 2
    idk[2] = (uint32_t) mc::Entity::spawn_entity_vtbl; // I don't know what this is and where to get this from. 
    idk[3] = (uint32_t) tnt;
    tnt->this_shared = mc_boost::shared_ptr<mc::Entity>(tnt, (uint32_t) idk);

    // This could crash. I didn't test it Properly and the First time it crashed me so idk
    tnt->setFuse(20 * 10); // 10 Seconds

    return tnt;
}  

DECL_FUNCTION(void, ServerPlayer_swing, mc::ServerPlayer* player, mc::InteractionHand::EInteractionHand hand) {
    // No Comments on this one Because i don't know either tbh
    mc::PrimedTnt* tnt = spawnTnt(player);

    // Move the PrimedTnt to the Position of the Players Eyes
    tnt->moveTo(player->position.x, player->position.y, player->position.z, 0.0f, 0.0f);
    
    // Push the PrimedTnt into the Direction the Player is Looking
    mc::Vec3 push = getLookAt(player->yaw, player->pitch);
    push *= 3.0f;
    push.y /= 2.0f;
    tnt->push(push.x, push.y, push.z);

    // Add the PrimedTnt to the ServerLevel 
    player->listener->server->getLevel(0)->addEntity(tnt->this_shared);

    // Make the Player ride the PrimedTnt
    player->startRiding(tnt->this_shared);

    // Spawn 20 PrimedTnts around the Player (No Explaination here)
    const int count = 20;
    const float yaw = 360.0f / mc::toFloat(count);
    for (int i = 0; i < count; i++) {
        mc::Vec3 pos = getLookAt(yaw * i, 0.0f);
        pos = pos + player->position;

        mc::PrimedTnt* _tnt = spawnTnt(player);
        _tnt->moveTo(pos.x, pos.y, pos.z, 0.0f, 0.0f);
        mc::Vec3 _push = getLookAt(yaw * i, -35.0f);
        _push *= 2.0f;
        _tnt->push(_push.x, _push.y, _push.z);

        player->listener->server->getLevel(0)->addEntity(_tnt->this_shared);
    }

    // Make the Player swing the Hand;
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