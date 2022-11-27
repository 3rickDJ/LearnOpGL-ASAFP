#include "Scenario.h"
#include "stb_image.h"
#include <GL/gl.h>
#include <cstdio>
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

    //Cartel del fondo
    {
        glColor3f(1.0,1.0,1.0);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        // Texture binding
        glPushMatrix();
        cube.texture.activate(0);
        cube.drawFace( 0, 10, -100,0.0, 0.0, -100.0,10.0, 0, -100,10, 10, -100);
        cube.texture.deactivate();
        glPopMatrix();
    }
    //draw cubes
    for (int i = 0; i < cubes.size(); ++i) {
        Cube * cubo = cubes[i];
        glPushMatrix();
        cubo->draw();
        glPopMatrix();
    }

    //draw Animated SnowMans
    glPushMatrix();
    for (int i = 0; i < snowMans.size(); ++i) {
        SnowMan * munecoNieve = snowMans[i];
        glPushMatrix();
        munecoNieve->draw(true, true);
        glPopMatrix();
    }
    glPopMatrix();

    // Draw 36 SnowMen
    for (int i = -100; i < 100; i+=15) {
        glPushMatrix();
            glTranslated(0, 0, i);
            snowMan.draw(true,false);
            glPopMatrix();

            glPushMatrix();
            glTranslated(10, 0, i);
            snowMan.draw(true, false);
            glPopMatrix();
    }
    glPushMatrix();
    snowMan.draw(true,false);
    glPopMatrix();
    environment();


    // watch to collide with cube or SnowMan
    collider.watch();
    ReachEnd();
    glutSwapBuffers();
}

Scenario::Scenario() {

}
void Scenario::ReachEnd(){
    if(player.cam.z < -100){
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
        default:
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
    gluPerspective(80.0, (GLfloat) 1.0, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    //load textures
    loadTextures();
    // set control variables for objects (obstacles)
    snowMan.loadVars(8,0.0,-10,0.02,0,0,0,0.1,0.75, true);
    cube.loadVars(8, 1, 3, 0.01, 0, 0, 0, 0.1, 1, false);
    //config collider
    //who is the principal object
    collider.player(&player);
    //attatch objects to collide to
    collider.attach(&snowMan);
    collider.attach(&cube);
}

void Scenario::loadTextures() {
    cube.loadTexture(15, "container.jpg", "textura1.bmp", "textura2.bmp", "textura3.bmp", "textura4.bmp",
                     "textura5.bmp","pavement.jpg", "road.bmp","cielo.jpg", "trees.jpg",
                     "trunk2.jpg", "house1.jpg", "house2.jpg", "buld1.jpg", "buld2.jpg"
                    );

}

void Scenario::environment(){
    //Draw ground
     glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[7]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(0, 0,-100);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(0, 0, 100);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(10, 0, 100);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(10, 0, -100);
        glEnd();
    }

    //Draw sky
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[8]);
    glBegin(GL_QUADS);
    {

        glTexCoord2f(1.0, 0.0);
        glVertex3f(-50, 10,-100);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-50, 10, 100);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(50, 10, 100);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(50, 10, -100);
        glEnd();
    }


    //pavement left
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[6]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-20, 0,-100);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-20, 0, 100);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(0, 0, 100);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(0, 0, -100);
        glEnd();
    }

    //pavement right
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[6]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(30, 0,-100);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(30, 0, 100);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(10, 0, 100);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(10, 0, -100);
        glEnd();
    }

    //trees left

for (int i = -100; i < 100; i+=15) {
    glPushMatrix();
    glTranslated(0, 4, i+7);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    gluSphere(qobj, 1.0f, 20, 20);
    gluDeleteQuadric(qobj);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 4, i+9);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj2 = gluNewQuadric();
    gluQuadricTexture(qobj2, GL_TRUE);
    gluSphere(qobj2, 1.0f, 20, 20);
    gluDeleteQuadric(qobj2);
    glPopMatrix();

     glPushMatrix();
    glTranslated(-0.5, 5, i+8);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj3 = gluNewQuadric();
    gluQuadricTexture(qobj3, GL_TRUE);
    gluSphere(qobj3, 1.0f, 20, 20);
    gluDeleteQuadric(qobj3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1, 4, i+8);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj4 = gluNewQuadric();
    gluQuadricTexture(qobj4, GL_TRUE);
    gluSphere(qobj4, 1.0f, 20, 20);
    gluDeleteQuadric(qobj4);
    glPopMatrix();

}

