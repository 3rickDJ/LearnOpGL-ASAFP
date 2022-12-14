#include "Obstacle.h"
#include <stdarg.h>
Obstacle::Obstacle() {
    reset();
}

void Obstacle::loadVars(float x, float y, float z, float dx, float dy, float dz, float rotation, float speedRotation,
                        float radius, bool leftToRight) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
    this->radius = radius;
    this->tx = x;
    this->ty = y;
    this->tz = z;
    this->degree = rotation;
    this->speedRotation = speedRotation;
    this->leftToRigh = leftToRight;
}

void Obstacle::loadVars(float x, float y, float z, float radius) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->radius = radius;
    this->tx = x;
    this->ty = y;
    this->tz = z;
    this->leftToRigh =true;
}

void Obstacle::reset() {
    this->leftToRigh = true;
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->dx = 0;
    this->dy = 0;
    this->dz = 0;
    this->radius = 0;
    this->tx = 0;
    this->ty = 0;
    this->tz = 0;
    this->degree = 0;
    this->speedRotation = 0;
}

float Obstacle::getX() {
    return tx;
}

float Obstacle::getZ() {
    return tz;
}

float Obstacle::getRadius() {
    return radius;
}

void Obstacle::loadTexture(int num_textures, ...) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    va_list args;
    va_start(args,num_textures);

    for (int i = 0; i < num_textures; ++i) {
        char * file = va_arg(args,char*);
        texture.loadTextureFromFile(file,i);
    }
}
