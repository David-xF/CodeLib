#pragma once

#include "VTable.h"

#include "../client/resource/shared_ptr.h"
#include "../util/InteractionHand.h"
#include "./TelemetryManager.h"

namespace mc {
    struct VTable_TelemetryManager : public VTable {
    public:
	
        MC_VFUNC(void,         struct TelemetryManager, __dt);
        MC_VFUNC(void,         struct TelemetryManager, Init);
        MC_VFUNC(void,         struct TelemetryManager, Tick);
        MC_VFUNC(void,         struct TelemetryManager, Flush);
        MC_VFUNC(void,         struct TelemetryManager, RecordPlayerSessionStart);
        MC_VFUNC(void,         struct TelemetryManager, RecordPlayerSessionExit);
        MC_VFUNC(void,         struct TelemetryManager, RecordHeartBeat);
        MC_VFUNC(void,         struct TelemetryManager, RecordLevelStart);
        MC_VFUNC(void,         struct TelemetryManager, RecordLevelExit);
        MC_VFUNC(void,         struct TelemetryManager, RecordLevelSaveOrCheckpoint);
        MC_VFUNC(void,         struct TelemetryManager, RecordLevelResume);
        MC_VFUNC(void,         struct TelemetryManager, RecordPauseOrInactive);
        MC_VFUNC(void,         struct TelemetryManager, RecordUnpauseOrActive);
        MC_VFUNC(void,         struct TelemetryManager, RecordMenuShown, uint32_t, uint32_t, uint32_t);
        MC_VFUNC(void,         struct TelemetryManager, RecordAchievementUnlocked);
        MC_VFUNC(void,         struct TelemetryManager, RecordMediaShareUpload);
        MC_VFUNC(void,         struct TelemetryManager, RecordUpsellPresented);
        MC_VFUNC(void,         struct TelemetryManager, RecordUpsellResponded);
    };
}