#include <valarray>
#include "Camera.h"
#include <GL/glut.h>

Camera::Camera() {
    reset();
}

void Camera::reset(){
    angle = 0.0;
    speedMovement = 0.16;
    speedRotation = 0.025;
    x = 5;
    y = 1.0;
    z = 50.0;
    lx = 0.0;
    ly = 0.0;
    lz = -1.0;
    upX = 0;
    upY = 1;
    upZ = 0;
}

void Camera::TurnLeft() {
    angle -= speedRotation;
    lx = sin(angle);
    lz = -cos(angle);
}

void Camera::TurnRight() {
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

void Camera::goLeft() {
    if (x > 1.5) {
        x -= speedMovement;
    }
}

void Camera::goRight() {
    if (x < 8.5) {
        x += speedMovement;
    }
}
