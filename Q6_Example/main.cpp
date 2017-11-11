#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Robot.h"
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "TextureApp.h"
#define INITACTION -1
#define PUNCH 2
#define WALK 1
#define IDLE 0
#define DPUNCH 3
using namespace glm;

mat4 Projection;
mat4 View;
GLboolean mouserdown = GL_FALSE;
GLboolean mouseldown = GL_FALSE;
GLboolean mousemdown = GL_FALSE;
static GLint mousex = 0, mousey = 0;
float position = 0.0;
float eyeAngley = 0.0;
float eyedistance = 20.0;
int mode;
int action;
bool isFrame;
void ChangeSize(int w, int h);
void display();
void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Mousemove(int x, int y);
void menuEvents(int option);
void ActionMenuEvents(int option);


const char windowName[] = "Q6";
int windowWidth = 1000;
int windowHeight = 800;
float aspect = 1;
float angle = 320;
GLfloat mat[4];
Robot *robot;
enum { SKY_LEFT = 0, SKY_BACK, SKY_RIGHT, SKY_FRONT, SKY_BOTTOM, SKY_TOP };
GLuint skybox[6]; //the ids for the textures

void SetLightSource()
{

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glEnable(GL_COLOR_MATERIAL);

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



void initskybox()
{
	skybox[SKY_LEFT] = TextureApp::GenTexture("Media\\skybox_left.jpg");
	skybox[SKY_BACK] = TextureApp::GenTexture("Media\\skybox_back.jpg");
	skybox[SKY_RIGHT] = TextureApp::GenTexture("Media\\skybox_right.jpg");
	skybox[SKY_FRONT] = TextureApp::GenTexture("Media\\skybox_front.jpg");
	skybox[SKY_TOP] = TextureApp::GenTexture("Media\\skybox_top.jpg");
	skybox[SKY_BOTTOM] = TextureApp::GenTexture("Media\\skybox_bottom.jpg");
}

void drawSkybox(float size)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_BACK]);  //use the texture we want
	glBegin(GL_QUADS);      //and draw a face
							//back face
	glTexCoord2f(1, 1);      //use the correct texture coordinate
	glVertex3f(size / 2, size / 2, size / 2);       //and a vertex
	glTexCoord2f(0, 1);      //and repeat it...
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_LEFT]);
	glBegin(GL_QUADS);
	//left face
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_FRONT]);
	glBegin(GL_QUADS);
	//front face
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_RIGHT]);
	glBegin(GL_QUADS);
	//right face
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_TOP]);
	glBegin(GL_QUADS);                      //top face
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_BOTTOM]);
	glBegin(GL_QUADS);
	//bottom face
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glPopMatrix();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
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
	float eyey = eyeAngley*3.1415 / 180;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		eyedistance*sin(eyey), 0, eyedistance*cos(eyey), //eye(camera) position
		0.0f, 0.0f, 0.0f, //look direction
		0.0f, 1.0f, 0.0f);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	drawSkybox(100);
	glPushMatrix();
	glTranslatef(0, -1.5, -15);
	glRotatef(angle, 0, 1, 0);
	glScalef(2, 2, 2);
	//drawSkybox(50.0f);
	robot->drawRobot();
	glPopMatrix();

	glFlush();
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
	float eyey = eyeAngley*3.1415 / 180;
	gluLookAt(
		0, 0, 1, //eye(camera) position
		0.0f, 0.0f, 0.0f, //look direction
		0.0f, 1.0f, 0.0f);//up direction
}

void timer(int value)
{
	glutPostRedisplay();
	switch (action) {
	case INITACTION:
		robot->initAction();
		break;
	case IDLE:
		break;
	case WALK:
		robot->walk();
		break;
	case PUNCH:
		robot->clenchfist();
		break;
	case DPUNCH:
		robot->SRK_punch();
		break;
	}

	glutTimerFunc(16, timer, 0);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_MULTISAMPLE); //GLUT_MULTISAMPLE anti-aliasing
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow(windowName);
	isFrame = false;
	InitOpenGL();
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(Keyboard);
	int ActionMenu;
	ActionMenu = glutCreateMenu(ActionMenuEvents);
	glutAddMenuEntry("init action", -1);
	glutAddMenuEntry("idle", 0);
	glutAddMenuEntry("walk", 1);
	glutAddMenuEntry("punch", 2);
	glutAddMenuEntry("SRK-punch", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutCreateMenu(menuEvents);
	glutAddSubMenu("action", ActionMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMouseFunc(Mouse);
	glutMotionFunc(Mousemove);

	robot = new Robot();	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(16, timer, 0);
	initskybox();

	glutMainLoop();

	return 0;
}

void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		break;
	case '2':
		break;
	case 'w':
		if (eyedistance > 1)
			eyedistance -= 0.4;
		break;
	case 's':
		if (eyedistance <= 30)
			eyedistance += 0.4;
		break;
	case 'a':
		//if (eyeAngley <= 10)
			eyeAngley += 1;
		break;
	case 'd':
		//if (eyeAngley >= -10)
			eyeAngley -= 1;
		break;
	case 'q':
		angle -= 5;
		if (angle <= 0) angle = 360;
		break;
	case 'e':
		angle += 5;
		if (angle >= 360) angle = 0;
		break;
	}
	glutPostRedisplay();
}

void ActionMenuEvents(int option) {
	switch (option) {
	case -1:
		action = INITACTION;
		break;
	case 0:
		action = IDLE;
		break;
	case 1:
		action = WALK;
		break;
	case 2:
		action = PUNCH;
		break;
	case 3:
		action = DPUNCH;
		break;
	}
}
void ChangeSize(int w, int h) {
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	Projection = glm::perspective(80.0f, (float)w / h, 0.1f, 100.0f);
}

void Mouse(int button, int state, int x, int y) {
	if (button == 2) isFrame = false;
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON) mouseldown = GL_TRUE;
	}
	else
	{
		if (button == GLUT_LEFT_BUTTON) mouseldown = GL_FALSE;
	}
	mousex = x, mousey = y;
}

void Mousemove(int x, int y)
{
	if (mouseldown == GL_TRUE)
	{
		eyeAngley += (x - mousex) / 10.0f;
	}

	if (mouseldown == GL_TRUE)
	{
		eyedistance += (y - mousey) / 25.0f;
	}
	mousex = x, mousey = y;
	glutPostRedisplay();
}


void menuEvents(int option) {};
void ModeMenuEvents(int option);