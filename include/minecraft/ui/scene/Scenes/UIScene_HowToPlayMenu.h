#pragma once


#include "../../control/object/UIControl_ButtonList.h"
namespace mc {
    class UIScene_HowToPlayMenu : public UIScene {
    public:
		UIScene_HowToPlayMenu(uint32_t ID ,uint32_t FuncMaybe ,uint32_t layer)
		{
			code::Func<void, 0x02E39FD8, UIScene*, uint32_t, uint32_t>()(this, ID, layer); 										// UIScene::UIScene
			this->vtbl = (mc::VTable_UIScene*)0x1038574c;
			
			UIControl_ButtonList(&this->HowToList);
			this->initialiseMovie();
			
			wchar_t* LLG = new wchar_t[0x40];
			mc_swprintf(LLG, 0x40, L" -- %#p -- %#p", this->UIControl_Vector.start, this->UIControl_Vector.finish);
			Log(LLG);
			
			this->HowToList.init(0);
			
			for(int i = 0; i < 33; i++)
			{
				wchar_t* String = mc::Minecraft::getString(  *((uint32_t*)(0x104ca2d0 + (4 * i)))  );
				this->HowToList.addItem(new mstd::wstring(String), i);
			}
			
			this->doHorizontalResizeCheck();
			this->field_0x17C = 0;
			((ConsoleUIController*)0x104f73e0)->TouchBoxRebuild(this);
		}
		
		void mapElementsAndNames()
		{
			uint32_t fuiRoot = code::Func<uint32_t, 0x02ba8144, uint32_t>()(this->fuiFile); // fuiFile::getRootNode
			
			mstd::wstring* HowToPlayStr = new mstd::wstring(L"");
			HowToPlayStr->assign("HowToList", 9);
			
			this->HowToList.setupControl(this, fuiRoot, HowToPlayStr);
			
			UIControl_ButtonList* ControlPTR = &this->HowToList;
			
			code::Func<void, 0x02e34e18, uint32_t*, UIControl_ButtonList**>()((uint32_t*)&this->UIControl_Vector, &ControlPTR); // vector<UIControl*>.push_back
		}
		
		static void Log(const wchar_t* text)
		{
			code::Func<void, 0x0382F6B8, const char*, const wchar_t*>()("%ls\n", text);
		}
		
		
		UIControl_ButtonList HowToList;
		uint32_t field_0x17C;
        
    };
}