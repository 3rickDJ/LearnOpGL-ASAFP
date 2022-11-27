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
            snowMan.draw(true, false);
            glPopMatrix();
        }
    }
    glPushMatrix();
    snowMan.draw(true,true);
    glPopMatrix();

    // watch to collide with cube or SnowMan
    collider.watch();
    ReachEnd();
    glutSwapBuffers();
}

Scenario::Scenario() {

}
void Scenario::ReachEnd(){
    if(player.cam.z < -50){
        printf("FELICIDADES BUAPO, CRUSASTE MAL LA CALLE!!");
        exit(0);
    }
}
void Scenario::keys(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
        case 'Q':
            exit(0);
            break;
        case 'a':
            player.cam.TurnLeft();
            break;
        case 'd':
            player.cam.TurnRight();
            break;
    }
    glutPostRedisplay();
}

void Scenario::specialKeys(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_LEFT:
            player.cam.goLeft();
            break;
        case GLUT_KEY_RIGHT:
            player.cam.goRight();
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
    // set control variables for objects (obstacles)
    snowMan.loadVars(8,0.0,-10      ,0.01,0,0,0,0.01,0.75, true);
    cube.loadVars   (8, 1, 3        ,0.009,0,0,0,0.1,1   , false);
    //config collider
    //who is the principal object
    collider.player(&player);
    //attatch objects to collide to

    //mugneco de nieve 1
    collider.attach(&snowMan);


    //cubo malo
    collider.attach(&cube);

}

void Scenario::loadTextures() {
    cube.loadTexture(6, "cubo_malo.bmp", "cubo_malo.bmp", "cubo_malo.bmp", "cubo_malo.bmp", "cubo_malo.bmp",
                     "cubo_malo.bmp");

}
