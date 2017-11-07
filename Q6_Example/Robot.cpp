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
	//glRotatef(-90, 1, 0, 0);
	//glRotatef(-90, 0, 1, 0);
	drawBody(angle);

	glPushMatrix();
	glTranslatef(-1, 1.5, 0);
	SetBrassMaterial();
	drawLeftArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 1.5, 0);
	SetBrassMaterial();
	drawRightArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 0, 0);
	SetBrassMaterial();
	drawLeftLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0, 0);
	SetBrassMaterial();
	drawLeftLeg();
	glPopMatrix();
}

void Robot::drawBody(float angle)
{

	glPushMatrix();
	//glRotatef(angle, 0, 1, 0);
	glRotatef(0, 1, 0, 0);
	SetRubyMaterial();
	roundRect(Pnt3f(1, 2, 1), 2, 2, 2, 0.1);
	glPopMatrix();

	glPushMatrix();//drawHead
	//glTranslatef(0.5, 3, 0);
	//glRotatef(-70, 1, 0, 0);
	SetBrassMaterial();
	//gluCylinder(qobj, 0.1, 0.1, 2.5, 4, 4);
	roundRect(Pnt3f(0.5, 3, 0.5), 1, 1, 1, 0.3);
	//glutSolidTeapot(1);
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
	/*glRotatef(20, 1, 0, 0);
	glRotatef(40, 0, 0, 1);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);*/
	glPopMatrix();

	glPushMatrix(); //index
	glTranslatef(0, 0.1, 0.15);
	glRotatef(-20, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.15);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(-20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.11);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //middle
	glTranslatef(0, 0, 0.2);
	gluCylinder(qobj, 0.05, 0.05, 0.12, 20, 20);
	glTranslatef(0, 0.0, 0.17);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(-20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.13);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //ring
	glTranslatef(0, -0.1, 0.15);
	glRotatef(10, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.12);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(-20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.06, 20, 20);
	glTranslatef(0, 0.0, 0.1);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //pinky
	glTranslatef(0, -0.15, 0.08);
	glRotatef(30, 1, 0, 0);
	gluCylinder(qobj, 0.045, 0.045, 0.07, 20, 20);
	glTranslatef(0, 0.0, 0.085);
	gluSphere(qobj, 0.045, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(-20, 0, 1, 0);
	gluCylinder(qobj, 0.045, 0.045, 0.05, 20, 20);
	glTranslatef(0, 0.0, 0.065);
	gluSphere(qobj, 0.045, 10, 10);
	glPopMatrix();

	glPopMatrix();
}

void Robot::drawLeftHand()
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
	/*glRotatef(20, 1, 0, 0);
	glRotatef(40, 0, 0, 1);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);*/
	glPopMatrix();

	glPushMatrix(); //index
	glTranslatef(0, 0.1, 0.15);
	glRotatef(-20, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.15);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.11);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //middle
	glTranslatef(0, 0, 0.2);
	gluCylinder(qobj, 0.05, 0.05, 0.12, 20, 20);
	glTranslatef(0, 0.0, 0.17);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.13);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //ring
	glTranslatef(0, -0.1, 0.15);
	glRotatef(10, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.12);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.06, 20, 20);
	glTranslatef(0, 0.0, 0.1);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //pinky
	glTranslatef(0, -0.15, 0.08);
	glRotatef(30, 1, 0, 0);
	gluCylinder(qobj, 0.045, 0.045, 0.07, 20, 20);
	glTranslatef(0, 0.0, 0.085);
	gluSphere(qobj, 0.045, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 0, 1, 0);
	gluCylinder(qobj, 0.045, 0.045, 0.05, 20, 20);
	glTranslatef(0, 0.0, 0.065);
	gluSphere(qobj, 0.045, 10, 10);
	glPopMatrix();

	glPopMatrix();
}

void Robot::drawLeftArm()
{
	glPushMatrix();
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(50, 1, 0, 0);
	glRotatef(-15, 0, 1, 0);
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glTranslatef(0, 0, 1.2);
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(15, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glTranslatef(0, 0, 1.2);
	drawLeftHand();
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

void Robot::drawRightLeg()
{
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluSphere(qobj, 0.2, 10, 10);

	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.1, 0.7, 20, 20);
	glTranslatef(0, 0, 0.7);
	gluSphere(qobj, 0.2, 10, 10);
	glTranslatef(-0.2, -0.2, -0.3);
	roundRect(Pnt3f(0.5, 1, 0.5), 1.0, 0.5, 0.05, 0.1);


	glPopMatrix();

}

void Robot::drawLeftLeg()
{
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluSphere(qobj, 0.2, 10, 10);

	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.1, 0.7, 20, 20);
	glTranslatef(0, 0, 0.7);
	gluSphere(qobj, 0.2, 10, 10);
	glTranslatef(-0.2, -0.2, -0.3);
	roundRect(Pnt3f(0.5, 1, 0.5), 1.0, 0.5, 0.05, 0.1);


	glPopMatrix();
}

