#pragma once

class Camera {
public:
    float angle;
    float speedRotation;
    float x, y, z;
    float lx, ly, lz;
    float upX, upY, upZ;
    float speedMovement;

    Camera();

    void TurnLeft();

    void TurnRight();

    void Towards();

    void Backwards();

    void lookAt();

    void goLeft();

    void goRight();

    void reset();
};
