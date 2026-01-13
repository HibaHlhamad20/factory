
#pragma once
/*
#include "Cuboid.h"
#include "Texture.h"

class Street {
public:
    Point pos;
    float w, h, d;
    Texture tex;

    Street(Point p, float _w, float _h, float _d, const char* path)
        : pos(p), w(_w), h(_h), d(_d) {
        tex.load((char*)path);
    }

    void draw() {
        glEnable(GL_TEXTURE_2D);
        tex.use();
        glColor3f(1.0f, 1.0f, 1.0f); // ·÷„«‰ ŸÂÊ— √·Ê«‰ «·≈”›·  «·ÕﬁÌﬁÌ…

        // —”„ «·‘«—⁄ ﬂ„ﬂ⁄» „”ÿÕ Ãœ«
        Cuboid road(pos, w, h, d);
        road.draw();

        glDisable(GL_TEXTURE_2D);
    }
};*/
#ifndef SIMPLESTREET_H
#define SIMPLESTREET_H

#include "Dependencies/include/gl/glut.h"
#include "Point.h"

class SimpleStreet {
private:
    Point position;
    float width;   // «·⁄—÷ (⁄·Ï „ÕÊ— X √Ê Z Õ”» «·« Ã«Â)
    float length;  // «·ÿÊ·
    bool isVertical; // Â· «·‘«—⁄ ÿÊ·Ì („ÕÊ— Z) √„ ⁄—÷Ì („ÕÊ— X)
    float r, g, b; // ≈÷«›… „ €Ì—«  ··Ê‰ «·ŒÿÊÿ

public:
   /* SimpleStreet(Point pos, float w, float l, bool vertical)
        : position(pos), width(w), length(l), isVertical(vertical) {
    }*/
    SimpleStreet(Point pos, float w, float l, bool vertical, float red = 1.0f, float green = 1.0f, float blue = 1.0f)
        : position(pos), width(w), length(l), isVertical(vertical), r(red), g(green), b(blue) {
    }

    void draw() {
        glDisable(GL_LIGHTING); // ·÷„«‰ À»«  «··Ê‰ «·—„«œÌ

        // 1. —”„ Ã”„ «·‘«—⁄ («·√”›· )
        glColor3f(0.2f, 0.2f, 0.2f); // —„«œÌ €«„ﬁ
        glBegin(GL_QUADS);
        if (isVertical) { // ‘«—⁄ „Ê«“Ì ··»‰«Ì« 
            glVertex3f(position.x - width / 2, position.y, position.z - length / 2);
            glVertex3f(position.x + width / 2, position.y, position.z - length / 2);
            glVertex3f(position.x + width / 2, position.y, position.z + length / 2);
            glVertex3f(position.x - width / 2, position.y, position.z + length / 2);
        }
        else { // ‘«—⁄ „Ê«“Ì ·Ê«ÃÂ… «·„⁄—÷
            glVertex3f(position.x - length / 2, position.y, position.z - width / 2);
            glVertex3f(position.x + length / 2, position.y, position.z - width / 2);
            glVertex3f(position.x + length / 2, position.y, position.z + width / 2);
            glVertex3f(position.x - length / 2, position.y, position.z + width / 2);
        }
        glEnd();

        // 2. —”„ «·ŒÿÊÿ «·»Ì÷«¡ «·„ ﬁÿ⁄…
        glColor3f(r, g, b); // Â‰« ”Ì „  ÿ»Ìﬁ «··Ê‰ «·„„——
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        if (isVertical) {
            for (float i = -length / 2; i < length / 2; i += 500) {
                glVertex3f(position.x, position.y + 0.1f, position.z + i);
                glVertex3f(position.x, position.y + 0.1f, position.z + i + 250);
            }
        }
        else {
            for (float i = -length / 2; i < length / 2; i += 500) {
                glVertex3f(position.x + i, position.y + 0.1f, position.z);
                glVertex3f(position.x + i + 250, position.y + 0.1f, position.z);
            }
        }
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);

        glEnable(GL_LIGHTING);
    }
};

#endif