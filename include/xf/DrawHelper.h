#pragma once

#include <minecraft/mc.h>

namespace xf {
    namespace GUI {
        uint32_t TextColorIndex = 0;
        uint32_t frameCount = 0;
        
        class DrawHelper {
        public:
            static void renderSetup(bool disableTex = true) {
                mc::GlStateManager::matrixMode(1);
                mc::GlStateManager::loadIdentity();
                mc::GlStateManager::ortho(0.0f, WIDTH, HEIGHT, 0.0f, -1.0f, 3000.0f);
                mc::GlStateManager::matrixMode(0);
                mc::GlStateManager::loadIdentity();
                mc::GlStateManager::translatef(0.0f, 0.0f, 0.0f);
                mc::GlStateManager::scalef(1.0f, 1.0f, 1.0f);
                mc::GlStateManager::disableCull();
                mc::GlStateManager::disableLighting();
                mc::GlStateManager::disableDepthTest();
                if (disableTex) mc::GlStateManager::disableTexture();
                else            mc::GlStateManager::enableTexture();
                mc::GlStateManager::enableBlend();
                mc::GlStateManager::blendFunc(4, 5);
                mc::GlStateManager::color4f(1, 1, 1, 1);
                mc::GlStateManager::disableFog();
            }

            static void DisplayText(mc::Font* font, const mstd::wstring& text, float size, float x, float y, uint32_t color = 0xFFFFFFFF, bool normal = true) {
                mc::GlStateManager::enableTexture();
                mc::GlStateManager::pushMatrix();
                mc::GlStateManager::translatef(x, y, 0);
                mc::GlStateManager::scalef(size, size, 0);
                if (color == 0) color = getRainbowRGB(TextColorIndex);
                if (normal)  font->drawShadow(text, 0, 0, color);
                else         font->draw      (text, 0, 0, color);
                mc::GlStateManager::popMatrix();
            }

            static void drawRoundedBox(float x, float y, float width, float height, float cornerRadius, int rgb, int a, int seg = 20) {
                float startX = x;
                float startY = y;
                float sizeX = width;
                float sizeY = height;
                float angle = cornerRadius;
                int segments = seg;

                mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
                mc::GlStateManager::disableTexture();
                mc::GlStateManager::pushMatrix();
                mc::GlStateManager::color4f(1, 1, 1, 1);
                builder->begin(0);
                builder->color(rgb, a);

                float step = 90.0f / mc::toFloat(segments);
                for (int i = 0; i < segments; i++) {
                    float  _x = sinf(degToRad(step * mc::toFloat(i)))     * angle;
                    float  _y = cosf(degToRad(step * mc::toFloat(i)))     * angle;
                    float __x = sinf(degToRad(step * mc::toFloat(i + 1))) * angle;	
                	float __y = cosf(degToRad(step * mc::toFloat(i + 1))) * angle;

                    // BOTTOM RIGHT
                    builder->vertex(startX + ((sizeX / 2.0f) - angle),       startY + ((sizeY / 2.0f) - angle));
                    builder->vertex(startX + ((sizeX / 2.0f) - angle) + _x,  startY + ((sizeY / 2.0f) - angle) + _y);
                    builder->vertex(startX + ((sizeX / 2.0f) - angle) + __x, startY + ((sizeY / 2.0f) - angle) + __y);

                    // TOP LEFT
                    builder->vertex(startX - ((sizeX / 2.0f) - angle),       startY - ((sizeY / 2.0f) - angle));
                    builder->vertex(startX - ((sizeX / 2.0f) - angle) - _x,  startY - ((sizeY / 2.0f) - angle) - _y);
                    builder->vertex(startX - ((sizeX / 2.0f) - angle) - __x, startY - ((sizeY / 2.0f) - angle) - __y);

                     _x = sinf(degToRad(180.0f + (step * mc::toFloat(i))))     * angle;
                     _y = cosf(degToRad(180.0f + (step * mc::toFloat(i))))     * angle;
                    __x = sinf(degToRad(180.0f + (step * mc::toFloat(i + 1)))) * angle;
                    __y = cosf(degToRad(180.0f + (step * mc::toFloat(i + 1)))) * angle;

                    // BOTTOM LEFT
                    builder->vertex(startX - ((sizeX / 2.0f) - angle),       startY + ((sizeY / 2.0f) - angle));
                    builder->vertex(startX - ((sizeX / 2.0f) - angle) + _x,  startY + ((sizeY / 2.0f) - angle) - _y);
                    builder->vertex(startX - ((sizeX / 2.0f) - angle) + __x, startY + ((sizeY / 2.0f) - angle) - __y);

                    // TOP RIGHT
                    builder->vertex(startX + ((sizeX / 2.0f) - angle),       startY - ((sizeY / 2.0f) - angle));
                    builder->vertex(startX + ((sizeX / 2.0f) - angle) - _x,  startY - ((sizeY / 2.0f) - angle) + _y);
                    builder->vertex(startX + ((sizeX / 2.0f) - angle) - __x, startY - ((sizeY / 2.0f) - angle) + __y);
                }    
                builder->end();

                builder->begin();
                builder->color(rgb, a);
                builder->vertex(startX - (sizeX / 2.0f),  startY + (sizeY / 2.0f) - angle);
			    builder->vertex(startX + (sizeX / 2.0f),  startY + (sizeY / 2.0f) - angle);
			    builder->vertex(startX + (sizeX / 2.0f),  startY - (sizeY / 2.0f) + angle);
                builder->vertex(startX - (sizeX / 2.0f),  startY - (sizeY / 2.0f) + angle);
                builder->end();

                builder->begin();
                builder->color(rgb, a);
                builder->vertex(startX - (sizeX / 2.0f) + angle,  startY + (sizeY / 2.0f));
			    builder->vertex(startX + (sizeX / 2.0f) - angle,  startY + (sizeY / 2.0f));
			    builder->vertex(startX + (sizeX / 2.0f) - angle,  startY - (sizeY / 2.0f));
                builder->vertex(startX - (sizeX / 2.0f) + angle,  startY - (sizeY / 2.0f));
                builder->end();
                mc::GlStateManager::popMatrix();
            }

