#pragma once
class Camera {
    public:
        float angle;
        float speedRotation;
        float x, y, z;
        float lx, ly, lz;
        float upX,upY,upZ;
        float speedMovement;
    Camera();
    void Left();
    void Right();
    void Towards();
    void Backwards();
};
