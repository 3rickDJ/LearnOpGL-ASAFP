#include <valarray>
#include "SnowMan.h"

void SnowMan::drawBody() {
    glColor3f(1.0, 1.0, 1.0);
    glTranslated(0, radius, 0);
    glRotated(degree, 0, 1, 0);
    glutSolidSphere(radius, 20, 20);

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
    if(animateTrans){
        animationTrans();
    }
    if (animateHead) {
        animation();
    }
    glTranslated(tx, ty, tz);
    glRotated(degree, 0, 1, 0);
    glColor3f(1.0, 1.0, 1.0);
    glTranslated(0, radius, 0);
    glutSolidSphere(radius, 20, 20);

//    glPushMatrix();
//    drawButtons();
//    glPopMatrix();
    glColor3f(1, 1, 1);
    glTranslated(0.0f, 1.0, 0.0);
    glPushMatrix();
    glutSolidSphere(0.25, 20, 20);


    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f, 10, 10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);

    glPopMatrix();
    glColor3f(1.0f, 0.5f, 0.5f);
    glutSolidCone(0.08f, 0.5f, 10, 2);
}

SnowMan::SnowMan() {
}

void SnowMan::animation() {
    degree += speedRotation;
}

void SnowMan::drawButtons() {
    float radius  = 0.75;
    float yy,zz;
    float deg=0.9;
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        yy = cos(deg)*radius;
        zz = sin(deg)*radius;
        deg+=0.3;
        glTranslated(0,yy,zz);
        glColor3f(0, 0, 0);
        glutSolidSphere(0.05,10,10);
        glPopMatrix();
    }
}

void SnowMan::animationTrans() {
    if(tx>=0 && tx<=10){
        tx += leftToRigh ? dx:-dx;
    }else{
        tx = leftToRigh ? 0: 10;
    }
}
