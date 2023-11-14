#pragma once

#include <code/code.h>

#include "../client/resource/shared_ptr.h"
#include "../client/resource/vector.h"

namespace mc {
    class AbstractContainerMenu {
    public:
        mstd::vector<mc_boost::shared_ptr<struct ItemInstance>>& getItems() {
            return code::Func<mstd::vector<mc_boost::shared_ptr<struct ItemInstance>>&, 0x02033EA0, AbstractContainerMenu*>()(this);
        }  
    };
}