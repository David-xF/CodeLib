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
	
	
DECL_FUNCTION(void, MenuBuilder_Block, mc::MenuBuilder* builder, uint32_t State) {
	
	// run normal function to add block
	real_MenuBuilder_Block(builder, State);
	
	if(State == mc::Block::byId(52)->defaultBlockState()) // if block is a monster spawner(ID 52)
	{
		builder->ITEM_BLOCKSTATE(mc::Block::byId(166)->defaultBlockState()); // add barrier
		builder->ADD(api.GetItemPtr(mc::Item::byId(2255), 1, 0)); // add 4j debug item
	}
	
}

DECL_FUNCTION(void, MenuBuilder_Item, mc::MenuBuilder* builder, const mc_boost::shared_ptr<struct mc::ItemInstance>& instance) {
	
	// run normal function to add item
	real_MenuBuilder_Item(builder, instance);
	
	
	if(instance.get()->item->getId() == 399)  // if Item is a nether star(ID 399)
	{
		builder->ITEM_BLOCKSTATE(mc::Block::byId(166)->defaultBlockState()); // add barrier
		builder->ADD(api.GetItemPtr(mc::Item::byId(2255), 1, 0)); // add 4j debug item
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