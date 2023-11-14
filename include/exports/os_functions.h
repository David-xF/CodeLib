#pragma once

#include <code/tcpgecko.h>

EXPORT_DECL(void, OSScreenInit, void);
EXPORT_DECL(void, OSScreenShutdown, void);
EXPORT_DECL(unsigned int, OSScreenGetBufferSizeEx, unsigned int bufferNum);
EXPORT_DECL(int, OSScreenSetBufferEx, unsigned int bufferNum, void *addr);
EXPORT_DECL(int, OSScreenEnableEx, unsigned int bufferNum, int enable);
EXPORT_DECL(int, OSScreenClearBufferEx, unsigned int bufferNum, unsigned int temp);
EXPORT_DECL(int, OSScreenPutFontEx, unsigned int bufferNum, unsigned int posX, unsigned int posY, const char *buffer);
EXPORT_DECL(int, OSScreenFlipBuffersEx, unsigned int bufferNum);

EXPORT_DECL(int, OSCreateThread, void *thread, int(*callback)(int, void * ), int argc, void *args, uint32_t stack, uint32_t stack_size, int priority, uint32_t attr);
EXPORT_DECL(int, OSResumeThread, void *thread);

EXPORT_DECL(void, OSConsoleWrite, const char* msg, int size);

EXPORT_DECL(int, MCP_Open, void);
EXPORT_DECL(int, MCP_GetDeviceId, int handle, uint64_t* devideId);
EXPORT_DECL(int, MCP_Close, int handle);

EXPORT_DECL(void, OSSetExceptionCallback, uint8_t exceptionType, uint8_t(*callback)(void*));

#define PRINTF_TEXT(x, y, ...) {                   \
        snprintf(messageBuffer, 80, __VA_ARGS__);  \
        OSScreenPutFontEx(0, x, y, messageBuffer); \
        OSScreenPutFontEx(1, x, y, messageBuffer); \
    } 
#define PRINT_TEXT(x, y, message) {                \
        OSScreenPutFontEx(0, x, y, message);       \
        OSScreenPutFontEx(1, x, y, message);       \
    } 

#define OS_THREAD_ATTR_AFFINITY_NONE    0x0007u        // affinity to run on every core
#define OS_THREAD_ATTR_AFFINITY_CORE0   0x0001u        // run only on core0
#define OS_THREAD_ATTR_AFFINITY_CORE1   0x0002u        // run only on core1
#define OS_THREAD_ATTR_AFFINITY_CORE2   0x0004u        // run only on core2
#define OS_THREAD_ATTR_DETACH           0x0008u        // detached
#define OS_THREAD_ATTR_PINNED_AFFINITY  0x0010u        // pinned (affinitized) to a single core
#define OS_THREAD_ATTR_CHECK_STACK_USE  0x0040u        // check for stack usage
#define OS_THREAD_ATTR_NAME_SENT        0x0080u        // debugger has seen the name
#define OS_THREAD_ATTR_LAST             (OS_THREAD_ATTR_DETACH | OS_THREAD_ATTR_PINNED_AFFINITY | OS_THREAD_ATTR_AFFINITY_NONE)


void InitOSFunctionPointers() {
    uint32_t coreinit_handle;
    uint32_t* funcPointer = 0;
    OSDynLoad_Acquire("coreinit.rpl", &coreinit_handle);
    OS_FIND_EXPORT(coreinit_handle, OSScreenInit);
	OS_FIND_EXPORT(coreinit_handle, OSScreenShutdown);
	OS_FIND_EXPORT(coreinit_handle, OSScreenGetBufferSizeEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenSetBufferEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenEnableEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenClearBufferEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenPutFontEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenFlipBuffersEx);

    OS_FIND_EXPORT(coreinit_handle, OSCreateThread);
    OS_FIND_EXPORT(coreinit_handle, OSResumeThread);

    OS_FIND_EXPORT(coreinit_handle, OSConsoleWrite);

    OS_FIND_EXPORT(coreinit_handle, MCP_Open);
    OS_FIND_EXPORT(coreinit_handle, MCP_GetDeviceId);
    OS_FIND_EXPORT(coreinit_handle, MCP_Close);

    OS_FIND_EXPORT(coreinit_handle, OSSetExceptionCallback);
}