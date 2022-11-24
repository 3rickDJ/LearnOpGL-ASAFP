#include <GL/glut.h>
#include <iostream>
#include <valarray>
#include "Camera.h"
#include "SnowMan.h"

using namespace std;


//Variables dimensiones de la pantalla
int WIDTH=500;
int HEIGTH=500;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;
//Variables para definir la posicion del observador
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=10.0;
float EYE_Y=5.0;
float EYE_Z=10.0;
float CENTER_X=0;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;
//Variables para dibujar los ejes del sistema
float X_MIN=-20;
float X_MAX=20;
float Y_MIN=-20;
float Y_MAX=20;
float Z_MIN=-100;
float Z_MAX=20;

void drawAxis()
{
     glShadeModel(GL_SMOOTH);
     glLineWidth(3.0);
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(0.5f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glColor3f(0.0f,1.0f,0.0f);
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,0.5f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,0.5f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
     glLineWidth(1.0);
 }

/////////////////////////////////////////////////////////////////////////////
//funciones de objetos
/////////////////////////////////////////////////////////////////////////////

float angle= 0.0f;
//funciones callbacks

float red=1, green=1, blue = 1;
void idle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glPushMatrix();
    glColor3f(red,green,blue);
    glLoadIdentity();
    gluLookAt( 0.0f, 0.0f, 10.0f,
               0.0f, 0.0f,  0.0f,
               0.0f, 1.0f,  0.0f);
    glRotated(angle, 0.0f, 1.0f, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-2,-2,0.0);
        glVertex3f(2,0.0,0.0);
        glVertex3f(0.0,2,0.0);
    glEnd();
    angle += 0.1f;
    glutSwapBuffers();
    glPopMatrix();
 }

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

static void keys(unsigned char key, int x, int y)
{
    switch(key){
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Reset transformations
    glLoadIdentity();
    // Set the camera

    gluLookAt(cam.x, cam.y, cam.z,
              cam.x + cam.lx, cam.y+ cam.ly, cam.z+cam.lz,
              cam.upX, cam.upY, cam.upZ);

    drawAxis();
    //Draw ground
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
            glVertex3f(-100,0,-100);
            glVertex3f(-100,0,100);
            glVertex3f(100, 0, 100);
            glVertex3f(100,0,-100);
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

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
}

void specialKeys(int key, int x, int y){
    switch (key) {
        case GLUT_KEY_F1:
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F2:
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F3:
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
        case GLUT_KEY_LEFT:
            cam.angle -= cam.speedRotation;
            cam.lx = sin(cam.angle);
            cam.lz = -cos(cam.angle);
            break;
        case GLUT_KEY_RIGHT:
            cam.angle += cam.speedRotation;
            cam.lx = sin(cam.angle);
            cam.lz = -cos(cam.angle);
            break;
        case GLUT_KEY_UP:
            cam.x += cam.lx * cam.speedMovement;
            cam.z += cam.lz * cam.speedMovement;
            break;
        case GLUT_KEY_DOWN:
            cam.x -= cam.lx*cam.speedMovement;
            cam.z -= cam.lz*cam.speedMovement;
            break;
    }

};

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIDTH, HEIGTH);
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
