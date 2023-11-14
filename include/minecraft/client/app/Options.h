#pragma once

#include <code/code.h>

namespace mc {
    class Options {
    public:
        float musicVolume;
        float soundVolume;
        float mouseSensitivity;
        int field_0xC;
        int viewDistance;
        char bobView;
        char anaglyph3d;
        char hasAdvancedOpenGL;
        char field_0x17;
        int FPSCap;
        char hasFancyGraphics;
        char ao;
        char clouds_;
        char field_0x1F;
        char filler_0xB4[0xB4];
        int difficulty;
        bool renderNames;
        bool field_0xD9;
        bool field_0xDA;
        bool field_0xDB;
        int field_0xDC;
        int renderDebug;
        char filler_0x34[0x34];
        float guiScale;
        float particles;
        float FOV;
        float gamma;
    };
}