#pragma once

#include <code/code.h>

#include "../../client/resource/vector.h"

#include "../../util/unordered_map.h"
#include "../../util/pair.h"

namespace mc {
    class UILayer {
    public:
        mstd::vector<struct UIScene*> scenes;
        mstd::vector<struct UIScene*> components;
        mstd::vector<struct UIScene*> field_0x20;
        mstd::vector<struct UIScene*> field_0x30;
        mc_boost::unordered::unordered_map<int, mstd::pair<int, bool>> componentVisibility;
        bool field_0x58;
        bool field_0x59;
        bool field_0x5A;
        bool field_0x5B;
        int field_0x5C;
        int field_0x60;
        struct UIGroup* group;
    };
}