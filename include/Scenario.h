#pragma once
#include "Camera.h"
#include "Axis.h"
#include "SnowMan.h"
class Scenario {
public:
    Camera cam;
    SnowMan snowMan;
    Axis axis;
    Scenario();
    void display();
    void keys(unsigned char key, int x, int y);
    void specialKeys(int key, int x, int y);
    void reshape(int width, int height);
    void init();
};