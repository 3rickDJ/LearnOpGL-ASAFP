#include "Obstacle.h"

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
    this->rotation = rotation;
    this->speedRotation = speedRotation;
}

void Obstacle::loadVars(float x, float y, float z, float radius) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->radius = radius;
    this->tx = x;
    this->ty = y;
    this->tz = z;
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
    this->rotation = 0;
    this->speedRotation = 0;
}
