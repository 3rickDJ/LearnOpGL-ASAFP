#include "Cube.h"
#include <GL/glut.h>
Cube::Cube() {
    reset();
}

void Cube::addTexture(char *name, int face) {
    texture.loadTextureFromFile(name, face);
}

void Cube::draw() {
    animation();
    glTranslated(tx, ty, tz);
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
    glColor4f(1,1,1,0.2);
    glutSolidSphere(radius, 10, 10);
    glColor3f(1,1,1);
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

void Cube::animation(){
    if(tx>=0 && tx<=10){
        if(leftToRigh){
            tx += dx*10;
        } else{
            tx -= dx;
        }
    }else{
        if(leftToRigh){
            tx = 0;
        } else{
            tx = 10;
        }
    }
}
