#include "Scenario.h"
#include "stb_image.h"
#include <GL/glut.h>
void Scenario::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Reset transformations
    glLoadIdentity();
    // Set the camera
    player.cam.lookAt();
    glPushMatrix();
    cube.draw();
    glPopMatrix();
    glPushMatrix();
    axis.Draw();
    //Draw ground
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glColor3f(0.9, 0.9, 0.9);
        glVertex3f(-100, 0, -100);
        glVertex3f(-100, 0, 100);
        glVertex3f(100, 0, 100);
        glVertex3f(100, 0, -100);
        glEnd();
    }
    // Draw 36 SnowMen
    for (int i = -3; i < 3; i++) {
        for (int j = -3; j < 3; ++j) {
            glPushMatrix();
            glTranslated(i * 10, 0, j * 10);
            snowMan.draw();
            glPopMatrix();
        }
    }
    // draw sphere
    {
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(0, 1, 0);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[0]);
    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    gluSphere(qobj, 1.0f, 20, 20);
    gluDeleteQuadric(qobj);
    glPopMatrix();
}
    // draw teapot
    {
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[0]);
    glTranslatef(0.0, 0.0, -10);
    glutSolidTeapot(1);
    glDisable(GL_TEXTURE_2D);
    }
    // watch to collide with cube
    if(collider.isColliding(player, cube.getX(),cube.getZ(), cube.getRadius())){
        player.restart();
    }else{
        player.cam.Towards();
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
        case 'a':
            player.cam.goLeft();
            break;
        case 'd':
            player.cam.goRight();
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
            player.cam.TurnLeft();
            break;
        case GLUT_KEY_RIGHT:
            player.cam.TurnRight();
            break;
        case GLUT_KEY_UP:
            player.cam.Towards();
            break;
        case GLUT_KEY_DOWN:
            player.cam.Backwards();
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
    cube.loadVars(3,1,3,0.01,0,0,0,0.1,1,true);
}

void Scenario::loadTextures() {
    cube.loadTexture();
}

