#pragma once

#include "../../control/object/UIControl_MultiList.h"
#include "../../control/object/UIControl_ButtonList.h"
#include "../../control/object/UIControl_CheckboxButtonList.h"
#include "../../../util/VTable_UIScene.h"

namespace mc {
    class UIScene_DebugMenu : public UIScene {
    public:
		UIScene_DebugMenu(uint32_t ID ,uint32_t FuncMaybe ,uint32_t layer)
		{
			code::Func<void, 0x02E39FD8, UIScene*, uint32_t, uint32_t>()(this, ID, layer); // UIScene::UIScene
			
			VTable_UIScene* DebugUIVtbl = new VTable_UIScene;
			memcpy(DebugUIVtbl, (VTable_UIScene*)0x1038574c, sizeof(VTable_UIScene));
			DebugUIVtbl->mapElementsAndNames = 	&mapElementsAndNames;
			DebugUIVtbl->getMoviePath = 		&getMoviePath;
			
			this->vtbl = DebugUIVtbl;
			
			UIControl_MultiList(&this->HowToList);
			this->initialiseMovie();
			
			uint32_t options[] = {
				((uint32_t)(L"Load Saves From Local Folder Mode")),
				((uint32_t)(L"Write Saves To Local Folder Mode")),
				((uint32_t)(L"Freeze Players")),
				((uint32_t)(L"Display Safe Area")),
				((uint32_t)(L"Mobs don't attack")),
				((uint32_t)(L"Freeze Time")),
				((uint32_t)(L"Disable Weather")),
				((uint32_t)(L"Craft Anything")),
				((uint32_t)(L"Use DPad for debug")),
				((uint32_t)(L"Mobs don't tick")),
				((uint32_t)(L"Art tools")),
				((uint32_t)(L"Show UI Console")),
				((uint32_t)(L"Distributable Save")),
				((uint32_t)(L"Debug Leaderboards")),
				((uint32_t)(L"Height-Water Maps")),
				((uint32_t)(L"Superflat Nether")),
				((uint32_t)(L"More lightning when thundering")),
				((uint32_t)(L"Biome override")),
				((uint32_t)(L"Go To Overworld")),
				((uint32_t)(L"Unlock All DLC")),
				((uint32_t)(L"Show Marketing Guide"))
			};
			int i = 0;
			for(uint32_t option : options)
			{
				this->HowToList.AddNewCheckbox(*(new mstd::wstring(((wchar_t*)option))), i, false);
				i++;
			}
			
			//this->HowToList.AddNewCheckbox(*(new mstd::wstring(L"This is Enabled")), 0, true);
			//this->HowToList.AddNewCheckbox(*(new mstd::wstring(L"This is NOT Enabled")), 1, false);
			
			this->doHorizontalResizeCheck();
			this->field_0x17C = 0;
			((ConsoleUIController*)0x104f73e0)->TouchBoxRebuild(this);
		}
		
		static void getMoviePath(UIScene* scene, mstd::wstring& string)
		{
			string.str[0] =  0;
			string.length2 = 7;
			string.length =  0;
			string.assign(L"DebugOptionsMenu", 16);
		}
		static void getMoviePathHTP(UIScene* scene, mstd::wstring& string)
		{
			string.str[0] =  0;
			string.length2 = 7;
			string.length =  0;
			string.assign(L"HowToPlayMenu", 13);
		}
		
		static int getSceneType(UIScene* scene)
		{
			return 0xD;
		}
		
		static bool mapElementsAndNames(UIScene* scene)
		{
			uint32_t fuiRoot = code::Func<uint32_t, 0x02ba8144, uint32_t>()(scene->fuiFile); // fuiFile::getRootNode
			
			mstd::wstring* HowToPlayStr = new mstd::wstring(L"");
			//HowToPlayStr->assign("HowToList", 9);
			HowToPlayStr->assign("DebugOptionsList", 16);
			
			((UIScene_DebugMenu*)scene)->HowToList.setupControl(scene, fuiRoot, HowToPlayStr);
			
			UIControl_MultiList* ControlPTR = &((UIScene_DebugMenu*)scene)->HowToList;
			
			code::Func<void, 0x02e34e18, uint32_t*, UIControl_MultiList**>()((uint32_t*)&scene->UIControl_Vector, &ControlPTR); // vector<UIControl*>.push_back
			return true;
		}
		static void Log(const wchar_t* text)
		{
			code::Func<void, 0x0382F6B8, const char*, const wchar_t*>()("%ls\n", text);
		}
		
		
		UIControl_MultiList HowToList;
		uint32_t field_0x17C;
        
    };
}