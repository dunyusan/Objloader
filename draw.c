#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel *model;

void init()
{
    GLfloat scale_factor;
    model = glmReadOBJ("sophie.obj");
    scale_factor = glmUnitize(model);
    glmScale(model, 10.0*scale_factor);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display()
{
    printf("OK ");
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glColor3f(0.0, 0.0, 1.0);
    glmDraw(model, GLM_NONE);
    glFlush();
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
	gluPerspective(5.0, (GLdouble) h / (GLdouble) w, 0.5, 4.0);
    else
    	gluPerspective(5.0, (GLdouble) w / (GLdouble) h, 0.5, 4.0);
    /*glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);*/

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    printf("Reshape ");
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Sophie");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
