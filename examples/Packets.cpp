#include <code/code.h>

#include <minecraft/mc.h>

void packets() {
    mc::ClientPacketListener* listener = mc::Minecraft::getInstance()->getConnection(0);
    // This also works: mc::ClientPacketListener* listener = mc::Minecraft::getInstance()->thePlayer->listener;

    // Packets get Deleted Automatically after Sending!

    // Sends a Move Player Packet with Position (25, 30, 35) and Yaw/Pitch 180/90 while being on a Block and not Flying
    listener->send(new mc::ServerboundMovePlayerPacket(25, 30, 35, 180, 90, true, false));
}

DECL_HOOK(onFrameInGame, void) {
    START_BUTTONCHECK(button & VPAD_BUTTON_RIGHT, packets(), button)
    END_BUTTONCHECK()
}

int c_main(void*) {
    code::init();

    HOOK(0x02D9CAD0, onFrameInGame, 0);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}