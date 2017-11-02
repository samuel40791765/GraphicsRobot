#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "Robot.h"
#include <cstdio>
#include <cmath>

const char windowName[] = "Q6";
int windowWidth = 1000;
int windowHeight = 800;
float aspect = 1;
float angle = 0;
GLfloat mat[4];
Robot *robot;

void SetLightSource()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//point light
	GLfloat lightPosition[] = { -1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat lightAmbient[] = { 0.5f, 0.5f, 0.5f, 0.5f };
	GLfloat lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1f);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1f);

	glEnable(GL_LIGHT1);

	//point light
	GLfloat lightPosition1[] = { -1.0f, 1.0f, -1.0f, 1.0f };
	GLfloat lightAmbient1[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat lightDiffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lightSpecular1[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5f);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1f);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.1f);

}

void SetMaterial()
{
	GLfloat matAmbient[] = {0.2f, 0.2f, 0.8f, 1.0f };
	GLfloat matDiffuse[] = {0.2f, 0.2f, 0.8f, 1.0f };
	GLfloat matSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat shininess = 128.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}



void SetEmeraldMaterial()
{
	mat[0] = 0.0215;
	mat[1] = 0.1745;
	mat[2] = 0.0215;
	mat[3] = 1.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = 0.07568;
	mat[1] = 0.61424;
	mat[2] = 0.07568;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = 0.633;
	mat[1] = 0.61424;
	mat[2] = 0.633;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.6 * 128.0);
}

void InitOpenGL()
{
	glShadeModel(GL_SMOOTH);

	SetLightSource();

	//enable depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//clear color and depth
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0, -1.5, -15);
	glRotatef(-45, 0, 1, 0);
	glScalef(2, 2, 2);
	robot->drawRobot(angle);
	glPopMatrix();

	
	

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	if (windowHeight <= 0)
	{
		windowHeight = 1;
	}

	//calculate aspect ratio for perspective projection
	float aspect = (float)windowWidth / (float)windowHeight;
	
	//set projection matrix to perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.3f, 1000.0f);

	//set view matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 1.0f, //eye(camera) position
		0.0f, 0.0f, 0.0f, //look direction
		0.0f, 1.0f, 0.0f);//up direction
}

void timer(int value)
{
	glutPostRedisplay();
	angle++;
	glutTimerFunc(16, timer, 0);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_MULTISAMPLE); //GLUT_MULTISAMPLE anti-aliasing
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow(windowName);

	InitOpenGL();
	robot = new Robot();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(16, timer, 0);

	glutMainLoop();

	return 0;
}