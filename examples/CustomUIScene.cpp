#include <code/code.h>

#include <minecraft/mc.h>


DECL_FUNCTION(uint32_t, NavigateToScene, mc::UILayer* _this, uint32_t p2, uint32_t SceneID, uint32_t p4) {
	
	switch(SceneID)
	{
		case(0xd): // Check for unused UIScene ID
		{
			mc::UIScene_DebugMenu* debug = new mc::UIScene_DebugMenu(p2, p4, (uint32_t)_this);
			uint32_t SubSceneType = debug->vtbl->getSubSceneType(debug);
			(*(mc::TelemetryManager**)0x104f6970)->Vtbl->RecordMenuShown(*((mc::TelemetryManager**)0x104f6970), p2, SceneID, SubSceneType);
		
		
			uint32_t LayerSceneStart = (uint32_t)_this->scenes.start;
			uint32_t TempValue = 0;
			uint32_t LayerSceneFinish = (uint32_t)_this->scenes.finish - LayerSceneStart >> 2;
		
		
			if ((LayerSceneStart != 0) && (LayerSceneFinish != 0)) {
				TempValue = LayerSceneStart;
				if (LayerSceneStart != 0) {
					TempValue = LayerSceneFinish;
				}
				debug->SetBackScene(*((mc::UIScene**)(LayerSceneStart + (TempValue + -1) * 4)));
			}
		
			code::Func<void, 0x02e34e18, uint32_t*, mc::UIScene_DebugMenu**>()((uint32_t*)&_this->scenes, &debug); // vector<UIScene**>.push_back
			_this->updateFocusState(false);
			debug->vtbl->tick(debug);
		return 1;
		}
		break;
		default:
			return real_NavigateToScene(Scene, p2, SceneID, p4);
		break;
	}
	return real_NavigateToScene(Scene, p2, SceneID, p4);
}

int c_main(void*) {
    code::init();

    REPLACE(0x02e8461c,  NavigateToScene);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}