            static void drawRoundedBoxImg(float x, float y, float width, float height, float cornerRadius, int id, uint32_t anim, bool layer = false, int seg = 20) {
                float startX = x;
                float startY = y;
                float sizeX = width;
                float sizeY = height;
                float angle = cornerRadius;
                int segments = seg;

                mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
                mc::GlStateManager::disableTexture();
                mc::Minecraft::getInstance()->textures->bind(id);
                mc::GlStateManager::pushMatrix();
                builder->begin(0);

                auto vertex = [&](float ___x, float ___y) {
                    float minWidth  = x - (sizeX / 2.0f);
                    float minHeight = y - (sizeY / 2.0f);
                    float maxWidth  = (x + (sizeX / 2.0f)) - minWidth;
                    float maxHeight = (y + (sizeY / 2.0f)) - minHeight;

                    float u = (___x - minWidth) / maxWidth;
                    float v = (___y - minHeight) / maxHeight;

                    if (anim & 0x00040000 || anim & 0x00080000) {
                        if (layer) {
                            u = (u * ((6.0f / 8.0f) - (5.0f / 8.0f))) + (5.0f / 8.0f);
                            v = (v * ((2.0f / 8.0f) - (1.0f / 8.0f))) + (1.0f / 8.0f);
                        } else {        
                            u = (u * ((2.0f / 8.0f) - (1.0f / 8.0f))) + (1.0f / 8.0f); 
                            v = (v * ((2.0f / 8.0f) - (1.0f / 8.0f))) + (1.0f / 8.0f); 
                        }
                    } else {
                        u = (u * ((2.0f / 8.0f) - (1.0f / 8.0f))) + (1.0f / 8.0f); 
                        v = (v * ((2.0f / 4.0f) - (1.0f / 4.0f))) + (1.0f / 4.0f); 
                    }

                    builder->vertexUV(___x, ___y, 0, u, v);
                    return;
                };

                float step = 90.0f / mc::toFloat(segments);
                for (int i = 0; i < segments; i++) {
                    float  _x = sinf(degToRad(step * mc::toFloat(i)))     * angle;
                    float  _y = cosf(degToRad(step * mc::toFloat(i)))     * angle;
                    float __x = sinf(degToRad(step * mc::toFloat(i + 1))) * angle;	
                	float __y = cosf(degToRad(step * mc::toFloat(i + 1))) * angle;

                    // BOTTOM RIGHT
                    vertex(startX + ((sizeX / 2.0f) - angle),       startY + ((sizeY / 2.0f) - angle)      );
                    vertex(startX + ((sizeX / 2.0f) - angle) +  _x, startY + ((sizeY / 2.0f) - angle) +  _y);
                    vertex(startX + ((sizeX / 2.0f) - angle) + __x, startY + ((sizeY / 2.0f) - angle) + __y);

                    // TOP LEFT
                    vertex(startX - ((sizeX / 2.0f) - angle),       startY - ((sizeY / 2.0f) - angle));
                    vertex(startX - ((sizeX / 2.0f) - angle) - _x,  startY - ((sizeY / 2.0f) - angle) - _y);
                    vertex(startX - ((sizeX / 2.0f) - angle) - __x, startY - ((sizeY / 2.0f) - angle) - __y);

                     _x = sinf(degToRad(180.0f + (step * mc::toFloat(i))))     * angle;
                     _y = cosf(degToRad(180.0f + (step * mc::toFloat(i))))     * angle;
                    __x = sinf(degToRad(180.0f + (step * mc::toFloat(i + 1)))) * angle;
                    __y = cosf(degToRad(180.0f + (step * mc::toFloat(i + 1)))) * angle;

                    // BOTTOM LEFT
                    vertex(startX - ((sizeX / 2.0f) - angle),       startY + ((sizeY / 2.0f) - angle));
                    vertex(startX - ((sizeX / 2.0f) - angle) + _x,  startY + ((sizeY / 2.0f) - angle) - _y);
                    vertex(startX - ((sizeX / 2.0f) - angle) + __x, startY + ((sizeY / 2.0f) - angle) - __y);

                    // TOP RIGHT
                    vertex(startX + ((sizeX / 2.0f) - angle),       startY - ((sizeY / 2.0f) - angle));
                    vertex(startX + ((sizeX / 2.0f) - angle) - _x,  startY - ((sizeY / 2.0f) - angle) + _y);
                    vertex(startX + ((sizeX / 2.0f) - angle) - __x, startY - ((sizeY / 2.0f) - angle) + __y);
                }    
                builder->end();
            
                builder->begin();
                vertex(startX - (sizeX / 2.0f),  startY + (sizeY / 2.0f) - angle);
			    vertex(startX + (sizeX / 2.0f),  startY + (sizeY / 2.0f) - angle);
			    vertex(startX + (sizeX / 2.0f),  startY - (sizeY / 2.0f) + angle);
                vertex(startX - (sizeX / 2.0f),  startY - (sizeY / 2.0f) + angle);
                builder->end();

                builder->begin();
                vertex(startX - (sizeX / 2.0f) + angle,  startY + (sizeY / 2.0f));
			    vertex(startX + (sizeX / 2.0f) - angle,  startY + (sizeY / 2.0f));
			    vertex(startX + (sizeX / 2.0f) - angle,  startY - (sizeY / 2.0f));
                vertex(startX - (sizeX / 2.0f) + angle,  startY - (sizeY / 2.0f));
                builder->end();
                mc::GlStateManager::popMatrix();
            }


