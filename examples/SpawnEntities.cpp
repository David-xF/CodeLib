#include <code/code.h>

#include <minecraft/mc.h>

mc::Vec3 getLookAt(float yaw, float pitch) {
    return mc::Vec3(
        fabs(sinf(degToRad(pitch - 90.0f))) * sinf(degToRad(yaw   - 180.0f)),
                                              sinf(degToRad(pitch - 180.0f)),
        fabs(sinf(degToRad(pitch - 90.0f))) * cosf(degToRad(yaw))
    );
}

mc::PrimedTnt* spawnTnt(mc::ServerPlayer* player) {
    mc::PrimedTnt* tnt = new mc::PrimedTnt(player->lvl);
    mstd::wstring pUID;
    player->getStringUUID(pUID);
    tnt->setCustomName(L"aabbccdd", pUID, true);

    uint32_t* idk = new uint32_t[4];
    idk[0] = 1;
    idk[1] = 1;
    idk[2] = mc::PrimedTnt::default_something_important_with_spawning;
    idk[3] = (uint32_t) tnt;
    tnt->_this_ptr = mc_boost::shared_ptr<mc::Entity>(tnt, (uint32_t) idk);

    return tnt;
}  

DECL_FUNCTION(void, ServerPlayer_swing, mc::ServerPlayer* player, mc::InteractionHand::EInteractionHand hand) {
    // No Comments on this one Because i don't know either tbh
    mc::PrimedTnt* tnt = spawnTnt(player);
    tnt->moveTo(player->position.x, player->position.y, player->position.z, 0.0f, 0.0f);
    mc::Vec3 push = getLookAt(player->yaw, player->pitch);
    push *= 3.0f;
    push.y /= 2.0f;
    tnt->push(push.x, push.y, push.z);

    player->listener->server->getLevel(0)->addEntity(tnt->_this_ptr);
    player->startRiding(tnt->_this_ptr);

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

        player->listener->server->getLevel(0)->addEntity(_tnt->_this_ptr);
    }

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