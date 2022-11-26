#pragma once

#include "Textures.h"

class Cube {
    void drawFace(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4,
                  float y4, float z4);

public:
    float x,y,z;
    float tx,ty,tz;
    float radius;
    Cube();

    void draw();

    Textures texture;

    void addTexture(char *name, int face);
    void loadTexture();

    float getX();

    float getZ();

    float getRadius();

    void loadVars(float x, float y, float z, float radius);
};