#include "Light.h"

Light::Light(GLenum id) {
    lightID = id;

    //   (÷Ê¡ √»Ì÷
    float amb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    float diff[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    float spec[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    for (int i = 0; i < 4; i++) {
        ambient[i] = amb[i];
        diffuse[i] = diff[i];
        specular[i] = spec[i];
    }
}

void Light::setPosition(float x, float y, float z) {
    position[0] = x; position[1] = y; position[2] = z; position[3] = 1.0f; // 1.0  ⁄‰Ì ÷Ê¡ „Ê÷⁄Ì
}

void Light::setColors(float r, float g, float b) {
    diffuse[0] = r; diffuse[1] = g; diffuse[2] = b;
}

void Light::enable() {
    glEnable(GL_LIGHTING);
    glEnable(lightID);

    glLightfv(lightID, GL_POSITION, position);
    glLightfv(lightID, GL_AMBIENT, ambient);
    glLightfv(lightID, GL_DIFFUSE, diffuse);
    glLightfv(lightID, GL_SPECULAR, specular);
}

void Light::disable() {
    glDisable(lightID);
}