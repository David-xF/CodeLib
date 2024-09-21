#pragma once

#include <code/code.h>

#include "../UIControl_Base.h"

namespace mc {
    class UIControl_Label : public UIControl_Base {
    public:
		UIControl_Label()
		{
			code::Func<void, 0x02dbef08, UIControl_Label*>()(this);
		}
		UIControl_Label(UIControl_Label* _this)
		{
			code::Func<void, 0x02dbef08, UIControl_Label*>()(_this);
		}
        uint32_t field_0x5C;
    };
}