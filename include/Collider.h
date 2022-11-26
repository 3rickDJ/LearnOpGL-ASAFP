#pragma once
#include "Player.h"
#include "SnowMan.h"
#include "Cube.h"
#include <vector>
using namespace std;

class Collider{
public:
    Collider();
    bool isColliding(Player player, float x, float z, float radius);

    void player(Player *pPlayer);
    Player *pPlayer;
    vector<Obstacle*> obstacles;

    void attach(Obstacle *pObs);

    void watch();
};