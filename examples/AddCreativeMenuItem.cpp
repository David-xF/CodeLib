#include <code/code.h>
#include <minecraft/mc.h>

mc_boost::shared_ptr<struct mc::ItemInstance> GetItemPtr(mc::Item* ItemPointer, int qty, int aux)
{
	mc::ItemInstance inst = mc::ItemInstance(ItemPointer, qty, aux);
	mc::ItemInstance* itm = &inst;
	mc_boost::shared_ptr<mc::ItemInstance> instance;
		
	mc::ItemInstance::toShared(instance, itm);
		
	return instance;
}
	
	
DECL_FUNCTION(void, MenuBuilder_Block, uint32_t e1, uint32_t e2) {
	
	uint32_t Blockstate = mc::Block::byId(52)->defaultBlockState();
	
	// run normal function to add block
	real_MenuBuilder_Block(e1, e2);
	
	
	if(e2 == Blockstate) // is added block is a monster spawner
	{
		real_MenuBuilder_Block(e1, mc::Block::byId(166)->defaultBlockState()); // add barrier
	}
	
	
	
}

DECL_FUNCTION(void, MenuBuilder_Item, uint32_t e1, const mc_boost::shared_ptr<struct mc::ItemInstance>& e2) {
	
	// run normal function to add item
	real_MenuBuilder_Item(e1, e2);
	
	if(e2.get()->item->getId() == 399) // if Item has ID of nether star
	{
		real_MenuBuilder_Item(e1, GetItemPtr(mc::Item::byId(2255), 1, 0)); // add 4j debug item
	}
	
	
}


int c_main(void*) {
    // Init Export Functions and other Stuff
    code::init();
	
    REPLACE(0x02ECCD20, MenuBuilder_Block); // replace MenuBuilder::ITEM_BLOCKSTATE((BlockState const *))
    REPLACE(0x02F0F424, MenuBuilder_Item); // replace  MenuBuilder::ADD((const boost::shared_ptr<ItemInstance>&))

    return 0;
}

// Gets Called once at startup
void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}