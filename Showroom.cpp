#include <windows.h>    
#include <initializer_list> 
#include <GL/gl.h>       
#include <GL/glu.h>     
#include "Dependencies/include/gl/glut.h"

#include "Showroom.h"
#include "Cuboid.h"
#include "Point.h"
#include <math.h>
#include "texture.h"
#include "SimpleStreet.h"


Showroom::Showroom(float w, float h, float d) : width(w), height(h), depth(d) {
    // 1. ﬁ«∆„… »√”„«¡ «·’Ê— «·„ «Õ… ⁄‰œﬂ ›Ì «·„Ã·œ
    const char* buildingImages[] = {
        "building.png",
        "building2.png",
        "building3.png"
    };

    float startZ = 2000.0f;  // ‰ﬁÿ… «·»œ«Ì… („‰ «·√„«„)
    float spacing = 1200.0f;  // «·„”«›… »Ì‰ ﬂ· »‰«Ì… Ê»‰«Ì…
    float xPos = -7000.0f;   // „Êﬁ⁄ «·’› ⁄·Ï «·Ì”«— (Œ«—Ã «·„⁄—÷)

    for (int i = 0; i < 5; i++) {
        // ‰Œ «— ’Ê—… „‰ «·ﬁ«∆„… »‘ﬂ· œÊ—Ì
        const char* currentImg = buildingImages[i % 3];

        // ‰Õ”» „Êﬁ⁄ Z ·ﬂ· »‰«Ì… · „ œ ⁄·Ï ÿÊ· «·‘«—⁄
        float zPos = startZ - (i * spacing);

        // ‰‰‘∆ «·»‰«Ì… Ê‰÷Ì›Â« ··„’›Ê›…
        leftStreet.push_back(new Building(
            Point(xPos, -2.0f, zPos),
            700.0f,               // «·⁄—÷
            2000.0f + (i * 100),  // «— ›«⁄«  „ ‰Ê⁄… ·ﬂ”— «·„··
            700.0f,               // «·⁄„ﬁ
            currentImg
        ));
    }

  
    
    
     sideRoad = new SimpleStreet(Point(-4500.0f, -1.9f, 0.0f), 2000.0f, 12000.0f, true);

    
   
    frontRoad = new SimpleStreet(Point(2000.0f, -1.9f, 5000.0f), 2000.0f, 11000.0f, false);
 


    // œ«Œ· Showroom.cpp ›Ì «·‹ Constructor
    float laneWidth = 800.0f;  // ⁄—÷ „”«— «·ﬂ—«Ã «·Ê«Õœ
    float laneLength = 6500.0f; // ÿÊ· «·ﬂ—«Ã
    float startX = 4000.0f;    // ‰ﬁÿ… »œ«Ì… «·ﬂ—«Ã ⁄·Ï Ì„Ì‰ «·„⁄—÷
    float parkingZ = 1000.0f;   // „Êﬁ⁄ «·ﬂ—«Ã »«·‰”»… ·⁄„ﬁ «·„‘Âœ

    for (int i = 0; i < 5; i++) {
        // ≈“«Õ… ﬂ· „”«— ⁄‰ «·–Ì ﬁ»·Â »„ﬁœ«— laneWidth
        parkingLanes[i] = new SimpleStreet(
            Point(startX + (i * laneWidth), -1.9f, parkingZ),
            laneWidth,
            laneLength,
            true, // true ·ÌﬂÊ‰ ÿÊ·Ì« „À· «·„Ê«ﬁ›
            1.0f, 1.0f, 0.0f
        );
    }
   //»‰«Ì«  Ã«‰»Ì… 
    // 1. ﬁ«∆„… ’Ê— ÃœÌœ… ·ﬂ”— «· ﬂ—«—
    const char* rightBuildingImages[] = {
        "building3.png", //  √ﬂœÌ „‰ ÊÃÊœ Â–Â «·’Ê— ›Ì „Ã·œ «·„‘—Ê⁄
        "building4.png",
        "building5.png"
    };

    float startZ_Right = 2000.0f;
    float spacing_Right = 1500.0f;
    float xPos_Right = 9500.0f; // «·„Êﬁ⁄ ⁄·Ï «·Ì„Ì‰ (»⁄œ «·ﬂ—«Ã Ê«·Ãœ«—)

    for (int i = 0; i < 4; i++) {
        const char* currentImg = rightBuildingImages[i % 3];
        float zPos = startZ_Right - (i * spacing_Right);

        rightStreet.push_back(new Building(
            Point(xPos_Right, -2.0f, zPos),
            800.0f,               // «·⁄—÷
            2200.0f + (i * 150),  // «— ›«⁄«  „Œ ·›…
            800.0f,               // «·⁄„ﬁ
            currentImg
        ));
    }
    
  
}


