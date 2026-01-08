#include "Cylinder.h"

Cylinder::Cylinder(Point bc, float r, float h) {
    baseCenter = bc;
    radius = r;
    height = h;
}

void Cylinder::draw() {
    GLUquadric* quad = gluNewQuadric();

    // ÊİÚíá ÊæáíÏ ÅÍÏÇËíÇÊ ÇáÅßÓÇÁ ÊáŞÇÆíÇğ áåĞÇ ÇáÔßá
    gluQuadricTexture(quad, GL_TRUE);

    glPushMatrix();
    glTranslatef(baseCenter.x, baseCenter.y, baseCenter.z);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    // ÑÓã ÌÓã ÇáÃÓØæÇäÉ
    gluCylinder(quad, radius, radius, height, 32, 1);

    // ÑÓã ÇáŞæÇÚÏ
    gluDisk(quad, 0, radius, 32, 1);
    glTranslated(0, 0, height);
    gluDisk(quad, 0, radius, 32, 1);

    glPopMatrix();
    gluDeleteQuadric(quad);
}