#pragma once

#include "../../client/resource/vector.h"
namespace mc {
    class UIScene {
    public:
		UIScene()
		{
			code::Func<void, 0x02E30050, UIScene*>()(this);
		}
		UIScene(uint32_t ID ,uint32_t FuncMaybe ,uint32_t layer)
		{
			code::Func<void, 0x02E39FD8, UIScene*, uint32_t, uint32_t, uint32_t>()(this, ID, FuncMaybe, layer);
		}
		UIScene(uint32_t ID ,uint32_t layer)
		{
			code::Func<void, 0x02E39FD8, UIScene*, uint32_t, uint32_t>()(this, ID, layer);
		}
		
		void initialiseMovie()
		{
			code::Func<void, 0x02E3A79C, UIScene*>()(this);
		}
		void doHorizontalResizeCheck()
		{
			code::Func<void, 0x02e637c0, UIScene*>()(this); 
		}
		void SetBackScene(UIScene* BackScene)
		{
			code::Func<void, 0x02e84614, UIScene*, UIScene*>()(this, BackScene); 
		}
		
		uint32_t field_0x0;
		uint32_t UIScontrol;
		uint32_t field_0x8;
		uint32_t field_0xC;
		uint32_t field_0x10;
		uint32_t field_0x14;
		uint32_t field_0x18;
		uint32_t field_0x1C;
		uint32_t fuiFile;
		uint32_t field_0x24;
		uint32_t field_0x28;
		uint32_t field_0x2C;
		uint32_t field_0x30;
		uint32_t field_0x34;
		uint32_t field_0x38;
		uint32_t field_0x3C;
		uint32_t field_0x40;
		uint32_t field_0x44;
		uint32_t field_0x48;
		uint32_t field_0x4C;
		uint32_t field_0x50;
		uint32_t field_0x54;
		uint32_t field_0x58;
		uint32_t field_0x5C;
		uint32_t field_0x60;
		float Opacity;
		uint32_t field_0x68;
		UIScene* backScene;
		uint32_t field_0x70;
		uint32_t field_0x74;
		uint32_t field_0x78;
		uint32_t field_0x7C;
		uint32_t field_0x80;
		uint32_t field_0x84;
		uint32_t field_0x88;
		mstd::vector<uint32_t> UIControl_Vector;
		struct UILayer* UILayer;
		uint32_t field_0xA0;
		uint32_t UISceneID;
		uint32_t field_0xA8;
		uint32_t field_0xAC;
		uint32_t field_0xB0;
		uint32_t field_0xB4;
		uint32_t field_0xB8;
		uint32_t field_0xBC;
		uint32_t field_0xC0;
		struct VTable_UIScene* vtbl;
        
    };
}