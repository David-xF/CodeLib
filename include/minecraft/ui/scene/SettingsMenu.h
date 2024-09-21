#pragma once

namespace mc {
    class SettingsMenu : public UIScene {
    public:
		SettingsMenu()
		{
			code::Func<void, 0x02F85D2C, SettingsMenu*>()(this);
		}
		SettingsMenu(uint32_t ID, void* WhatIsThis, struct UILayer* layer)
		{
			code::Func<void, 0x02F85984, SettingsMenu*, uint32_t, void*,  struct UILayer*>()(this, ID, WhatIsThis, layer);
		}
		
		
        
    };
}