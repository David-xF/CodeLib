#pragma once

#include <code/code.h>

#include "../UIControl_Base.h"

namespace mc {
    class UIControl_List : public UIControl_Base {
    public:
		UIControl_List()
		{
			code::Func<void, 0x02E67AE4, UIControl_List*>()(this);
		}
		UIControl_List(UIControl_List* _this)
		{
			code::Func<void, 0x02E67AE4, UIControl_List*>()(_this);
		}
		void init(int i)
		{
			code::Func<void, 0x02e5606c, UIControl_List*, int>()(this, i);
		}
		void addElement(uint32_t EUICon, int id)
		{
			code::Func<void, 0x02E34538, UIControl_List*, uint32_t, int>()(this, EUICon, id);
		}
		
        uint32_t field_0x5C;
    };
}