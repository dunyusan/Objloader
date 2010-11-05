#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel *model;

void init(char *filename)
{
    GLfloat scale_factor;
    model = glmReadOBJ(filename);
    scale_factor = glmUnitize(model);
    glmScale(model, 0.1*scale_factor);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display()
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glColor3f(0.0, 0.0, 1.0);
    glmDraw(model, GLM_NONE);
    glutSwapBuffers();
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
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow(argv[1]);
    init(argv[1]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
