#include <GL/glut.h>
#include <iostream>
#include <valarray>
#include "Camera.h"
#include "SnowMan.h"
#include "Axis.h"

using namespace std;

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

static void keys(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
        case 'Q':
            exit(0);
            break;
        case 'u':
            break;
        case 'U':
            break;
        case 'h':
            break;
        case 'H':
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

//--------------------------------------------------------------------------
Camera cam;
SnowMan snowMan;
Axis axis;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Reset transformations
    glLoadIdentity();
    // Set the camera

    gluLookAt(cam.x, cam.y, cam.z,
              cam.x + cam.lx, cam.y + cam.ly, cam.z + cam.lz,
              cam.upX, cam.upY, cam.upZ);

    axis.Draw();
    //Draw ground
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex3f(-100, 0, -100);
    glVertex3f(-100, 0, 100);
    glVertex3f(100, 0, 100);
    glVertex3f(100, 0, -100);
    glEnd();
    // Draw 36 SnowMen
    for (int i = -3; i < 3; i++) {
        for (int j = -3; j < 3; ++j) {
            glPushMatrix();
            glTranslated(i * 10, 0, j * 10);
            snowMan.draw();
            glPopMatrix();
        }
    }
    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) 1.0, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:
            break;
        case GLUT_KEY_F2:
            break;
        case GLUT_KEY_F3:
            break;
        case GLUT_KEY_LEFT:
            cam.Left();
            break;
        case GLUT_KEY_RIGHT:
            cam.Right();
            break;
        case GLUT_KEY_UP:
            cam.Towards();
            break;
        case GLUT_KEY_DOWN:
            cam.Backwards();
            break;
    }

};

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangulo a color");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keys);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
