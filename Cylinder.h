#pragma once

#ifndef CYLINDER_H
#define CYLINDER_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h> 
#include "Point.h"

class Cylinder {
public:
    Point baseCenter; // ãÑßÒ ÇáŞÇÚÏÉ ÇáÓİáì
    float radius;     // äÕİ ÇáŞØÑ
    float height;     // ÇáÇÑÊİÇÚ

    Cylinder(Point bc, float r, float h);
    void draw();
};

#endif


