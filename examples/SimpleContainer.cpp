#include <code/code.h>

#include <minecraft/mc.h>

DECL_FUNCTION(void, ServerPlayer_Swing, mc::ServerPlayer* player, mc::InteractionHand::EInteractionHand eHand) {
    real_ServerPlayer_Swing(player, eHand);

    // Creates a Container with the Name "Menu" and sets its size to 27
    mc::SimpleContainer* cont = new mc::SimpleContainer(0, 0, L"Menu", 27);
    mc_boost::shared_ptr<mc::SimpleContainer> shared;
    // I don't know why this is needded, but it is
    mc::SimpleContainer::toShared(shared, cont);
    
    // Set every Item to Stone with the Amount of i + 1
    for (int i = 0; i < 27; i++) shared->setItem(i, new mc::ItemInstance(mc::Item::byId(1), i + 1));
    
    // Opens Container for Player (Must be ServerPlayer if you want it to work with other Players)
    player->openContainer(&shared->container);
}

DECL_FUNCTION(void, ServerGamePacketListenerImpl_handleContainerClick, mc::ServerGamePacketListenerImpl* listener, const mc_boost::shared_ptr<mc::ServerboundContainerClickPacket>& packet) {
    mc::ServerPlayer* player = listener->player.get();
    int maxSlots = player->currentContainer->getItems().size();
    if (packet->slotNum >= maxSlots || 0 > packet->slotNum) return real_ServerGamePacketListenerImpl_handleContainerClick(listener, packet);

    mc::ItemInstance* clickedItem = player->currentContainer->getItems()[packet->slotNum].get();

    wchar_t temp[0x60];
    mc_swprintf(temp, 0x60, L"You clicked on Item %d with Item Slot %d [Has Tag %s]", clickedItem->item->getId(), packet->slotNum, clickedItem->hasTag() ? "True" : "False");
    listener->send(new mc::ClientboundChatPacket(temp));
    listener->send(new mc::ClientboundSoundPacket(mc::SoundEvent::note_hat));

    // If you want to cancel this Packet don't call real_ServerGamePacketListenerImpl_handleContainerClick
    // And Refresh the container with player->refreshContainer(player->currentContainer);
    real_ServerGamePacketListenerImpl_handleContainerClick(listener, packet);
}

int c_main(void*) {
    code::init();

    REPLACE(mc::ServerPlayer::_swing.addr(), ServerPlayer_Swing);
    REPLACE(mc::ServerGamePacketListenerImpl::_handleContainerClick.addr(), ServerGamePacketListenerImpl_handleContainerClick);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}