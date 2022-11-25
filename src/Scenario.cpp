#include "Scenario.h"
#include <GL/glut.h>
void Scenario::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Reset transformations
    glLoadIdentity();
    // Set the camera

    cam.lookAt();
    axis.Draw();
    cube.draw();
    glPushMatrix();
        glTranslated(1,1,1);
        glutSolidTeapot(1);
    glPopMatrix();
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

Scenario::Scenario() {

}

void Scenario::keys(unsigned char key, int x, int y) {
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

void Scenario::specialKeys(int key, int x, int y) {

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
}

void Scenario::reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

void Scenario::init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) 1.0, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    //load textures
    char* filename0 = "textura0.bmp";
    cube.texture.loadTextureFromFile(filename0,0);
    char *filename1 = "textura1.bmp";
    char *filename2 = "textura2.bmp";
    char *filename3 = "textura3.bmp";
    char *filename4 = "textura4.bmp";
    char *filename5 = "textura5.bmp";

    cube.texture.loadTextureFromFile(filename1, 1);
    cube.texture.loadTextureFromFile(filename2,2);
    cube.texture.loadTextureFromFile(filename3,3);
    cube.texture.loadTextureFromFile(filename4,4);
    cube.texture.loadTextureFromFile(filename5,0);
}