void Robot::SetRubyMaterial()
{
	
	GLfloat matAmbient[] = { 0.1745,0.01175,0.01175, 1.0f };
	GLfloat matDiffuse[] = { 0.61424,0.04136,0.04136, 1.0f };
	GLfloat matSpecular[] = { 0.727811,0.626959,0.626959, 1.0f };
	GLfloat shininess = 0.6* 128.0f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	
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

void Robot::roundRect(Pnt3f pnt,float height, float width, float lgth, float curve) {
	glTranslatef(pnt.x, pnt.y, pnt.z);
	//draw spheres
	glPushMatrix();
	gluSphere(qobj, curve, 30, 30);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 30, 30);
	glRotatef(-90, 1, 0, 0);

	glTranslatef(-width, 0, 0);
	gluSphere(qobj, curve, 30, 30);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 30, 30);
	glRotatef(-90, 1, 0, 0);

	glTranslatef(0, -height, 0);
	gluSphere(qobj, curve, 30, 30);
	glTranslatef(width, 0, 0);
	gluSphere(qobj, curve, 30, 30);
	glTranslatef(0, 0, -lgth);
	gluSphere(qobj, curve, 30, 30);
	glTranslatef(-width, 0, 0);
	gluSphere(qobj, curve, 30, 30);
	glTranslatef(0, height, 0);
	gluSphere(qobj, curve, 30, 30);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 30, 30);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(width, 0, 0);
	gluSphere(qobj, curve, 30, 30);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 30, 30);
	glRotatef(-90, 1, 0, 0);
	glPopMatrix();

	//draw edges
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	gluCylinder(qobj, curve, curve,lgth, 30, 30);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-width, 0, -lgth);
	gluCylinder(qobj, curve, curve, lgth, 30, 30);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height, 0);
	glRotatef(180, 0, 1, 0);
	gluCylinder(qobj, curve, curve, lgth, 30, 30);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-width, -height, -lgth);
	gluCylinder(qobj, curve, curve, lgth, 30, 30);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 30, 30);
	glPopMatrix();

	//faces
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(0, 0, 0 + curve);
	glVertex3f(0 - width, 0, 0 + curve);
	glVertex3f(0 - width, 0 - height, 0 + curve);
	glVertex3f(0, 0 - height, 0 + curve);

	glNormal3f(0, 0, -1);
	glVertex3f(0, 0, 0-lgth - curve);
	glVertex3f(0 - width, 0, 0 - lgth - curve);
	glVertex3f(0 - width, 0 - height, 0 - lgth - curve);
	glVertex3f(0, 0 - height, 0 - lgth - curve);

	glNormal3f(1, 0, 0);
	glVertex3f(0 + curve, 0, 0);
	glVertex3f(0 + curve, 0 - height, 0);
	glVertex3f(0 + curve, 0 - height, 0 - lgth);
	glVertex3f(0 + curve, 0, 0 - lgth);

	glNormal3f(-1, 0, 0);
	glVertex3f(0 - width - curve, 0, 0);
	glVertex3f(0 - width - curve, 0 - height, 0);
	glVertex3f(0 - width - curve, 0 - height, 0 - lgth);
	glVertex3f(0 - width - curve, 0, 0 - lgth);

	glNormal3f(0, 1, 0);
	glVertex3f(0, 0 + curve, 0);
	glVertex3f(0, 0 + curve, 0 - lgth);
	glVertex3f(0 - width, 0 + curve, 0 - lgth);
	glVertex3f(0 - width, 0 + curve, 0);

	glNormal3f(0, -1, 0);
	glVertex3f(0, 0 - height - curve, 0);
	glVertex3f(0, 0 - height - curve, 0 - lgth);
	glVertex3f(0 - width, 0 - height - curve, 0 - lgth);
	glVertex3f(0 - width, 0 - height - curve, 0);
	
	
	glEnd(); 
	
}