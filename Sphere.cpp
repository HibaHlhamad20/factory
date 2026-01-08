#include "Sphere.h"

Sphere::Sphere(Point c, float r) {
    center = c;
    radius = r;
}

void Sphere::draw() {
    GLUquadric* quad = gluNewQuadric();

    // ÊİÚíá ÊæáíÏ ÅÍÏÇËíÇÊ ÇáÅßÓÇÁ ÊáŞÇÆíÇğ ááßÑÉ
    gluQuadricTexture(quad, GL_TRUE);

    glPushMatrix();
    glTranslatef(center.x, center.y, center.z);

    // ÑÓã ÇáßÑÉ ÈÇáÊŞÓíãÇÊ ÇáãØáæÈÉ
    gluSphere(quad, radius, 32, 32);

    glPopMatrix();
    gluDeleteQuadric(quad);
}