#pragma once
#include "Camera.h"
#include "Axis.h"
#include "SnowMan.h"
#include "Cube.h"
#include "Player.h"
#include "Collider.h"

class Scenario {
public:
    Player player;
    SnowMan snowMan;
    Cube cube;
    Collider collider;
    int width, height, nrChannels;
    Axis axis;
    Scenario();
    void display();
    void keys(unsigned char key, int x, int y);
    void specialKeys(int key, int x, int y);
    void reshape(int width, int height);
    void init();
    void loadTextures();
    void environment();
};
