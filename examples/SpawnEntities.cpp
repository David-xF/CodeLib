#include <code/code.h>

#include <minecraft/mc.h>
#include <xf/String.h>

mc::Vec3 getLookAt(float yaw, float pitch) {
    return mc::Vec3(
        fabs(sinf(degToRad(pitch - 90.0f))) * sinf(degToRad(yaw   - 180.0f)),
                                              sinf(degToRad(pitch - 180.0f)),
        fabs(sinf(degToRad(pitch - 90.0f))) * cosf(degToRad(yaw))
    );
}

mc::AreaEffectCloud* spawnHoloGram(mc::Vec3 pos, const wchar_t* name, mc::ServerPlayer* player) {
    mc::AreaEffectCloud* cloud = new mc::AreaEffectCloud(player->lvl);
    cloud->setupForSpawn(name, player);
    cloud->setCustomNameVisible(true);
    cloud->moveTo(pos.x, pos.y, pos.z, 0.0f, 0.0f);
    cloud->setParticle(mc::ParticleType::byId(mc::ePARTICLE_TYPE::NONE));
    cloud->setDuration(0x7FFF0000);
    cloud->setRadiusOnUse(0.0f);
    cloud->setRadiusPerTick(0.0f);
    cloud->setRadius(1.0f);
    player->listener->server->getLevel(0)->addEntity(cloud->this_shared);

    return cloud;
}

DECL_FUNCTION(void, ServerPlayer_swing, mc::ServerPlayer* player, mc::InteractionHand::EInteractionHand hand) {
    spawnHoloGram(player->position + mc::Vec3(0.0f, 1.0f / 3.0f + 1.5f, 5.0f), L"§bMinigame §7[v0.0]", player);
    spawnHoloGram(player->position + mc::Vec3(0.0f, 1.5f, 5.0f), L"§eCLICK TO PLAY", player);
    spawnHoloGram(player->position + mc::Vec3(0.0f, 1.5f, 0.0f), L"§8[§7Lv69§8] §cZombie §a100§7/§a100§cHP", player);

    mc::Zombie* zombie = new mc::Zombie(player->lvl);
    zombie->setupForSpawn(L"", player);
    zombie->setNoAi(true);
    zombie->setInvulnerable(true);
    zombie->setNoGravity(true);
    zombie->setSilent(true);
    zombie->moveTo(player->position, 0.0f, 0.0f);
    player->listener->server->getLevel(0)->addEntity(zombie->this_shared);

    mc::Zombie* zombie2 = new mc::Zombie(player->lvl);
    zombie2->setupForSpawn(L"", player);
    zombie2->setNoAi(true);
    zombie2->setInvulnerable(true);
    zombie2->setNoGravity(true);
    zombie2->setSilent(true);
    zombie2->moveTo(player->position + mc::Vec3(0.0f, 0.0f, 5.0f), 0.0f, 0.0f);
    player->listener->server->getLevel(0)->addEntity(zombie2->this_shared);

    mc::PrimedTnt* tnt = new mc::PrimedTnt(player->lvl);
    tnt->setupForSpawn(L"", player);
    tnt->setFuse(20 * 12); // 12 Seconds
    tnt->push(0.0f, 1.45f, 0.0f);
    tnt->moveTo(player->position, 0.0f, 0.0f);
    player->listener->server->getLevel(0)->addEntity(tnt->this_shared);

    mc::Sheep* sheep = new mc::Sheep(player->lvl);
    sheep->setupForSpawn(L"", player);
    sheep->setInvulnerable(true);
    sheep->moveTo(player->position, 0.0f, 0.0f);
    player->listener->server->getLevel(0)->addEntity(sheep->this_shared);
    
    sheep->startRiding(tnt->this_shared, false);
    
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