#include <windows.h>    
#include <initializer_list> 
#include <GL/gl.h>       
#include <GL/glu.h>     
#include "Dependencies/include/gl/glut.h"

#include "Showroom.h"
#include "Model_3DS.h"
#include "Cuboid.h"
#include "Point.h"
#include <math.h>


Showroom::Showroom(float w, float h, float d) : width(w), height(h), depth(d) {

    HouseModel.Load((char*)"House.3ds");

    
   /* HouseModel.pos = Point(0, 0, 0);*/

    HouseModel.pos.x = 0;
    HouseModel.pos.y = 0;
    HouseModel.pos.z = 0;
  
    HouseModel.scale = 0.5f;



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
    // «·√—÷Ì… «·”Êœ«¡ («·√”›· )
    glColor3f(0.1f, 0.1f, 0.12f);
    Cuboid ground(Point(0, -2.0f, 0), 100000.0f, 4.0f, 100000.0f);
    ground.draw();

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
    /// ﬂ‰  ⁄„ ÷Ì› „Êœ·

    glEnable(GL_LIGHTING);

   
    glPushMatrix();
   
     glTranslatef(500.0f, 0.0f, -600.0f); 

    HouseModel.Draw(); 
    glPopMatrix();

    glDisable(GL_LIGHTING);


    drawNeonSign();
}