#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>


#include "Door.h"
#include "Cuboid.h"
#include "Point.h"
#include <math.h>

Door::Door(float h, float z) : height(h), zPos(z), openOffset(0.0f), maxWidth(200.0f) {}

void Door::update(float camX, float camZ) {
    float dist = sqrt(pow(camX, 2) + pow(camZ - zPos, 2));
    if (dist < 600.0f) {
        if (openOffset < 240.0f) openOffset += 5.0f;
    }
    else {
        if (openOffset > 0.0f) openOffset -= 5.0f;
    }
}

void Door::draw() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.6f, 1.0f, 1.0f, 0.4f);
    Cuboid doorL(Point(-100.0f - openOffset, height / 2, zPos), maxWidth, height, 10.0f);
    doorL.draw();
    Cuboid doorR(Point(100.0f + openOffset, height / 2, zPos), maxWidth, height, 10.0f);
    doorR.draw();
    glDisable(GL_BLEND);
}