void Showroom::drawNeonSign() {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glLineWidth(5.0f);
    glPushMatrix();

    // Ê÷⁄ «··ÊÕ… ›Ì √⁄·Ï «·Ê«ÃÂ…
    glTranslatef(-700.0f, height - 350.0f, depth / 2 + 20.0f);
    glScalef(4.0f, 4.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    // «·≈ÿ«— «·Œ«—ÃÏ
    glBegin(GL_LINE_LOOP);
    glVertex2f(-10, -5); glVertex2f(460, -5);
    glVertex2f(460, 65); glVertex2f(-10, 65);
    glEnd();

    // —”„ Õ—Ê› CAR SHOWROOM
    // Õ—› C
    glBegin(GL_LINE_STRIP); glVertex2f(30, 45); glVertex2f(5, 45); glVertex2f(5, 10); glVertex2f(30, 10); glEnd();

    // Õ—› A
    glPushMatrix(); glTranslatef(40.0f, 0, 0);
    glBegin(GL_LINE_STRIP); glVertex2f(0, 10); glVertex2f(15, 45); glVertex2f(30, 10); glEnd();
    glBegin(GL_LINES); glVertex2f(7, 27); glVertex2f(23, 27); glEnd();

    // Õ—› R
    glTranslatef(40.0f, 0, 0);
    glBegin(GL_LINE_STRIP); glVertex2f(0, 10); glVertex2f(0, 45); glVertex2f(25, 45); glVertex2f(25, 27); glVertex2f(0, 27); glEnd();
    glBegin(GL_LINES); glVertex2f(10, 27); glVertex2f(25, 10); glEnd();

    // Õ—› S
    glTranslatef(75.0f, 0, 0);
    glBegin(GL_LINE_STRIP); glVertex2f(30, 45); glVertex2f(5, 45); glVertex2f(5, 27); glVertex2f(30, 27); glVertex2f(30, 10); glVertex2f(5, 10); glEnd();

    // Õ—› H
    glTranslatef(40.0f, 0, 0);
    glBegin(GL_LINES); glVertex2f(0, 45); glVertex2f(0, 10); glVertex2f(25, 45); glVertex2f(25, 10); glVertex2f(0, 27); glVertex2f(25, 27); glEnd();

    // Õ—› O
    glTranslatef(35.0f, 0, 0);
    glBegin(GL_LINE_LOOP); glVertex2f(0, 45); glVertex2f(25, 45); glVertex2f(25, 10); glVertex2f(0, 10); glEnd();

    // Õ—› W
    glTranslatef(35.0f, 0, 0);
    glBegin(GL_LINE_STRIP); glVertex2f(0, 45); glVertex2f(5, 10); glVertex2f(12, 30); glVertex2f(20, 10); glVertex2f(25, 45); glEnd();

    // Õ—› R
    glTranslatef(35.0f, 0, 0);
    glBegin(GL_LINE_STRIP); glVertex2f(0, 10); glVertex2f(0, 45); glVertex2f(25, 45); glVertex2f(25, 27); glVertex2f(0, 27); glEnd();
    glBegin(GL_LINES); glVertex2f(10, 27); glVertex2f(25, 10); glEnd();

    // Õ—› O (ﬂ——)
    glTranslatef(35.0f, 0, 0); glBegin(GL_LINE_LOOP); glVertex2f(0, 45); glVertex2f(25, 45); glVertex2f(25, 10); glVertex2f(0, 10); glEnd();

    // Õ—› O (ﬂ—— À«‰)
    glTranslatef(35.0f, 0, 0); glBegin(GL_LINE_LOOP); glVertex2f(0, 45); glVertex2f(25, 45); glVertex2f(25, 10); glVertex2f(0, 10); glEnd();

    // Õ—› M
    glTranslatef(35.0f, 0, 0);
    glBegin(GL_LINE_STRIP); glVertex2f(0, 10); glVertex2f(0, 45); glVertex2f(17, 25); glVertex2f(34, 45); glVertex2f(34, 10); glEnd();

    glPopMatrix();
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

void Showroom::draw() {
    glEnable(GL_DEPTH_TEST); //  √ﬂœÌ „‰  ›⁄Ì· «Œ »«— «·⁄„ﬁ
    glDepthFunc(GL_LEQUAL);  // Ì”„Õ »—”„ «·√”ÿÕ «·„ ﬁ«—»… Ãœ« œÊ‰ „‘«ﬂ·
    // 1. «·√—÷Ì… «·√”«”Ì… (”Êœ«¡  „«„«)
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glColor3f(0.05f, 0.05f, 0.05f); // √”Êœ
    Cuboid ground(Point(0, -2.5f, 0), 100000.0f, 0.1f, 100000.0f);
    ground.draw();


    // 2. —”„ «·‘Ê«—⁄ «·ÃœÌœ… («· Ì  Õ ÊÌ ⁄·Ï ŒÿÊÿÂ« »œ«Œ·Â«)
    if (sideRoad) sideRoad->draw();
    if (frontRoad) frontRoad->draw();
    //«·ﬂ—«Ã
    for (int i = 0; i < 5; i++) {
        if (parkingLanes[i]) parkingLanes[i]->draw();
    }



    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // «· √ﬂÌœ ⁄·Ï «··Ê‰ «·√»Ì÷ ·ŸÂÊ— ’Ê—… «·Ãœ«— »Ê÷ÊÕ

    // —”„ »«ﬁÌ «·»‰«Ì« 
    for (auto b : leftStreet) { if (b) b->draw(); }

    // 4. *** ≈⁄«œ…  ÂÌ∆… «·„⁄—÷ (Â«„ Ãœ«) ***
    glEnable(GL_LIGHTING);    // ≈⁄«œ…  ›⁄Ì· «·≈÷«¡… ··„⁄—÷
    glDisable(GL_TEXTURE_2D); //  ⁄ÿÌ· «· ﬂ ‘— ·ﬂÌ ·« Ì’»€ «·Ãœ—«‰
    glColor3f(1.0f, 1.0f, 1.0f); // ≈⁄«œ… «··Ê‰ ··√»Ì÷ ·ﬂÌ  ⁄„· «·≈÷«¡… »‘ﬂ· ’ÕÌÕ

    // —”„ ’› «·»‰«Ì«  «·Ì”«—Ì («·ﬁœÌ„)
    glEnable(GL_TEXTURE_2D);
    for (auto b : leftStreet) { if (b) b->draw(); }

    // —”„ ’› «·»‰«Ì«  «·Ì„Ì‰Ì («·ÃœÌœ)
    for (auto b : rightStreet) { if (b) b->draw(); }

    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // ≈⁄«œ… «··Ê‰ ··√»Ì÷ ·ﬂÌ  ⁄„· «·≈÷«¡… »‘ﬂ· ’ÕÌÕ

    float stepX = 400.0f;
    float stepZ = 400.0f;

    // «·√⁄„œ… Ê«·“Ã«Ã
    for (float x = -width / 2; x <= width / 2; x += stepX) {
        for (float z : {-depth / 2, depth / 2}) {
            glColor3f(0.15f, 0.15f, 0.15f);
            Cuboid p(Point(x, height / 2, z), 25.0f, height, 25.0f);
            p.draw();

            if (x < width / 2) {
                if (z > 0 && fabsf(x + stepX / 2) < 250.0f) continue;
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glColor4f(0.5f, 0.8f, 1.0f, 0.25f);
                Cuboid g(Point(x + stepX / 2, height / 2, z), stepX, height, 4.0f);
                g.draw();
                glDisable(GL_BLEND);
            }
        }
    }

    // «·√⁄„œ… «·Ã«‰»Ì…
    for (float z = -depth / 2; z <= depth / 2; z += stepZ) {
        for (float x : {-width / 2, width / 2}) {
            glColor3f(0.15f, 0.15f, 0.15f);
            Cuboid sideP(Point(x, height / 2, z), 25.0f, height, 25.0f);
            sideP.draw();
            if (z < depth / 2) {
                glEnable(GL_BLEND);
                glColor4f(0.5f, 0.8f, 1.0f, 0.25f);
                Cuboid sideG(Point(x, height / 2, z + stepZ / 2), 4.0f, height, stepZ);
                sideG.draw();
                glDisable(GL_BLEND);
            }
        }
    }

    // «·”ﬁ›
    glColor3f(0.05f, 0.05f, 0.05f);
    Cuboid roof(Point(0, height, 0), width + 100.0f, 40.0f, depth + 100.0f);
    roof.draw();
    drawNeonSign();
}

  