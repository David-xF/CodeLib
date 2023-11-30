#pragma once

#include "mem.h"
#include "Func.h"
#include "startup.h"
#include "Random.h"

#include "tcpgecko.h"
#include "wups.h"

#include <exports/exports.h>

namespace code {
	void init() {
	    InitTCPGecko();
	    InitWups();
	
	    // Remove Whatever you don't need (Will Reduce File Size)
	    InitSocketFunctionPointers();
	    InitKernelFunctionPointers();
	    InitVPadFunctionPointers();
	    InitMemoryFunctionPointers();
	    InitOSFunctionPointers();
	    InitGX2FunctionPointers();
	    InitLibCurlFunctionPointers();
	
	    memoryInitialize();
	}
}

#define WIDTH 640
#define HEIGHT 360

#define MC_CHECK_SIZE(type, size) static_assert(sizeof(mc::type) == size, #type " has invalid size.")

#define MC_VFUNC(return_type, class_type, function_name, ...)     \
	int flag_##function_name;                                     \
	return_type(*function_name)(class_type* _this, ##__VA_ARGS__)

#define DEFINE_STATIC_DEF_VAR(type, name, addr) \
	static inline type default_##name = (type) addr;

#define DEFINE_STATIC_VAR(type, name, addr) \
	static inline type name = (type) addr;

// WHEN CEMU IS DEFINED THE MC_LIB USES CEMU POINTERS	
#define CEMU