/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<iostream>
using namespace std;
float xr =0,yr = 0;
static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,1);
    glBegin(GL_QUADS);
    glVertex2f(200+xr,100+yr);
    glVertex2f(300+xr,100+yr);
    glVertex2f(300+xr,200+yr);
    glVertex2f(200+xr,200+yr);
    glEnd();

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();


}


 void specialkey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        yr = yr + 1;
        cout<<y<<endl;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        yr--;
        cout<<y<<endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        xr--;
        cout<<x<<endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        xr++;
        cout<<x<<endl;
        glutPostRedisplay();
        break;

    }

    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    cout<<"Use array key"<<endl;
    glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(600,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Rectangle Moving");

    glutDisplayFunc(display);


    glClearColor(0,1,1,0);
    gluOrtho2D(0.0,400,0.0,400);

    glutSpecialFunc(specialkey);



    glutMainLoop();

    return EXIT_SUCCESS;
}
