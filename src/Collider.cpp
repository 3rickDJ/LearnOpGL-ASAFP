#include "Collider.h"

bool Collider::isColliding(Player player, float x, float z, float radius) {
    if (z + radius+1 < player.cam.z) {
        return false;
    }
    float a = player.cam.x - 1;
    float b = player.cam.x + 1;
    float c = x - radius;
    float d = x + radius;
    if(b < c){
        return false;
    }
    if(a>d) {
        return false;
    }
    return true;
}

Collider::Collider() {

}
