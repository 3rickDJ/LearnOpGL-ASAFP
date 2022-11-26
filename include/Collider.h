#pragma once
#include "Player.h"

class Collider{
public:
    Collider();
    bool isColliding(Player player, float x, float z, float radius);
};