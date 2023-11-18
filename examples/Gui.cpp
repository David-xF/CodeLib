#include <code/code.h>

#include <code/tcpgecko.h>
#include <code/wups.h>

#include <exports/curl_functions.h>
#include <exports/socket_functions.h>
#include <exports/vpad_functions.h>
#include <exports/gx2_functions.h>
#include <exports/kernel.h>
#include <exports/os_functions.h>
#include <exports/memory.h>

#include <minecraft/mc.h>

#include <xf/DrawHelper.h>

void init() {
    InitTCPGecko();
    InitWups();

    InitSocketFunctionPointers();
    InitKernelFunctionPointers();
    InitVPadFunctionPointers();
    InitMemoryFunctionPointers();
    InitOSFunctionPointers();
    InitGX2FunctionPointers();
    InitLibCurlFunctionPointers();

    memoryInitialize();
}

DECL_HOOK(onFrameInGame, void) {
    xf::GUI::DrawHelper::renderSetup();
    mc::Font* font = mc::Minecraft::getInstance()->defaultFonts;
    xf::GUI::DrawHelper::DisplayText(font, L"Hello World", 1.0f, 5, 5, 0xFFFFFFFF);
}

DECL_HOOK(onFrameInMenu, void) {
    xf::GUI::DrawHelper::renderSetup();
    mc::Font* font = mc::Minecraft::getInstance()->defaultFonts;
    xf::GUI::DrawHelper::DisplayText(font, L"Hello World", 1.0f, 5, 5, 0xFFFFFFFF);
}

int c_main(void*) {
    init();

    HOOK(0x02D9CAD0, onFrameInGame, 0);
    HOOK(0x02D9C8B0, onFrameInMenu, 0);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}