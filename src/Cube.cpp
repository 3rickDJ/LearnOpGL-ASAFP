#include "Cube.h"
#include <GL/glut.h>
Cube::Cube() {
}

void Cube::addTexture(char *name, int face) {
    texture.loadTextureFromFile(name, face);
}

void Cube::draw() {
    glTranslated(3, 1, 3);
    glColor3f(1.0,1.0,1.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // Texture binding
    texture.activate(0);
    drawFace(-1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0);
    texture.activate(1);
    drawFace(1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0);
    texture.activate(2);
    drawFace(1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0);
    texture.activate(3);
    drawFace(-1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0);
    texture.deactivate();
    // restore the matrix
}

void Cube::drawFace(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4,
                    float y4, float z4) {
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(x1, y1, z1);

    glTexCoord2f(0.0, 1.0);
    glVertex3f(x2, y2, z2);

    glTexCoord2f(1.0, 1.0);
    glVertex3f(x3, y3, z3);

    glTexCoord2f(1.0, 0.0);
    glVertex3f(x4, y4, z4);
    glEnd();

}

void Cube::loadTexture() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    char* filename0 = "../container.jpg";
    char *filename1 = "../textura1.bmp";
    char *filename2 = "../textura2.bmp";
    char *filename3 = "../textura3.bmp";
    char *filename4 = "../textura4.bmp";
    char *filename5 = "../textura5.bmp";
    texture.loadTextureFromFile(filename0,0);
    texture.loadTextureFromFile(filename1, 1);
    texture.loadTextureFromFile(filename2,2);
    texture.loadTextureFromFile(filename3,3);
    texture.loadTextureFromFile(filename4,4);
    texture.loadTextureFromFile(filename5,5);
}

float Cube::getX() {
    return this->x;
}

float Cube::getZ() {
    return this->z;
}

float Cube::getRadius() {
    return this->radius;
}
