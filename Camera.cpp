

#include "Camera.h"


Camera::Camera() {
    x = 0.0f; y = 70.0f; z = 600.0f; // äÞØÉ ÈÏÇíÉ ãäÇÓÈÉ
    yaw = -1.57f; // ÇáäÙÑ ÈÇÊÌÇå ÇáãÚÑÖ
    pitch = 0.0f;
    moveSpeed = 3.5f; // ÓÑÚÉ åÇÏÆÉ æØÈíÚíÉ
    updateLookAt(0, 0);
}

void Camera::updateLookAt(float xOffset, float yOffset) {
    yaw += xOffset * 0.005f;   // ÍÓÇÓíÉ ÇáãÇæÓ
    pitch -= yOffset * 0.005f;

    // ÍãÇíÉ ãä ÇäÞáÇÈ ÇáßÇãíÑÇ ÚäÏ ÇáäÙÑ ááÃÚáì/ÇáÃÓÝá
    if (pitch > 1.5f) pitch = 1.5f;
    if (pitch < -1.5f) pitch = -1.5f;

    viewX = x + cos(pitch) * cos(yaw);
    viewY = y + sin(pitch);
    viewZ = z + cos(pitch) * sin(yaw);
}

void Camera::render() {
    gluLookAt(x, y, z, viewX, viewY, viewZ, 0, 1, 0);
}

void Camera::moveForward(float direction, float boundaryW, float boundaryD) {
    float nextX = x + cos(yaw) * direction * moveSpeed;
    float nextZ = z + sin(yaw) * direction * moveSpeed;

    // ãÈÏÃ ÇáÕÏã (Collision Detection) áÚÏã ÊÎØí ÇáÌÏÑÇä Ãæ ÇáÜ Skybox
    if (fabs(nextX) < boundaryW && fabs(nextZ) < boundaryD) {
        x = nextX;
        z = nextZ;
    }
    updateLookAt(0, 0);
}

void Camera::moveSide(float direction, float boundaryW, float boundaryD) {
    float nextX = x + cos(yaw + 1.57f) * direction * moveSpeed;
    float nextZ = z + sin(yaw + 1.57f) * direction * moveSpeed;

    if (fabs(nextX) < boundaryW && fabs(nextZ) < boundaryD) {
        x = nextX;
        z = nextZ;
    }
    updateLookAt(0, 0);
}