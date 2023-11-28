#include <code/code.h>

#include <minecraft/mc.h>
#include <xf/DrawHelper.h>

DECL_HOOK(onFrameInGame, void) {
    xf::GUI::DrawHelper::renderSetup();
    mc::Font* font = mc::Minecraft::getInstance()->defaultFonts;
    // Display "Hello World" at x = 5, y = 5, with color white [Format ARGB]
    xf::GUI::DrawHelper::DisplayText(font, L"Hello World", 1.0f, 5, 5, 0xFFFFFFFF);
}

DECL_HOOK(onFrameInMenu, void) {
    xf::GUI::DrawHelper::renderSetup();
    mc::Font* font = mc::Minecraft::getInstance()->defaultFonts;
    // Display "Hello World" at x = 5, y = 5, with color white [Format ARGB]
    xf::GUI::DrawHelper::DisplayText(font, L"Hello World", 1.0f, 5, 5, 0xFFFFFFFF);
}

int c_main(void*) {
    code::init();

    HOOK(0x02D9CAD0, onFrameInGame, 0);
    HOOK(0x02D9C8B0, onFrameInMenu, 0);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}