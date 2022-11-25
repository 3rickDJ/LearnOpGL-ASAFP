#pragma once
#include <GL/glut.h>
class Textures{
public:
    GLuint	texture[20];
    void loadTextureFromFile(char *filename, int index);
    void activate(int face);
    void deactivate();
};