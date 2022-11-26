#include "Collider.h"
#include <iostream>
using namespace std;

bool Collider::isColliding(Player player, float x, float z, float radius) {
    float pZ = player.cam.z;
    float pX = player.cam.x;
    float a = pX - 1;
    float b = pX + 1;
    float c = x - radius;
    float d = x + radius;
    float deepFar = z - radius;
    float deepNear = z + radius;
    bool inRange = deepNear >= pZ && pZ >= deepFar;
    bool colliding = !(b < c || a > d);
    if(inRange && colliding){
        return true;
    }
    return false;
}

Collider::Collider() {

}
