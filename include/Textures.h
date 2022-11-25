#pragma once
#include <GL/glut.h>
class Textures{
public:
    GLuint	texture[20];
    void static loadTextureFromFile(char *filename, int index);
    void activate(int face);
    void deactivate();
};