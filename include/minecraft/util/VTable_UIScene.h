#pragma once

#include "VTable.h"

#include "../client/resource/shared_ptr.h"
#include "../util/InteractionHand.h"
#include "../util/BlockPos.h"

namespace mc {
    struct VTable_UIScene : public VTable {
    public:
	
        MC_VFUNC(void,         struct UIScene, reloadMovie);
        MC_VFUNC(void,         struct UIScene, needsReloaded);
        MC_VFUNC(void,         struct UIScene, hasMovie);
        MC_VFUNC(void,         struct UIScene, updateSafeZone);
        MC_VFUNC(void,         struct UIScene, updateViewportTouchOffset);
        MC_VFUNC(void,         struct UIScene, getSafeZoneHalfHeight);
        MC_VFUNC(void,         struct UIScene, getSafeZoneHalfWidth);
        MC_VFUNC(void,		   struct UIScene, getMoviePath, mstd::wstring&);
        MC_VFUNC(bool,         struct UIScene, mapElementsAndNames);
        MC_VFUNC(void,         struct UIScene, __dt);
        MC_VFUNC(int,          struct UIScene, getSceneType);
        MC_VFUNC(uint32_t,     struct UIScene, getSubSceneType);
        MC_VFUNC(void,         struct UIScene, tick);
        MC_VFUNC(void,         struct UIScene, SetFocusToElement);
        MC_VFUNC(void,         struct UIScene, handleTimerComplete);
        MC_VFUNC(void,         struct UIScene, stealsFocus);
        MC_VFUNC(void,         struct UIScene, hasFocus);
        MC_VFUNC(void,         struct UIScene, updateTooltips);
        MC_VFUNC(void,         struct UIScene, updateComponents);
        MC_VFUNC(void,         struct UIScene, handleGainFocus);
        MC_VFUNC(void,         struct UIScene, handleLoseFocus);
        MC_VFUNC(void,         struct UIScene, hidesLowerScenes);
        MC_VFUNC(void,         struct UIScene, blocksInput);
        MC_VFUNC(void,         struct UIScene, GetMainPanel);
        MC_VFUNC(void,         struct UIScene, render);
        MC_VFUNC(void,         struct UIScene, customDraw);
        MC_VFUNC(void,         struct UIScene, allowRepeat);
        MC_VFUNC(void,         struct UIScene, handleInput, int, int, bool ,bool ,bool ,bool);
        MC_VFUNC(void,         struct UIScene, handleDestroy);
        MC_VFUNC(void,         struct UIScene, handlePreUnloadForReload);
        MC_VFUNC(void,         struct UIScene, handlePreReload);
        MC_VFUNC(void,         struct UIScene, handleReload);
        MC_VFUNC(void,         struct UIScene, handlePress);
        MC_VFUNC(void,         struct UIScene, handleFocusChange);
        MC_VFUNC(void,         struct UIScene, handleInitFocus);
        MC_VFUNC(void,         struct UIScene, handleCheckboxToggled);
        MC_VFUNC(void,         struct UIScene, handleCheckboxElementToggled);
        MC_VFUNC(void,         struct UIScene, handleSliderMove);
        MC_VFUNC(void,         struct UIScene, handleSliderElementMove);
        MC_VFUNC(void,         struct UIScene, handleAnimationEnd);
        MC_VFUNC(void,         struct UIScene, handleSelectionChanged);
        MC_VFUNC(void,         struct UIScene, handleRequestMoreData);
        MC_VFUNC(void,         struct UIScene, handleTouchBoxRebuild);
        MC_VFUNC(void,         struct UIScene, HandleDLCMountingComplete);
        MC_VFUNC(void,         struct UIScene, HandleDLCInstalled);
        MC_VFUNC(void,         struct UIScene, HandleDLCLicenseChange);
        MC_VFUNC(void,         struct UIScene, HandleTMSBanFileRetrieved);
        MC_VFUNC(void,         struct UIScene, HandleMessage);
        MC_VFUNC(void,         struct UIScene, HandleSaveDeviceRemoved);
        MC_VFUNC(void,         struct UIScene, handleUnlockFullVersion);
        MC_VFUNC(void,         struct UIScene, handleTouchInput);
        MC_VFUNC(void,         struct UIScene, isReadyToDelete);
    };
}