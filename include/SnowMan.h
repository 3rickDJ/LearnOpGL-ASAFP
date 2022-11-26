#pragma once

#include <GL/glut.h>

class SnowMan {
public:
    SnowMan();
    float degree;
    float speedRotation;
    float colorBody[3];
    float posBody[3];

    void drawBody();

    float colorHead[3];
    float posHead[3];

    void drawHead();

    float colorEyes[3];
    float posEyes[3];

    void drawEyes();

    float posNose[3];
    float colorNose[3];

    void drawNose();

    void animation();

public:
    void draw();
};
