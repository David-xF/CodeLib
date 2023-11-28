#include <code/code.h>

#include <minecraft/mc.h>
#include <xf/DrawHelper.h>

int imgId = 0;

DECL_FUNCTION(void, panorama, void* uicomp, int a, int b, int c) {
    if (imgId == 0) {
        mc::File file(L"custom_panorama.png");
        if (!file.exists()) {
            real_panorama(uicomp, a, b, c);
            return;
        }
        mc::FileInputStream in(file);
        int bufferSize = in.filesize();
        uint8_t* buffer = new uint8_t[bufferSize + 5];

        for (int i = 0; i < bufferSize; i++) {
            buffer[i] = in.read();
        }

        in.close();

        mc::BufferedImage* image = new mc::BufferedImage(buffer, bufferSize);
        imgId = mc::GlStateManager::genTexture();
        mc::Minecraft::getInstance()->textures->loadTexture(image, imgId);
    }

    xf::GUI::DrawHelper::renderSetup();
    xf::GUI::DrawHelper::DisplayBox2D(0, 0, WIDTH, HEIGHT, imgId);
}

int c_main(void*) {
    code::init();

    REPLACE(0x02e0b3a4, panorama);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}