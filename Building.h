#pragma once
#include <windows.h>
#include "Dependencies/include/gl/glut.h"
#include "Cuboid.h"
#include "Texture.h"

class Building {
public:
    Point pos;        // ãæŞÚ ÇáÈäÇíÉ
    float w, h, d;    // ÇáÚÑÖ¡ ÇáÇÑÊİÇÚ¡ ÇáÚãŞ
    Texture tex;      // ÕæÑÉ ÇáæÇÌåÉ

    // ÇáãÔíÏ: íÃÎĞ (ÇáãæŞÚ¡ ÇáÚÑÖ¡ ÇáÇÑÊİÇÚ¡ ÇáÚãŞ¡ ãÓÇÑ ÇáÕæÑÉ)
    Building(Point p, float _w, float _h, float _d, const char* texturePath)
        : pos(p), w(_w), h(_h), d(_d) {
        tex.load((char*)texturePath);
    }

    void draw() {
        glEnable(GL_TEXTURE_2D);
        tex.use();

        // ÑÓã ÇáÈäÇíÉ ßãßÚÈ (Cuboid)
        // ãáÇÍÙÉ: ÌÚáäÇ ÇáÜ y åæ ÇáÇÑÊİÇÚ/2 áÊŞİ ÇáÈäÇíÉ ÊãÇãÇğ Úáì ÇáÃÑÖ
        Cuboid block(Point(pos.x, pos.y + h / 2, pos.z), w, h, d);
        block.draw();

        glDisable(GL_TEXTURE_2D);
    }
};