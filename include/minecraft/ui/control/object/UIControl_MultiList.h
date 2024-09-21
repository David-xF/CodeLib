#pragma once

#include <code/code.h>

#include "./UIControl_List.h"
#include "../../scene/UIScene.h"

namespace mc {
    class UIControl_MultiList : public UIControl_List {
    public:
		UIControl_MultiList()
		{
			code::Func<void, 0x02E67BD4, UIControl_MultiList*>()(this);
		}
		
		UIControl_MultiList(UIControl_MultiList* _this)
		{
			code::Func<void, 0x02E67BD4, UIControl_MultiList*>()(_this);
		}
		
		void setupControl(UIScene* scene, uint32_t fuiNode, mstd::wstring* Str)
		{
			code::Func<void, 0x02E8E86C, UIControl_MultiList*, UIScene*, uint32_t, mstd::wstring*>()(this, scene, fuiNode, Str);
		}
		
		void AddNewButton(const mstd::wstring& string, uint32_t ID, bool Enabled)
		{
			code::Func<void, 0x02E345EC, UIControl_MultiList*, const mstd::wstring&, uint32_t, bool>()(this, string, ID, Enabled);
		}
		
		void AddNewCheckbox(const mstd::wstring& string, uint32_t ID, bool Enabled)
		{
			code::Func<void, 0x02E67CA8, UIControl_MultiList*, const mstd::wstring&, uint32_t, bool>()(this, string, ID, Enabled);
		}
		
		void AddNewLabel(const mstd::wstring& string, uint32_t ID)
		{
			code::Func<void, 0x02E67C40, UIControl_MultiList*, const mstd::wstring&, uint32_t>()(this, string, ID);
		}
		
		void AddNewMenuButton(const mstd::wstring& string, uint32_t ID)
		{
			code::Func<void, 0x02E8ECF8, UIControl_MultiList*, const mstd::wstring&, uint32_t>()(this, string, ID);
		}
		
		void AddNewTextInput(const mstd::wstring& string, uint32_t ID, uint32_t Limit)
		{
			code::Func<void, 0x02E7A76C, UIControl_MultiList*, const mstd::wstring&, uint32_t, uint32_t>()(this, string, ID, Limit);
		}
		
		void AddNewSlider(const mstd::wstring& string, bool Enabled, uint32_t ID, uint32_t Index, uint32_t Minimum, uint32_t Maximum)
		{
			code::Func<void, 0x02E6CF88, UIControl_MultiList*, const mstd::wstring&, uint32_t, uint32_t, uint32_t, uint32_t, bool, uint32_t, uint32_t>()(this, string, ID, Minimum, Maximum, Index, Enabled, Maximum, Minimum);
		}
		
		void removeItem(uint32_t ID, bool Condition)
		{
			code::Func<void, 0x02E89F0C, UIControl_MultiList*, uint32_t, bool>()(this, ID, Condition);
		}
		void EnableItem(uint32_t ID, bool Condition, bool Condition2)
		{
			code::Func<void, 0x02E67FC0, UIControl_MultiList*, uint32_t, bool, bool>()(this, ID, Condition, Condition2);
		}
		void ToggleCheckbox(uint32_t ID, bool Condition, bool Condition2)
		{
			code::Func<void, 0x02E6D0D4, UIControl_MultiList*, uint32_t, bool, bool>()(this, ID, Condition, Condition2);
		}
		void ToggleSlider(uint32_t ID, uint32_t Value, bool Condition)
		{
			code::Func<void, 0x02E8EDDC, UIControl_MultiList*, uint32_t, uint32_t, bool>()(this, ID, Value, Condition);
		}
		
		void SetItemLabel(wchar_t* string, uint32_t ID, bool Enabled)
		{
			uint32_t UIString = code::Func<uint32_t, 0x02f47938, uint32_t, wchar_t*>()(0, string);
			code::Func<void, 0x02E8F054, UIControl_MultiList*, uint32_t, uint32_t, bool, bool, bool>()(this, ID, UIString, Enabled, Enabled, Enabled);
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
        uint32_t field_0xB8;
        uint32_t field_0xBC;
    };
}