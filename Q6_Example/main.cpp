#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <FreeImage.h>
#include "Robot.h"
#include <cstdio>
#include <cmath>
#include <vector>
#include "TextureManager.h"
//#include <SDL.h>

const char windowName[] = "Q6";
int windowWidth = 1000;
int windowHeight = 800;
float aspect = 1;
float angle = 0;
GLfloat mat[4];
Robot *robot;
enum { SKY_LEFT = 0, SKY_BACK, SKY_RIGHT, SKY_FRONT, SKY_TOP, SKY_BOTTOM };
unsigned int skybox[6]; //the ids for the textures

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

//int loadTexture(const char* filename)  //load the filename named texture
//{
//	unsigned int num;       //the id for the texture
//	glGenTextures(1, &num);  //we generate a unique one
//	SDL_Surface* img = SDL_LoadBMP(filename); //load the bmp image
//	glBindTexture(GL_TEXTURE_2D, num);       //and use the texture, we have just generated
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);      //we repeat the pixels in the edge of the texture, it will hide that 1px wide line at the edge of the cube, which you have seen in the video
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);      //we do it for vertically and horizontally (previous line)
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT , img->pixels);        //we make the actual texture
//	SDL_FreeSurface(img);   //we delete the image, we don't need it anymore
//	return num;     //and we return the id
//}
//
//void initskybox()
//{
//	skybox[SKY_LEFT] = loadTexture("left.bmp");
//	skybox[SKY_BACK] = loadTexture("back.bmp");
//	skybox[SKY_RIGHT] = loadTexture("right.bmp");
//	skybox[SKY_FRONT] = loadTexture("front.bmp");
//	skybox[SKY_TOP] = loadTexture("top.bmp");
//	skybox[SKY_BOTTOM] = loadTexture("bottom.bmp");
//}
//
//void drawSkybox(float size)
//{
//	bool b1 = glIsEnabled(GL_TEXTURE_2D);     //new, we left the textures turned on, if it was turned on
//	glDisable(GL_LIGHTING); //turn off lighting, when making the skybox
//	glDisable(GL_DEPTH_TEST);       //turn off depth texting
//	glEnable(GL_TEXTURE_2D);        //and turn on texturing
//	glBindTexture(GL_TEXTURE_2D, skybox[SKY_BACK]);  //use the texture we want
//	glBegin(GL_QUADS);      //and draw a face
//							//back face
//	glTexCoord2f(0, 0);      //use the correct texture coordinate
//	glVertex3f(size / 2, size / 2, size / 2);       //and a vertex
//	glTexCoord2f(1, 0);      //and repeat it...
//	glVertex3f(-size / 2, size / 2, size / 2);
//	glTexCoord2f(1, 1);
//	glVertex3f(-size / 2, -size / 2, size / 2);
//	glTexCoord2f(0, 1);
//	glVertex3f(size / 2, -size / 2, size / 2);
//	glEnd();
//	glBindTexture(GL_TEXTURE_2D, skybox[SKY_LEFT]);
//	glBegin(GL_QUADS);
//	//left face
//	glTexCoord2f(0, 0);
//	glVertex3f(-size / 2, size / 2, size / 2);
//	glTexCoord2f(1, 0);
//	glVertex3f(-size / 2, size / 2, -size / 2);
//	glTexCoord2f(1, 1);
//	glVertex3f(-size / 2, -size / 2, -size / 2);
//	glTexCoord2f(0, 1);
//	glVertex3f(-size / 2, -size / 2, size / 2);
//	glEnd();
//	glBindTexture(GL_TEXTURE_2D, skybox[SKY_FRONT]);
//	glBegin(GL_QUADS);
//	//front face
//	glTexCoord2f(1, 0);
//	glVertex3f(size / 2, size / 2, -size / 2);
//	glTexCoord2f(0, 0);
//	glVertex3f(-size / 2, size / 2, -size / 2);
//	glTexCoord2f(0, 1);
//	glVertex3f(-size / 2, -size / 2, -size / 2);
//	glTexCoord2f(1, 1);
//	glVertex3f(size / 2, -size / 2, -size / 2);
//	glEnd();
//	glBindTexture(GL_TEXTURE_2D, skybox[SKY_RIGHT]);
//	glBegin(GL_QUADS);
//	//right face
//	glTexCoord2f(0, 0);
//	glVertex3f(size / 2, size / 2, -size / 2);
//	glTexCoord2f(1, 0);
//	glVertex3f(size / 2, size / 2, size / 2);
//	glTexCoord2f(1, 1);
//	glVertex3f(size / 2, -size / 2, size / 2);
//	glTexCoord2f(0, 1);
//	glVertex3f(size / 2, -size / 2, -size / 2);
//	glEnd();
//	glBindTexture(GL_TEXTURE_2D, skybox[SKY_TOP]);
//	glBegin(GL_QUADS);                      //top face
//	glTexCoord2f(1, 0);
//	glVertex3f(size / 2, size / 2, size / 2);
//	glTexCoord2f(0, 0);
//	glVertex3f(-size / 2, size / 2, size / 2);
//	glTexCoord2f(0, 1);
//	glVertex3f(-size / 2, size / 2, -size / 2);
//	glTexCoord2f(1, 1);
//	glVertex3f(size / 2, size / 2, -size / 2);
//	glEnd();
//	glBindTexture(GL_TEXTURE_2D, skybox[SKY_BOTTOM]);
//	glBegin(GL_QUADS);
//	//bottom face
//	glTexCoord2f(1, 1);
//	glVertex3f(size / 2, -size / 2, size / 2);
//	glTexCoord2f(0, 1);
//	glVertex3f(-size / 2, -size / 2, size / 2);
//	glTexCoord2f(0, 0);
//	glVertex3f(-size / 2, -size / 2, -size / 2);
//	glTexCoord2f(1, 0);
//	glVertex3f(size / 2, -size / 2, -size / 2);
//	glEnd();
//	glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
//	glEnable(GL_DEPTH_TEST);
//	if (!b1)
//		glDisable(GL_TEXTURE_2D);
//}

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
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glPushMatrix();
	glTranslatef(0, -1.5, -15);
	glRotatef(-0, 0,1, 0);
	glScalef(2, 2, 2);
	//drawSkybox(50.0f);
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
	robot->clenchfist();
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
	TextureManager *mtexture[6];
	//****************
	//mtexture[0]->Inst.LoadTexture("");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(16, timer, 0);

	glutMainLoop();

	return 0;
}