#include <code/code.h>
#include <minecraft/mc.h>

int c_main(void*) {
    // Init Export Functions and other Stuff
    code::init();

    // Your Code here gets executed in a thread

    return 0;
}

// Gets Called once at startup
void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}