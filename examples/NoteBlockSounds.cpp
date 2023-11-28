#include <code/code.h>

#include <minecraft/mc.h>

void playSound(mc::SoundEvent* sound, int pitch) {
    if (pitch == -1) return;
    
    mstd::wstring name;
    sound->getName(name);
    mc_printf(L"Played Sound %ls with Pitch %d", name.c_str(), pitch);
    for (mc_boost::shared_ptr<mc::Player>& player : mc::Minecraft::getInstance()->thePlayer->lvl->players) {
        if (player->uuid == mc::Minecraft::getInstance()->thePlayer->uuid) {
            mc::Minecraft::getInstance()->thePlayer->playSound(sound, 1.0f, mc::SoundEvent::getNoteBlockPitch(pitch));
        } else {
            mc::Minecraft::getInstance()->getConnection(0)->send(new mc::ClientboundSoundPacket(sound, mc::SoundSource::noteblock, player->position.x, player->position.y, player->position.z, 1.0f, mc::SoundEvent::getNoteBlockPitch(pitch)));
        }
    }
}

int playNoteBlockThread(void*) {
    uint64_t lastTime = mc::System::processTimeInMilliSecs();
    const float timeBetweenSound = 0.25f;

    // -1 = No Sound
    const int totalSounds = 29;
    int wood[totalSounds] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int wool[totalSounds] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int dirt[totalSounds] = { 6,  8, 10,  6,  6,  8, 10,  6, 10, 11, 13, -1, 10, 11, 13, -1, 13, 15, 13, 11, 10,  6, -1, 13, 15, 13, 11, 10,  6};

    int currSoundIndex = 0;
    while (true) {
        uint64_t currTime = mc::System::processTimeInMilliSecs();
        float deltaTime = mc::toFloat(currTime - lastTime) / 1000.0f;
        if (deltaTime >= timeBetweenSound) {
            lastTime = currTime;

            playSound(mc::SoundEvent::note_bassattack, wood[currSoundIndex]);
            playSound(mc::SoundEvent::block_note_guitar, wool[currSoundIndex]);
            playSound(mc::SoundEvent::note_harp, dirt[currSoundIndex]);

            currSoundIndex++;
            if (totalSounds == currSoundIndex) break;
        }
    }

    return 0;
}

DECL_FUNCTION(void, LocalPlayer_swing, mc::LocalPlayer* player, mc::InteractionHand::EInteractionHand hand) {
    real_LocalPlayer_swing(player, hand);

    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(playNoteBlockThread, nullptr, "Note Block Thread", 0x200);
    thread->Run(),
    thread->SetDeleteOnExit(true);
}

int c_main(void*) {
    code::init();

    REPLACE(mc::LocalPlayer::_swing.addr(), LocalPlayer_swing);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}