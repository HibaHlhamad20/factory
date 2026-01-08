#pragma once


#ifndef CAMERA_H
#define CAMERA_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

class Camera {
public:
    float x, y, z;          // ãæŞÚ ÇáßÇãíÑÇ
    float viewX, viewY, viewZ; // ÇáäŞØÉ ÇáÊí ÊäÙÑ ÅáíåÇ

    // ãÊÛíÑÇÊ ÇáãÇæÓ æÇáÏæÑÇä
    float yaw;   // ÇáÏæÑÇä ÇáÃİŞí
    float pitch; // ÇáäÙÑ ááÃÚáì æÇáÃÓİá
    float moveSpeed; // ÓÑÚÉ ÇáÍÑßÉ ÇáãÈØÆÉ

    Camera();
    void render();
    void moveForward(float direction, float boundaryW, float boundaryD); // ÍÑßÉ ãÚ ÊÕÇÏã
    void moveSide(float direction, float boundaryW, float boundaryD);    // ÍÑßÉ ÌÇäÈíÉ
    void updateLookAt(float xOffset, float yOffset); // ÊÍÏíË ÇáäÙÑ ÈÇáãÇæÓ
};

#endif