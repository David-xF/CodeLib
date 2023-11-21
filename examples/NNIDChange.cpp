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

int swkbd_callback(void* data, bool unk) {
    wchar_t* nnidAddr = (wchar_t*) data;
    wchar_t buff[17];
    mc::CInput::GetInput()->GetText(buff, 17);

    mc_swprintf(nnidAddr, 17, L"%ls", buff);
    mc_printf(L"[NNID] Changed NNID to %ls", buff);
    return 0;
}

void openNNIDChangeKeyboard() {
    wchar_t* nnidAddr = getNNID();
    mc::CInput::GetInput()->RequestKeyboard(L"", nnidAddr, 0, 16, swkbd_callback, nnidAddr, mc::CInput::KeyboardMode::NNID);
}

DECL_HOOK(onFrameInGame, void) {
    START_BUTTONCHECK(button & VPAD_BUTTON_RIGHT, openNNIDChangeKeyboard, button)
    END_BUTTONCHECK()
}

int c_main(void*) {
    init();

    HOOK(0x02D9CAD0, onFrameInGame, 0);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}