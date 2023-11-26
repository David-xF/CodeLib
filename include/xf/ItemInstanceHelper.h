#pragma once

#include <minecraft/mc.h>

namespace xf {
    class ItemInstanceHelper {
    public:
    	enum eOperator : int {
    		PLUS = 0,
    		PLUS_PERCENT = 1
    	};
    
        static void setName(mc::ItemInstance* _item, mstd::wstring const & name) {
            if (!_item->tag) _item->setTag(new mc::CompoundTag());
            
            if (!_item->tag->contains(L"display")) {
                mc::CompoundTag* tag = new mc::CompoundTag();
                _item->tag->put(L"display", tag);
            }
            
            mc::CompoundTag* tag = _item->tag->getCompound(L"display");
            if (tag->contains(L"Name")) tag->remove(L"Name");
            tag->putString(L"Name", name);
        }
    
        static void addEnchant(mc::ItemInstance* _item, int ench, int lvl) {
            if (!_item->tag) _item->setTag(new mc::CompoundTag()); 
    
            bool isAlreadyThere = _item->tag->contains(L"ench");
            if (!isAlreadyThere) {
                mc::ListTag* list = new mc::ListTag(0);
                _item->tag->put(L"ench", list);
            }
    
            mc::ListTag* list = _item->tag->getList(L"ench", 10);
            mc::CompoundTag* newTag = new mc::CompoundTag();
    
            newTag->putShort(L"id", ench);
            newTag->putShort(L"lvl", lvl);
    
            list->add(newTag);
        }
    
        static void addAttrib(mc::ItemInstance* _item, int id, double amt, int op, mstd::wstring const & str) {
            if (!_item->tag) _item->setTag(new mc::CompoundTag()); 
    
            bool isAlreadyThere = _item->tag->contains(L"AttributeModifiers");
            if (!isAlreadyThere) {
                mc::ListTag* list = new mc::ListTag(0);
                _item->tag->put(L"AttributeModifiers", list);
            }
    
            mc::ListTag* list = _item->tag->getList(L"AttributeModifiers", 10);
            mc::CompoundTag* newTag = new mc::CompoundTag();
    
            newTag->putInt(L"ID", id);
            newTag->putDouble(L"Amount", amt);
            newTag->putInt(L"Operation", op);
            newTag->putString(L"Slot", str);
    
            list->add(newTag);
        }

        static void addPotionEffect(mc::ItemInstance* _item, int id, int amplifier, int duration) {
            if (!_item->tag) _item->setTag(new mc::CompoundTag());

            bool isAlreadyThere = _item->tag->contains(L"CustomPotionEffects");
            if (!isAlreadyThere) {
                mc::ListTag* list = new mc::ListTag(0);
                _item->tag->put(L"CustomPotionEffects", list);
            }

            mc::ListTag* list = _item->tag->getList(L"CustomPotionEffects", 10);
            mc::CompoundTag* newTag = new mc::CompoundTag();
    
            newTag->putByte(L"Ambient", false);
            newTag->putByte(L"Amplifier", amplifier);
            newTag->putByte(L"Id", id);
            newTag->putByte(L"ShowParticles", true);
            newTag->putInt(L"Duration", duration);
    
            list->add(newTag);
        }
    };
}