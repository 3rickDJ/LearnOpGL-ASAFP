#include <GL/glut.h>
#include "Scenario.h"

using namespace std;
Scenario escenario;

void reshape(int width, int height) {
    escenario.reshape(width,height);
}

static void keys(unsigned char key, int x, int y) {
    escenario.keys(key,x,y);
}

void display() {
    escenario.display();
}

void specialKeys(int key, int x, int y) {
    escenario.specialKeys(key,x,y);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangulo a color");
    escenario.init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keys);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
