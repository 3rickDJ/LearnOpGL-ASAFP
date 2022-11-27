#include <valarray>
#include "Camera.h"
#include <GL/glut.h>

Camera::Camera() {
    reset();
}

void Camera::reset(){
    angle = 0.0;
    speedMovement = 1;
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
    float future_posicion = x + lx * speedMovement;
    bool fueraderango = !(future_posicion>=8.5||future_posicion<=1.5);
    if(fueraderango){
        x += lx * speedMovement;
        z += lz * speedMovement;
    }
}

void Camera::Backwards() {
    float future_posicion = x - lx * speedMovement;
    bool fueraderango = !(future_posicion>=8.5||future_posicion<=1.5);
    if(fueraderango){
        x -= lx * speedMovement;
        z -= lz * speedMovement;
    }
}

void Camera::lookAt() {
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              upX, upY, upZ);
}

void Camera::goLeft() {
    float future_posicion = x - speedMovement;
    bool dentro_de_rango = !(future_posicion>=8.5||future_posicion<=1.5);
    if (dentro_de_rango) {
        x -= speedMovement;
    }
}

void Camera::goRight() {
    float future_posicion = x + speedMovement;
    bool dentro_de_rango = !(future_posicion>=8.5||future_posicion<=1.5);
    if (dentro_de_rango) {
         x += speedMovement;
     }
}
