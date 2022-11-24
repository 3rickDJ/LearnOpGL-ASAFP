#include "SnowMan.h"

void SnowMan::drawBody() {
    glColor3f(1.0, 1.0, 1.0);
    glTranslated(0.0, 0.75, 0.0);
    glutSolidSphere(0.75f, 20, 20);
}

void SnowMan::drawHead() {
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

void SnowMan::draw() {
    drawBody();
    drawHead();
    drawEyes();
    drawNose();
}
