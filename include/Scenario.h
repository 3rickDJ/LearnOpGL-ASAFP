#pragma once
#import "Camera.h"
#import "Axis.h"
#import "SnowMan.h"
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