            static void DisplayBox2D(float x, float y, float sX, float sY, int rgb, int a) {
                mc::GlStateManager::disableTexture();
                mc::GlStateManager::pushMatrix();
                mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
                builder->begin();
                builder->color(rgb, a);
                builder->vertex(x,      y,      0.0f);
                builder->vertex(x + sX, y,      0.0f);
                builder->vertex(x,      y + sY, 0.0f);
                builder->end();

                builder->begin();
                builder->color(rgb, a);
                builder->vertex(x + sX, y + sY, 0.0f);
                builder->vertex(x + sX, y,      0.0f);
                builder->vertex(x,      y + sY, 0.0f);
                builder->end();
                mc::GlStateManager::popMatrix();
            }

            static void DisplayBox2D(float x, float y, float sX, float sY, int imageID) {
                mc::Minecraft::getInstance()->textures->bind(imageID);
                mc::GlStateManager::pushMatrix();
                mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
                builder->begin();
                builder->vertexUV(x,      y,      0.0f, 0.0f, 0.0f);
                builder->vertexUV(x + sX, y,      0.0f, 1.0f, 0.0f);
                builder->vertexUV(x,      y + sY, 0.0f, 0.0f, 1.0f);
                builder->end();

                builder->begin();
                builder->vertexUV(x + sX, y + sY, 0.0f, 1.0f, 1.0f);
                builder->vertexUV(x + sX, y,      0.0f, 1.0f, 0.0f);
                builder->vertexUV(x,      y + sY, 0.0f, 0.0f, 1.0f);
                builder->end();
                mc::GlStateManager::popMatrix();
            }

