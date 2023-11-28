#include <code/code.h>

#include <minecraft/mc.h>
#include <xf/DrawHelper.h>

void drawLine(mc::BufferBuilder* builder, mc::Vec3 pos1, mc::Vec3 pos2) {
    builder->vertex(pos1.x, pos1.y, pos1.z, true);
    builder->vertex(pos2.x, pos2.y, pos2.z, true);
}

void drawLineBox(mc::AABB box, uint32_t rgb = 0xFFFFFF, uint32_t a = 0xFF) {
    mc::BufferBuilder* builder = mc::Tesselator::getInstance()->getBuilder();
    mc::GlStateManager::disableTexture();
    mc::GlStateManager::lineWidth(5);
    mc::GlStateManager::pushMatrix();
    builder->begin(MC_GL_LINES);
    builder->color(rgb, a);
    // Bottom
    drawLine(builder, {box.min.x, box.min.y, box.min.z}, {box.max.x, box.min.y, box.min.z});
    drawLine(builder, {box.max.x, box.min.y, box.min.z}, {box.max.x, box.min.y, box.max.z});    
    drawLine(builder, {box.max.x, box.min.y, box.max.z}, {box.min.x, box.min.y, box.max.z});
    drawLine(builder, {box.min.x, box.min.y, box.max.z}, {box.min.x, box.min.y, box.min.z});

    // Top
    drawLine(builder, {box.min.x, box.max.y, box.min.z}, {box.max.x, box.max.y, box.min.z});
    drawLine(builder, {box.max.x, box.max.y, box.min.z}, {box.max.x, box.max.y, box.max.z});    
    drawLine(builder, {box.max.x, box.max.y, box.max.z}, {box.min.x, box.max.y, box.max.z});
    drawLine(builder, {box.min.x, box.max.y, box.max.z}, {box.min.x, box.max.y, box.min.z});

    // Lines from Buttom to Top
    drawLine(builder, {box.min.x, box.min.y, box.min.z}, {box.min.x, box.max.y, box.min.z});
    drawLine(builder, {box.max.x, box.min.y, box.min.z}, {box.max.x, box.max.y, box.min.z});
    drawLine(builder, {box.min.x, box.min.y, box.max.z}, {box.min.x, box.max.y, box.max.z});
    drawLine(builder, {box.max.x, box.min.y, box.max.z}, {box.max.x, box.max.y, box.max.z});
        
    builder->end();
    mc::GlStateManager::popMatrix();
}

DECL_FUNCTION(void, LevelRenderer_renderEntities, void* c, const mc_boost::shared_ptr<mc::Entity>& entity, void* b, float a) {
    real_LevelRenderer_renderEntities(c, entity, b, a); // Must be Called first
    
    mc::GlStateManager::disableCull();
    mc::GlStateManager::disableLighting();
    mc::GlStateManager::enableDepthTest();
    mc::GlStateManager::enableBlend();
    mc::GlStateManager::blendFunc(4, 5);
    mc::GlStateManager::disableFog();
    
    // Draws a White Cube at (0, 50, 0) with size (1, 1, 1)
    xf::GUI::DrawHelper::DisplayBox3D(0, 50, 0, 1, 1, 1, 0xFFFFFF, 0xFF, true); // Must be set to True
    // Draws a Red Cube with Half Transparency at (0, 50, 5) with size (1, 1, 1)
    xf::GUI::DrawHelper::DisplayBox3D(0, 50, 5, 1, 1, 1, 0xFF0000, 0xFF / 2, true);

    // Draws a Purple Line Box at (0, 50, -5) with size (1, 1, 1)
    drawLineBox({{0, 50, -5}, {1, 51, -4}}, 0xFF00FF, 0xFF);

    mc::GlStateManager::disableBlend();
    mc::GlStateManager::enableCull();
}

int c_main(void*) {
    code::init();

    REPLACE(0x031B8298, LevelRenderer_renderEntities);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}