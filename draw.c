#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "glm.h"

GLMmodel *model;
int mx, my; //Global for mouse location;
GLfloat ax = 0.0, ay = 0.0, az = 0.0;	//Global for rotate angle;

void init(char *filename)
{
    GLfloat scale_factor;
    model = glmReadOBJ(filename);
    scale_factor = glmUnitize(model);
    glmScale(model, 0.1 * scale_factor);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 0.0, 1.0);
}

void display()
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(ax, 1.0, 0.0, 0.0);
    glRotatef(ay, 0.0, 1.0, 0.0);
    glRotatef(az, 0.0, 0.0, 1.0);
    glmDraw(model, GLM_NONE);
    glPopMatrix();
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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	mx = x;
	my = y;
    }
}

void motion(int x, int y)
{
    ax = fmod((ax + ((GLfloat)(y - my))/100.0), 360.0);
    ay = fmod((ay + ((GLfloat)(x - mx))/100.0), 360.0);
    glutPostRedisplay();
}

void keyboard(int key, int x, int y)
{
    switch(key) {
	case GLUT_KEY_LEFT:
	    az += 10.0;
	    break;
	case GLUT_KEY_RIGHT:
	    az -= 10.0;
	    break;
	default:
	    return;
    }
    if(az >=360.0)
	az -= 360.0;
    glutPostRedisplay();
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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
