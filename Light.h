#pragma once

#ifndef LIGHT_H
#define LIGHT_H

#include <windows.h>
#include <gl/GL.h>

class Light {
public:
    GLenum lightID;       // ÑŞã ÇáÖæÁ (ãËáÇğ GL_LIGHT0)
    float position[4];    // ãæŞÚ ÇáÖæÁ (x, y, z, w)
    float ambient[4];     // ÇáÖæÁ ÇáãÍíØ (Îİíİ ÌÏÇğ)
    float diffuse[4];     // ÇáÖæÁ ÇáãäÊÔÑ (Çááæä ÇáÃÓÇÓí ááÖæÁ)
    float specular[4];    // ÇáÖæÁ ÇáÇäÚßÇÓí (ááãÚÇä Úáì ÃÓØÍ)

    Light(GLenum id);
    void setPosition(float x, float y, float z);
    void setColors(float r, float g, float b);
    void enable();        // ÊÔÛíá ÇáÖæÁ
    void disable();       // ÅØİÇÁ ÇáÖæÁ
};

#endif