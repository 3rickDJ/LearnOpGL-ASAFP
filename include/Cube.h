#pragma once
#include "Obstacle.h"
#include "Textures.h"

class Cube : public Obstacle {
    void drawFace(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4,
                  float y4, float z4);

public:
    Cube();

    void draw();

    void addTexture(char *name, int face);

    void animation();
};
