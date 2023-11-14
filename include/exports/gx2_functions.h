#pragma once

#include <code/tcpgecko.h>

EXPORT_DECL(void, GX2WaitForVsync, void);

void InitGX2FunctionPointers(void) {
    unsigned int* funcPointer = 0;
    uint32_t gx2_handle;
    OSDynLoad_Acquire("gx2.rpl", &gx2_handle);
    OS_FIND_EXPORT(gx2_handle, GX2WaitForVsync);
}