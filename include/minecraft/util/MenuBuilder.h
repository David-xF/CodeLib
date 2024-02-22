#pragma once

#include <code/code.h>
#include <minecraft/item/ItemInstance.h>


namespace mc {
	
    class MenuBuilder {
		public:
        void ADD(const mc_boost::shared_ptr<struct mc::ItemInstance>& InstanceSharedPtr, mc::ItemInstance Instance)
		{
			mc::ItemInstance::toShared(InstanceSharedPtr, &Instance);
			code::Func<void, 0x02F0F424, MenuBuilder*, const mc_boost::shared_ptr<struct mc::ItemInstance>&>()(this, InstanceSharedPtr);
		}
		
        void ITEM_BLOCKSTATE(uint32_t BlockState)
		{
			code::Func<void, 0x02eccd20, MenuBuilder*, uint32_t>()(this, BlockState);
		}
		
		
		
		
		// NEITHER OF THESE WORK AT THE TIME BEING
        void BANNER(uint32_t DyeColor, uint32_t BannerPattern_PTR) //NEEDS DYECOLOUR AND BANNERPATTERN BUILDERS
		{
			code::Func<void, 0x02F0FDF8, MenuBuilder*, uint32_t, uint32_t>()(this, DyeColor, BannerPattern_PTR);
		}
		
        void POTION(mc::Item* item, uint32_t Potion_PTR) //NEEDS POTION BUILDER
		{
			code::Func<void, 0x02F10680, MenuBuilder*, mc::Item*, uint32_t>()(this, item, Potion_PTR);
		}
	};
}