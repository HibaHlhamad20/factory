#pragma once

#ifndef SPHERE_H
#define SPHERE_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Point.h"

class Sphere {
public:
    Point center;
    float radius;

    Sphere(Point c, float r);
    void draw();
};

#endif