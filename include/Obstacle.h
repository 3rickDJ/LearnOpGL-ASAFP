#pragma once
#include "Textures.h"

class Obstacle {
public:
    Obstacle();
    float x,y,z;
    float tx, ty, tz;
    float radius;
    float dx,dy,dz;
    float degree;
    float speedRotation;
    bool leftToRigh;
    Textures texture;

    void loadVars(float x, float y, float z, float dx, float dy, float dz, float rotation, float speedRotation,
                  float radius, bool leftToRight);
    void loadVars(float x, float y, float z, float radius);

    void reset();

    float getX();

    float getZ();

    float getRadius();

    void loadTexture(int num_textures, ...);
};