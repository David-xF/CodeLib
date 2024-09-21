#pragma once

#include <code/code.h>
#include "./VTable_TelemetryManager.h"

namespace mc {
    class TelemetryManager {
    public:
		uint32_t field_0x0;
		uint32_t field_0x4;
		uint32_t field_0x8;
		uint32_t field_0xC;
		uint32_t field_0x10;
		uint32_t field_0x14;
		uint32_t field_0x18;
		uint32_t field_0x1C;
		uint32_t field_0x20;
		VTable_TelemetryManager* Vtbl;
    };
}