//trunk
for (int i = -100; i < 100; i+=15) {
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[10]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(0, 0,i+9);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(0, 5, i+9);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(0, 5, i+7);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(0, 0, i+7);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-0.5, 0,i+9);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-0.5, 4, i+9);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(0, 4, i+9);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(0, 0, i+9);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-0.5, 0,i+7);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-0.5, 4, i+7);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(0, 4, i+7);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(0, 0, i+7);
        glEnd();
    }
}

//trees right
for (int i = -100; i < 100; i+=15) {
    glPushMatrix();
    glTranslated(10, 4, i+7);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    gluSphere(qobj, 1.0f, 20, 20);
    gluDeleteQuadric(qobj);
    glPopMatrix();

    glPushMatrix();
    glTranslated(10, 4, i+9);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj2 = gluNewQuadric();
    gluQuadricTexture(qobj2, GL_TRUE);
    gluSphere(qobj2, 1.0f, 20, 20);
    gluDeleteQuadric(qobj2);
    glPopMatrix();

     glPushMatrix();
    glTranslated(10.5, 5, i+8);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj3 = gluNewQuadric();
    gluQuadricTexture(qobj3, GL_TRUE);
    gluSphere(qobj3, 1.0f, 20, 20);
    gluDeleteQuadric(qobj3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(11, 4, i+8);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 0.0f, 1.0f);
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[9]);
    GLUquadric *qobj4 = gluNewQuadric();
    gluQuadricTexture(qobj4, GL_TRUE);
    gluSphere(qobj4, 1.0f, 20, 20);
    gluDeleteQuadric(qobj4);
    glPopMatrix();

}
//trunk
for (int i = -100; i < 100; i+=15) {
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[10]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(10, 0,i+9);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(10, 5, i+9);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(10, 5, i+7);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(10, 0, i+7);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(10.5, 0,i+9);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(10.5, 4, i+9);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(10, 4, i+9);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(10, 0, i+9);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(10.5, 0,i+7);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(10.5, 4, i+7);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(10, 4, i+7);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(10, 0, i+7);
        glEnd();
    }
}
//houses

//left
for (int i = -100; i < 100; i+=30) {
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[11]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
          glVertex3f(-5, 5, i+3);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-5, 0,i+3);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-5, 0, i+12);
         glTexCoord2f(0.0, 0.0);
          glVertex3f(-5, 5, i+12);
        glEnd();
    }
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[12]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-10, 0,i+3);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-10, 5, i+3);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-5, 5, i+3);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(-5, 0, i+3);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-10, 0,i+12);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-10, 5, i+12);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-5, 5, i+12);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(-5, 0, i+12);
        glEnd();
    }
}

//right
for (int i = -100; i < 100; i+=30) {
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[11]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
          glVertex3f(15, 5, i+3);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(15, 0,i+3);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(15, 0, i+12);
         glTexCoord2f(0.0, 0.0);
          glVertex3f(15, 5, i+12);
        glEnd();
    }
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[12]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(15, 0,i+3);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(15, 5, i+3);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(20, 5, i+3);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(20, 0, i+3);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(15, 0,i+12);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(15, 5, i+12);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(20, 5, i+12);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(20, 0, i+12);
        glEnd();
    }
}

//buildings

//left
for (int i = -100; i < 100; i+=30) {
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[13]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
          glVertex3f(-5, 8, i+18);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-5, 0,i+18);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-5, 0, i+27);
         glTexCoord2f(0.0, 0.0);
          glVertex3f(-5, 8, i+27);
        glEnd();
    }
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[14]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-10, 0,i+18);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-10, 8, i+18);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-5, 8, i+18);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(-5, 0, i+18);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-10, 0,i+27);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-10, 8, i+27);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-5, 8, i+27);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(-5, 0, i+27);
        glEnd();
    }
}

//right
//left
for (int i = -100; i < 100; i+=30) {
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[13]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
          glVertex3f(15, 8, i+18);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(15, 0,i+18);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(15, 0, i+27);
         glTexCoord2f(0.0, 0.0);
          glVertex3f(15, 8, i+27);
        glEnd();
    }
    glBindTexture(GL_TEXTURE_2D, cube.texture.texture[14]);
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(20, 0,i+18);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(20, 8, i+18);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(15, 8, i+18);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(15, 0, i+18);
        glEnd();
    }
    glBegin(GL_QUADS);
    {
        glPopMatrix();
        glTexCoord2f(1.0, 0.0);
        glVertex3f(20, 0,i+27);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(20, 8, i+27);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(15, 8, i+27);
         glTexCoord2f(0.0, 0.0);
        glVertex3f(15, 0, i+27);
        glEnd();
    }
}


glDisable(GL_TEXTURE_2D);
}