            static void DisplayBox3D(float x, float y, float z, float sX, float sY, float sZ, int rgb, int a, bool fixCoords = false) {
                mc::GlStateManager::disableTexture();
                mc::GlStateManager::pushMatrix();
                mc::GlStateManager::translatef(0, 0, 0);
                mc::GlStateManager::color4f(1, 1, 1, 1);
                mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
            
                float s = x;
                s = s*2;

                builder->begin(); // TOP
                builder->color(rgb, a);
                builder->vertex(x,      y + sY,  z + sZ, fixCoords); // Y
			    builder->vertex(x + sX, y + sY,  z + sZ, fixCoords); // Y
			    builder->vertex(x + sX, y + sY,  z,      fixCoords); // Y
			    builder->vertex(x,      y + sY,  z,      fixCoords); // Y
                builder->end();

                builder->begin(); // BELOW
                builder->color(rgb, a);
                builder->vertex(x,       y,      z + sZ, fixCoords); // Y
			    builder->vertex(x + sX,  y,      z + sZ, fixCoords); // Y
			    builder->vertex(x + sX,  y,      z,      fixCoords); // Y
			    builder->vertex(x,       y,      z,      fixCoords); // Y
                builder->end();

                builder->begin(); // SOUTH = THe OTHER THING
			    builder->color(rgb, a);
                builder->vertex(x,      y + sY,  z + sZ, fixCoords); // X
			    builder->vertex(x,      y + sY,  z,      fixCoords); // X
			    builder->vertex(x,      y,       z,      fixCoords); // X
                builder->vertex(x,      y,       z + sZ, fixCoords); // X
                builder->end();

                builder->begin(); // WEST = LEFT
                builder->color(rgb, a);
			    builder->vertex(x,       y + sY,  z,     fixCoords); // Z
			    builder->vertex(x + sX,  y + sY,  z,     fixCoords); // Z
			    builder->vertex(x + sX,  y,       z,     fixCoords); // Z
                builder->vertex(x,       y,       z,     fixCoords); // Z
                builder->end();

                builder->begin(); // NORTH = MIDDLE
			    builder->color(rgb, a);
                builder->vertex(x + sX,  y + sY,  z,      fixCoords); // X
			    builder->vertex(x + sX,  y + sY,  z + sZ, fixCoords); // X
                builder->vertex(x + sX,  y,       z + sZ, fixCoords); // X
			    builder->vertex(x + sX,  y,       z,      fixCoords); // X
                builder->end();

                builder->begin(); // EAST = RIGHT
                builder->color(rgb, a);
                builder->vertex(x + sX,  y + sY,  z + sZ, fixCoords); // Z
			    builder->vertex(x,       y + sY,  z + sZ, fixCoords); // Z
			    builder->vertex(x,       y,       z + sZ, fixCoords); // Z
			    builder->vertex(x + sX,  y,       z + sZ, fixCoords); // Z
                builder->end();

                mc::GlStateManager::popMatrix();
            }

