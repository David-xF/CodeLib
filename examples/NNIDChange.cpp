#include <code/code.h>

#include <minecraft/mc.h>

int swkbd_callback(void* data, bool unk) {
    wchar_t* nnidAddr = (wchar_t*) data;
    wchar_t buff[17];
    mc::CInput::GetInput()->GetText(buff, 17);

    // Override the NNID Address, with input from Keyboard
    mc_swprintf(nnidAddr, 17, L"%ls", buff);
    mc_printf(L"[NNID] Changed NNID to %ls", buff);
    return 0;
}

void openNNIDChangeKeyboard() {
    wchar_t* nnidAddr = getNNID();
    mc::CInput::GetInput()->RequestKeyboard(L"", nnidAddr, 0, 16, swkbd_callback, nnidAddr, mc::CInput::KeyboardMode::NNID);
}

DECL_HOOK(onFrameInGame, void) {
    START_BUTTONCHECK(button & VPAD_BUTTON_RIGHT, openNNIDChangeKeyboard(), button)
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