#pragma once
#ifndef CUBOID_H
#define CUBOID_H

#include <windows.h>
#include <gl/GL.h> // ãßÊÈÉ OpenGL ÇáÃÓÇÓíÉ
#include "Point.h"

class Cuboid {
public:
    Point center;    // ãÑßÒ ÇáãßÚÈ
    float length;    // ÇáØæá (Úáì ãÍæÑ x)
    float height;    // ÇáÇÑÊİÇÚ (Úáì ãÍæÑ y)
    float width;     // ÇáÚÑÖ (Úáì ãÍæÑ z)

    Cuboid(Point c, float l, float h, float w);
    void draw(); // ÏÇáÉ ÇáÑÓã
};

#endif