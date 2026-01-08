#pragma once
#include <gl/GL.h>

class Door {
private:
    float openOffset;
    float height;
    float zPos;
    float maxWidth;

public:
    Door(float h, float z);
    void update(float camX, float camZ);
    void draw();
};