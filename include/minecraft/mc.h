#pragma once

#include "block/Block.h"

#include "blockentity/BlockEntity.h"
#include "blockentity/SignBlockEntity.h"
#include "blockentity/TheEndGatewayEntity.h"

#include "client/app/CInput.h"
#include "client/app/CMinecraftApp.h"
#include "client/app/ConsoleUIController.h"
#include "client/app/CProfile.h"
#include "client/app/Options.h"
#include "client/app/System.h"

#include "client/file/File.h"
#include "client/file/FileInputStream.h"
#include "client/file/FileOutputStream.h"

#include "client/resource/texture/Textures.h"

#include "client/resource/NonNullList.h"
#include "client/resource/ResourceLocation.h"
#include "client/resource/shared_ptr.h"
#include "client/resource/vector.h"
#include "client/resource/wstring.h"

#include "client/C4JThreadImpl.h"
#include "client/Minecraft.h"

#include "container/AbstractContainerMenu.h"
#include "container/Container.h"
#include "container/Inventory.h"
#include "container/SimpleContainer.h"

#include "entity/effect/MobEffect.h"
#include "entity/effect/MobEffectInstance.h"

#include "entity/player/LocalPlayer.h"
#include "entity/player/Player.h"
#include "entity/player/PlayerUID.h"
#include "entity/player/RemotePlayer.h"
#include "entity/player/ServerPlayer.h"

#include "entity/AgableMob.h"
#include "entity/Animal.h"
#include "entity/AreaEffectCloud.h"
#include "entity/Entity.h"
#include "entity/ItemEntity.h"
#include "entity/ItemFrame.h"
#include "entity/LivingEntity.h"
#include "entity/Mob.h"
#include "entity/Monster.h"
#include "entity/Painting.h"
#include "entity/PathfinderMob.h"
#include "entity/PrimedTnt.h"
#include "entity/Sheep.h"
#include "entity/Slime.h"
#include "entity/SpectralArrow.h"
#include "entity/TippableArrow.h"
#include "entity/Zombie.h"

#include "item/BlockItem.h"
#include "item/BowItem.h"
#include "item/Item.h"
#include "item/ItemInstane.h"

#include "nbt/CompundTag.h"
#include "nbt/ListTag.h"
#include "nbt/Tag.h"

#include "network/listener/ClientPacketListener.h"
#include "network/listener/ServerGamePacketListenerImpl.h"

#include "network/packet/clientbound/ClientbooundSetEntityMotionPacket.h"
#include "network/packet/clientbound/ClientboundBlockUpdatePacket.h"
#include "network/packet/clientbound/ClientboundChatPacket.h"
#include "network/packet/clientbound/ClientboundSoundPacket.h"

#include "network/packet/serverbound/ServerboundContainerClickPacket.h"
#include "network/packet/serverbound/ServerboundInteractPacket.h"
#include "network/packet/serverbound/ServerboundMovePlayerPacket.h"
#include "network/packet/serverbound/ServerboundPlayerActionPacket.h"
#include "network/packet/serverbound/ServerboundPreLoginPacket.h"
#include "network/packet/serverbound/ServerboundSetCreativeModeSlotPacket.h"
#include "network/packet/serverbound/ServerboundUseItemOnPacket.h"

#include "network/packet/CraftItemPacket.h"
#include "network/packet/DisconnectPacket.h"
#include "network/packet/Packet.h"

#include "network/server/MinecraftServer.h"
#include "network/server/PlayerList.h"

#include "rendering/buffer/BufferBuilder.h"
#include "rendering/buffer/BufferedImage.h"

#include "rendering/CameraController.h"
#include "rendering/Font.h"
#include "rendering/GlStateManager.h"
#include "rendering/Tesselator.h"

#include "ui/Gui.h"

#include "util/AABB.h"
#include "util/Abilities.h"
#include "util/BlockPos.h"
#include "util/ClickType.h"
#include "util/DamageSource.h"
#include "util/Direction.h"
#include "util/EntityTickCache.h"
#include "util/ePARTICLE_TYPE.h"
#include "util/FloatConverter.h"
#include "util/FoodData.h"
#include "util/GameType.h"
#include "util/HitResult.h"
#include "util/InteractionHand.h"
#include "util/MallocOperator.h"
#include "util/Matrix4.h"
#include "util/Other.h"
#include "util/pair.h"
#include "util/ParticleType.h"
#include "util/ParticleType.h"
#include "util/SoundEvent.h"
#include "util/SoundSource.h"
#include "util/unordered_map.h"
#include "util/Vec3.h"
#include "util/VTable_Entity.h"
#include "util/VTable_Item.h"
#include "util/VTable.h"

#include "world/gamemode/ServerPlayerGameMode.h"

#include "world/Level.h"
#include "world/ServerLevel.h"

// Prints a message into Chat.
template<typename... Args>
void mc_printf(const wchar_t* x, Args... args) {
    if (!mc::Minecraft::getInstance()->thePlayer) return;
    wchar_t temp[0xA0];
    mc_swprintf(temp, 0xA0, x, args...);
    mc::Minecraft::getInstance()->gui->addMessage(temp, 0, 0, 0, 0, 0);
}