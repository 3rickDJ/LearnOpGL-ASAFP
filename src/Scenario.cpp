#include "Scenario.h"
#include "stb_image.h"
#include <GL/glut.h>
void Scenario::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Reset transformations
    glLoadIdentity();
    // Set the camera
    cam.lookAt();
    glPushMatrix();
    glTranslated(3, 0, 3);
    cube.draw();
    glPopMatrix();
    axis.Draw();
//    glPushMatrix();
//        glTranslated(1,1,1);
//        glutSolidTeapot(1);
//    glPopMatrix();
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
//            snowMan.draw();
            glPopMatrix();
        }
    }
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(0, 1, 0);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[0]);
    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture( qobj, GL_TRUE );
    gluSphere( qobj, 1.0f, 20, 20 );
    gluDeleteQuadric( qobj );
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
//    anguloSol = (anguloSol + 0.1 > 360) ? 0.0 : anguloSol + 0.1;

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
    loadTextures();
}

void Scenario::loadTextures() {
    cube.loadTexture();
}

