#include <valarray>
#include "Camera.h"
#include <GL/glut.h>

Camera::Camera() {
    angle = 0.0;
    speedMovement = 0.2;
    speedRotation = 0.02;
    x = 0;
    y = 1.0;
    z = 5.0;
    lx = 0.0;
    ly = 0.0;
    lz = -1.0;
    upX = 0;
    upY = 1;
    upZ = 0;
}

void Camera::Left() {
    angle -= speedRotation;
    lx = sin(angle);
    lz = -cos(angle);
}

void Camera::Right() {
    angle += speedRotation;
    lx = sin(angle);
    lz = -cos(angle);
}

void Camera::Towards() {
    x += lx * speedMovement;
    z += lz * speedMovement;
}

void Camera::Backwards() {
    x -= lx * speedMovement;
    z -= lz * speedMovement;
}

void Camera::lookAt() {
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              upX, upY, upZ);
}
