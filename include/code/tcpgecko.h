#pragma once

#include <inttypes.h>

#define EXPORT_DECL(res, func, ...) res(*func)(__VA_ARGS__) = 0;
#define EXPORT_VAR(type, var)       type var;

EXPORT_DECL(int, OSDynLoad_Acquire, const char* rpl, uint32_t* handle);
EXPORT_DECL(int, OSDynLoad_FindExport, uint32_t handle, int isData, const char* symbol, void* address);

#define EXPORT_FUNC_WRITE(func, val) *(uint32_t*)(((uint32_t)&func) + 0) = (uint32_t)val
#define OS_FIND_EXPORT(handle, func) funcPointer = 0;                                      \
                                     OSDynLoad_FindExport(handle, 0, #func, &funcPointer); \
                                     EXPORT_FUNC_WRITE(func, funcPointer);

#define MINECRAFT
//#define MARIO_KART

#ifdef MINECRAFT 
    #define AcquireAddress    0x038071E4
    #define FindExportAddress 0x038077B0
#elif ifdef MARIO_KART
    #define AcquireAddress    0x0249EAC8
    #define FindExportAddress 0x026789DC 
#else
    #define AcquireAddress    0x0
    #define FindExportAddress 0x0
#endif

int32_t targetAddr(uint32_t instructionAddress) {
    uint32_t instruction = code::Mem(instructionAddress).as<uint32_t>();
    int32_t li = instruction & 0x03FFFFFC;
    return (li & 0x02000000) ? (li - 0x04000000) : li;
}

void InitTCPGecko() {
    OSDynLoad_Acquire    = (int(*)(const char*, uint32_t*))            targetAddr(AcquireAddress);
    OSDynLoad_FindExport = (int(*)(uint32_t, int, const char*, void*)) targetAddr(FindExportAddress);
}