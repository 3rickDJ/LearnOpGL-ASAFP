#include <valarray>
#include "SnowMan.h"

void SnowMan::drawBody() {
    glColor3f(1.0, 1.0, 1.0);
    glTranslated(0.0, 0.75, 0.0);
    glRotated(degree, 0, 1, 0);
    glutSolidSphere(0.75f, 20, 20);

}

void SnowMan::drawHead() {
    glColor3f(1, 1, 1);
    glTranslated(0.0f, 1.0, 0.0);
    glutSolidSphere(0.25, 20, 20);
}

void SnowMan::drawEyes() {
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f, 10, 10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);
    glPopMatrix();
}

void SnowMan::drawNose() {
    glColor3f(1.0f, 0.5f, 0.5f);
    glutSolidCone(0.08f, 0.5f, 10, 2);
}

void SnowMan::draw(bool animateHead, bool animateTrans) {
    glTranslated(tx, ty, tz);
    drawBody();
    drawButtons();
    drawHead();
    drawEyes();
    drawNose();
    if (animateHead)
        animation();
    if(animateTrans)
        animationTrans();
}

SnowMan::SnowMan() {
    speedRotation = 0.04;
    degree = 0;
}

void SnowMan::animation() {
    degree += speedRotation;
}

void SnowMan::drawButtons() {
    float radius  = 0.75;
    float y,z;
    float deg=0.9;
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        y = cos(deg)*radius;
        z = sin(deg)*radius;
        deg+=0.3;
        glTranslated(0,y,z);
        glColor3f(0, 0, 0);
        glutSolidSphere(0.05,10,10);
        glPopMatrix();
    }
}

void SnowMan::animationTrans() {
    if(tx>=0 && tx<=10){
        tx += dx;
    }else{
        tx = leftToRigh ? 10: 0;
    }
}
