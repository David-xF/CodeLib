#include <code/code.h>

#include <minecraft/mc.h>
#include <xf/DrawHelper.h>
#include <xf/String.h>

uint32_t startAddr = 0x02000000;
bool isShowing = false;

void displayCheck() {
    START_BUTTONCHECK(button & VPAD_BUTTON_RIGHT, isShowing = !isShowing, button)
    ADD_BUTTONCHECK(button & VPAD_BUTTON_LEFT, mc::CInput::GetInput()->RequestKeyboard(L"", xf::WString::intToHexStr(startAddr).c_str(), 0, 8, [](void*, bool) -> int {
        wchar_t temp[9];
        mc::CInput::GetInput()->GetText(temp, 9);

        uint32_t addr = xf::WString::hexStrToInt(temp);
        addr /= 0x10;
        addr *= 0x10;
        startAddr = addr;
        
        return 0;
    }, nullptr, mc::CInput::KeyboardMode::FULL))
    END_BUTTONCHECK()
}

void scrollCheck() {
    START_TIMED_BUTTONCHECK(button & VPAD_BUTTON_DOWN, startAddr += 0x10, button, 200, 30)
    ADD_TIMED_BUTTONCHECK(button & VPAD_BUTTON_UP, startAddr -= 0x10)
    END_TIMED_BUTTONCHECK()

    if (0x02000000 > startAddr) startAddr = 0x02000000;
}

void memoryViewer() {
    displayCheck();
    scrollCheck();
    if (isShowing) {
        xf::GUI::DrawHelper::renderSetup();
        mc::Font* font = mc::Minecraft::getInstance()->defaultFonts;
        xf::GUI::DrawHelper::DisplayText(font, L"Address", 1.0f, 5.0f, 5.0f);

        const float space = 13.0f;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 5; j++) {
                wchar_t temp[0x40];
                mc_swprintf(temp, 0x40, L"%08X", j == 0 ? startAddr + (i * 0x10) : code::Mem(startAddr + (j * 0x4) - 0x4 + (i * 0x10)).as<uint32_t>());
                xf::GUI::DrawHelper::DisplayText(font, temp, 1.0f, 5.0f + (j * 70.0f), 5.0f + space + (space * i));
            }
        }

        xf::Vector<mstd::pair<const wchar_t*, void*>> vec = { {L"LocalPlayer*", 0x0}, {L"Minecraft*", 0x0}, {L"Level*", 0x0} };
        mc::Minecraft* minecraft = mc::Minecraft::getInstance();
        vec[0].t2 = minecraft->thePlayer;
        vec[1].t2 = minecraft;
        vec[2].t2 = minecraft->thePlayer->lvl;

        float yOffset = 0;
        for (mstd::pair<const wchar_t*, void*>& pair : vec){
            wchar_t temp[0x40];
            mc_swprintf(temp, 0x40, L"%08X", pair.t2);
            xf::GUI::DrawHelper::DisplayText(font, pair.t1, 1.0f, WIDTH - (WIDTH * (12.0f / 100.0f)), 5 + yOffset);
            xf::GUI::DrawHelper::DisplayText(font, temp, 1.0f, WIDTH - (WIDTH * (12.0f / 100.0f)), 5 + yOffset + space);
            yOffset += space * 3.0f;
        }
    }
}

DECL_HOOK(onFrameInGame, void) {
    memoryViewer();
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