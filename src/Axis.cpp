#include "Axis.h"
#include <GL/glut.h>
void Axis::Draw() {
    float X_MIN = -20;
    float X_MAX = 20;
    float Y_MIN = -20;
    float Y_MAX = 20;
    float Z_MIN = -100;
    float Z_MAX = 20;
    glShadeModel(GL_SMOOTH);
    glLineWidth(3.0);
    //X axis in red
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(X_MIN, 0.0, 0.0);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex3f(X_MAX, 0.0, 0.0);
    glEnd();
    //Y axis in green
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0, Y_MIN, 0.0);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.0, Y_MAX, 0.0);
    glEnd();
    //Z axis in blue
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0, 0.0, Z_MIN);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex3f(0.0, 0.0, Z_MAX);
    glEnd();
    glLineWidth(1.0);
}

Axis::Axis() {

}
