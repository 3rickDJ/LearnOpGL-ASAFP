#pragma once

class Obstacle {
public:
    Obstacle();
    float x,y,z;
    float tx, ty, tz;
    float radius;
    float dx,dy,dz;
    float rotation;
    float speedRotation;

    void loadVars(float x, float y, float z, float dx, float dy, float dz, float rotation, float speedRotation,
                  float radius);
    void loadVars(float x, float y, float z, float radius);
};