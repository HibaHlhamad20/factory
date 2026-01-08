#include "Cuboid.h"

Cuboid::Cuboid(Point c, float l, float h, float w) {
    center = c;
    length = l;
    height = h;
    width = w;
}

void Cuboid::draw() {
    float hl = length / 2.0f;
    float hh = height / 2.0f;
    float hw = width / 2.0f;

    glBegin(GL_QUADS);

    // 1. «·ÊÃÂ «·√„«„Ì (Front Face)
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(center.x - hl, center.y - hh, center.z + hw);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(center.x + hl, center.y - hh, center.z + hw);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(center.x + hl, center.y + hh, center.z + hw);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(center.x - hl, center.y + hh, center.z + hw);

    // 2. «·ÊÃÂ «·Œ·›Ì (Back Face)
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(center.x - hl, center.y - hh, center.z - hw);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(center.x - hl, center.y + hh, center.z - hw);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(center.x + hl, center.y + hh, center.z - hw);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(center.x + hl, center.y - hh, center.z - hw);

    // 3. «·ÊÃÂ «·⁄·ÊÌ (Top Face) - «·”ﬁ›
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(center.x - hl, center.y + hh, center.z - hw);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(center.x - hl, center.y + hh, center.z + hw);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(center.x + hl, center.y + hh, center.z + hw);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(center.x + hl, center.y + hh, center.z - hw);

    // 4. «·ÊÃÂ «·”›·Ì (Bottom Face) - «·√—÷Ì…
    glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(center.x - hl, center.y - hh, center.z - hw);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(center.x + hl, center.y - hh, center.z - hw);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(center.x + hl, center.y - hh, center.z + hw);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(center.x - hl, center.y - hh, center.z + hw);

    // 5. «·ÊÃÂ «·√Ì„‰ (Right Face)
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(center.x + hl, center.y - hh, center.z - hw);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(center.x + hl, center.y + hh, center.z - hw);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(center.x + hl, center.y + hh, center.z + hw);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(center.x + hl, center.y - hh, center.z + hw);

    // 6. «·ÊÃÂ «·√Ì”— (Left Face)
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(center.x - hl, center.y - hh, center.z - hw);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(center.x - hl, center.y - hh, center.z + hw);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(center.x - hl, center.y + hh, center.z + hw);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(center.x - hl, center.y + hh, center.z - hw);

    glEnd();
}