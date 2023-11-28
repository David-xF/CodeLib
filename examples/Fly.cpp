#include <code/code.h>

#include <minecraft/mc.h>

DECL_FUNCTION(void, tick__11LocalPlayerFv, mc::LocalPlayer* lPlayer) {
    lPlayer->abilities.canFly = true;
}

int c_main(void*) {
    code::init();

    REPLACE(0x031e3a80, tick__11LocalPlayerFv);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}