            static void DisplayBox3DImg(float x, float y, float z, float sX, float sY, float sZ, int imgID) {
                mc::Minecraft::getInstance()->textures->bind(imgID);
                mc::GlStateManager::pushMatrix();
                mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
            
                float s = x;
                s = s*2;

                //float32 Su = texture.getSide().r;    
            	//float32 Sv = texture.getSide().g;
            	//float32 Sm = texture.getSide().b;
            	//float32 Sn = texture.getSide().a;
         
                float width = 1.0f / 3.0f;
                float height = 1.0f / 2.0f;

                auto getUV = [&](int _x, int _y) {
                    float* f = new float[4];

                    f[0] = width * _x;
                    f[1] = f[0] + width;
                    f[3] = height * _y;
                    f[2] = f[3] + height;
                    return f;
                };

                float* f = getUV(1, 0);
                builder->begin(3); // TOP
                builder->vertexUV(x,      y + sY, z + sZ, f[1], f[2]); // Y
			    builder->vertexUV(x + sX, y + sY, z + sZ, f[0], f[2]); // Y
			    builder->vertexUV(x + sX, y + sY, z,      f[0], f[3]); // Y
			    builder->vertexUV(x,      y + sY, z,      f[1], f[3]); // Y
                builder->end();

                f = getUV(0, 0);
                builder->begin(3); // BELOW
                builder->vertexUV(x,      y, z + sZ, f[1], f[3]); // Y
			    builder->vertexUV(x + sX, y, z + sZ, f[0], f[3]); // Y
			    builder->vertexUV(x + sX, y, z,      f[0], f[2]); // Y
			    builder->vertexUV(x,      y, z,      f[1], f[2]); // Y
                builder->end();

                f = getUV(2, 1);
                builder->begin(3); // SOUTH = THe OTHER THING
                builder->vertexUV(x, y + sY, z + sZ, f[0], f[3]); // X
			    builder->vertexUV(x, y + sY, z,      f[1], f[3]); // X
			    builder->vertexUV(x, y,      z,      f[1], f[2]); // X
                builder->vertexUV(x, y,      z + sZ, f[0], f[2]); // X
                builder->end();

                f = getUV(2, 0);
                builder->begin(3); // WEST = LEFT
			    builder->vertexUV(x,      y + sY, z, f[0], f[3]); // Z
			    builder->vertexUV(x + sX, y + sY, z, f[1], f[3]); // Z
			    builder->vertexUV(x + sX, y,      z, f[1], f[2]); // Z
                builder->vertexUV(x,      y,      z, f[0], f[2]); // Z
                builder->end();

                f = getUV(0, 1);
                builder->begin(3); // NORTH = MIDDLE
                builder->vertexUV(x + sX, y + sY, z,      f[0], f[3]); // X
			    builder->vertexUV(x + sX, y + sY, z + sZ, f[1], f[3]); // X
                builder->vertexUV(x + sX, y,      z + sZ, f[1], f[2]); // X
			    builder->vertexUV(x + sX, y,      z,      f[0], f[2]); // X
                builder->end();

                f = getUV(1, 1);
                builder->begin(3); // EAST = RIGHT
                builder->vertexUV(x + sX, y + sY, z + sZ, f[0], f[3]); // Z
			    builder->vertexUV(x,      y + sY, z + sZ, f[1], f[3]); // Z
			    builder->vertexUV(x,      y,      z + sZ, f[1], f[2]); // Z
			    builder->vertexUV(x + sX, y,      z + sZ, f[0], f[2]); // Z
                builder->end();

                mc::GlStateManager::popMatrix();
            }

            static uint32_t Color(uint32_t r, uint32_t g, uint32_t b) {
                return 0xFF000000 | (r & 0xFF) << 24 | (g & 0xFF) << 16 | (b & 0xFF) << 8;
            }

            static uint32_t HSVToColor(float H, float S, float V) {
                return code::Func<uint32_t, 0x02624178, float, float, float>()(H, S, V);
            }

            static uint32_t getRainbowRGB(int _index = 0) {
                float jump = 360.0f / (2000.0f);
                for (int i = 0; i < 2000; i++) {
                    if (i == (_index % 2000)) {
                        uint32_t hsv = HSVToColor((jump * i) / 360.0f, 1.0f, 1.0f);
                        return 0xFF000000 | hsv;
                    }
                }
                
                return Color(255, 255, 255);
            }
        };
    } // GUI
} // xf
