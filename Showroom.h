#pragma once

#include <gl/GL.h>
#include "Model_3DS.h"

class Showroom {
private:
    Model_3DS HouseModel;
    float width, height, depth;
    void drawNeonSign(); // œ«·… œ«Œ·Ì… ·—”„ Õ—Ê› «··ÊÕ…
   
public:
    Showroom(float w, float h, float d);
    void draw();
};