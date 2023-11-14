#pragma once

#include <code/code.h>

#include "UIControl.h"

namespace mc {
    class UIControl_Base : public UIControl {
    public:
        uint8_t _filler[0xC];
    };
}