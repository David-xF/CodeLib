#pragma once

#include <code/code.h>

#include "./UIControl_List.h"
#include "../../scene/UIScene.h"

namespace mc {
    class UIControl_CheckboxButtonList : public UIControl_List {
    public:
		UIControl_CheckboxButtonList()
		{
			code::Func<void, 0x02DC59D4, UIControl_CheckboxButtonList*>()(this);
		}
		UIControl_CheckboxButtonList(UIControl_CheckboxButtonList* _this)
		{
			code::Func<void, 0x02DC59D4, UIControl_CheckboxButtonList*>()(_this);
		}
		
		void setupControl(UIScene* scene, uint32_t fuiNode, mstd::wstring* Str)
		{
			code::Func<void, 0x02DC5A40, UIControl_CheckboxButtonList*, UIScene*, uint32_t, mstd::wstring*>()(this, scene, fuiNode, Str);
		}
		
		void addItem(mstd::wstring* Str, uint32_t id, bool checked, mstd::wstring* Icon)
		{
			code::Func<void, 0x02DC5A70, UIControl_CheckboxButtonList*, mstd::wstring*, uint32_t, bool, mstd::wstring*>()(this, Str, id, checked, Icon);
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