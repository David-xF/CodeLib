#pragma once

#include <code/code.h>

#include "./UIControl_List.h"
#include "../../scene/UIScene.h"

namespace mc {
    class UIControl_ButtonList : public UIControl_List {
    public:
		UIControl_ButtonList()
		{
			code::Func<void, 0x02DC0580, UIControl_ButtonList*>()(this);
		}
		UIControl_ButtonList(UIControl_ButtonList* _this)
		{
			code::Func<void, 0x02DC0580, UIControl_ButtonList*>()(_this);
		}
		
		void addItem(mstd::wstring* Str, uint32_t i)
		{
			code::Func<void, 0x02dc0604, UIControl_ButtonList*, mstd::wstring*, uint32_t>()(this, Str, i);
		}
		void setupControl(UIScene* scene, uint32_t fuiNode, mstd::wstring* Str)
		{
			code::Func<void, 0x02dc05ec, UIControl_ButtonList*, UIScene*, uint32_t, mstd::wstring*>()(this, scene, fuiNode, Str);
		}
		
		uint32_t field_0x60;
		uint32_t field_0x64;
		uint32_t field_0x68;
		uint32_t field_0x6C;
		uint32_t field_0x70;
		uint32_t field_0x74;
		uint32_t field_0x78;
		uint32_t field_0x7C;
		uint32_t field_0x80;
		uint32_t field_0x84;
		uint32_t field_0x88;
		uint32_t field_0x8C;
		uint32_t field_0x90;
		uint32_t field_0x94;
		uint32_t field_0x98;
		uint32_t field_0x9C;
		uint32_t field_0xA0;
		uint32_t field_0xA4;
		uint32_t field_0xA8;
		uint32_t field_0xAC;
		uint32_t field_0xB0;
		uint32_t field_0xB4;
    };
}