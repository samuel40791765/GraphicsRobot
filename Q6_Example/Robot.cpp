#include "Robot.h"



Robot::Robot()
{
	qobj = gluNewQuadric();
}


Robot::~Robot()
{
}

void Robot::drawRobot(float angle)
{
	drawBody(angle);

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	SetBrassMaterial();
	drawLeftArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 2, 0);
	SetBrassMaterial();
	drawRightArm();
	glPopMatrix();
}

void Robot::drawBody(float angle)
{

	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	SetRubyMaterial();
	gluCylinder(qobj, 1.5, 0.5, 3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3, 0);
	glRotatef(-90, 0, 1, 0);
	SetBrassMaterial();
	glutSolidTeapot(1);
	glPopMatrix();

}

void Robot::drawRightArm()
{

	glPushMatrix();
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(50, 1, 0, 0);
	glRotatef(15, 0, 1, 0);
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glTranslatef(0, 0, 1.2);
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(-15, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glTranslatef(0, 0, 1.2);
	drawRightHand();
	glPopMatrix();

	glPushMatrix();
	/*glRotatef()
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);*/
	glPopMatrix();

	glPushMatrix();
	glRotatef(30, 1, 0, 0);
	
	//gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glPopMatrix();
}

void Robot::drawRightHand()
{
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluSphere(qobj, 0.2, 10, 10);

	glPushMatrix(); //thumb
	glTranslatef(0, 0.18, 0);
	glRotatef(-80, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.13);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 1, 0, 0);
	glRotatef(40, 0, 0, 1);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glPopMatrix();

	glPushMatrix(); //index
	glTranslatef(0, 0.18, 0);
	glRotatef(-80, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.13);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 1, 0, 0);
	glRotatef(40, 0, 0, 1);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glPopMatrix();

	glPopMatrix();
}

void Robot::drawLeftHand()
{

}

void Robot::drawLeftArm()
{

}

void Robot::drawRightLeg()
{

}

void Robot::drawLeftLeg()
{

}

void Robot::SetRubyMaterial()
{
	GLfloat matAmbient[] = { 0.1745,0.01175,0.01175, 1.0f };
	GLfloat matDiffuse[] = { 0.61424,0.04136,0.04136, 1.0f };
	GLfloat matSpecular[] = { 0.727811,0.626959,0.626959, 1.0f };
	GLfloat shininess = 0.6* 128.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void Robot::SetBrassMaterial()
{
	GLfloat matAmbient[] = { 0.329412,0.223529,0.027451, 1.0f };
	GLfloat matDiffuse[] = { 0.780392,0.568627,0.113725, 1.0f };
	GLfloat matSpecular[] = { 0.992157,0.941176,0.807843, 1.0f };
	GLfloat shininess = 0.21794872f* 128.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}