#include "Robot.h"



Robot::Robot()
{
	qobj = gluNewQuadric();
	right_bicep_xangle = 90;
	left_bicep_xangle = 90;
	right_arm_xangle = -30;
	left_arm_xangle = -30;
	right_big_legxangle = 0;
	left_big_legxangle = 0;
	right_small_legxangle = 0;
	left_small_legxangle = 0;
	right_finger_angle = 0;
	left_fingerangle = 0;
}


Robot::~Robot()
{
}

void Robot::drawRobot(float angle)
{
	drawBody(angle);

	glPushMatrix();
	glTranslatef(-1.15, 1.65, 0);
	Material::SetBrassMaterial();
	drawLeftArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.15, 1.65, 0);
	Material::SetBrassMaterial();
	drawRightArm();
	glPopMatrix();
}

void Robot::drawBody(float angle)
{

	glPushMatrix();
	//glRotatef(angle, 0, 1, 0);
	glRotatef(0, 1, 0, 0);
	Material::SetWhiteMaterial();
	roundRect(Pnt3f(0.7, 1.8, 0.7), 1.7, 1.7, 1.7, 0.3);
	glPopMatrix();

	glPushMatrix();//drawHead
	//glTranslatef(0.5, 3, 0);
	//glRotatef(-70, 1, 0, 0);
	Material::SetWhiteMaterial();
	//gluCylinder(qobj, 0.1, 0.1, 2.5, 4, 4);
	roundRect(Pnt3f(0.5, 2.7, 0.5), 0.2, 1, 1, 0.5);

	Material::SetBlackMaterial();
	glTranslatef(0, 2.6, 0.9);
	glScalef(2.3, 1.35, 1);
	gluSphere(qobj, 0.3, 30, 30);
	glPopMatrix();

	Material::SetCyanMaterial();
	glPushMatrix();
	glTranslatef(-0.38, 2.6, 1.13);
	glScalef(1.3, 1.75, 1);
	gluSphere(qobj, 0.1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.38, 2.6, 1.13);
	glScalef(1.3, 1.75, 1);
	gluSphere(qobj, 0.1, 30, 30);
	glPopMatrix();

	
}

void Robot::drawRightArm()
{

	glRotatef(right_bicep_xangle, 1, 0, 0);
	glPushMatrix();
	Material::SetWhiteMaterial();
	glPushMatrix();
	glScalef(1.5, 1, 1);
	gluSphere(qobj, 0.25, 10, 10);
	glPopMatrix();
	glRotatef(15, 0, 1, 0);
	Material::SetBlackMaterial();
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glTranslatef(0, 0, 1);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(-15, 0, 1, 0);
	glRotatef(right_arm_xangle, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.25, 1, 20, 20);
	glTranslatef(0, 0, 1);
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
	Material::SetWhiteMaterial();
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluSphere(qobj, 0.2, 10, 10);

	Material::SetBlackMaterial();
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
	Material::SetWhiteMaterial();
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluSphere(qobj, 0.2, 10, 10);

	Material::SetBlackMaterial();
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
	glRotatef(left_bicep_xangle, 1, 0, 0);
	glPushMatrix();
	Material::SetWhiteMaterial();
	glPushMatrix();
	glScalef(1.5, 1, 1);
	gluSphere(qobj, 0.2, 10, 10);
	glPopMatrix();
	glRotatef(-15, 0, 1, 0);
	Material::SetBlackMaterial();
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glTranslatef(0, 0, 1.2);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(15, 0, 1, 0);
	glRotatef(left_arm_xangle, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.25, 1, 20, 20);
	glTranslatef(0, 0, 1);
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

}

void Robot::drawLeftLeg()
{

}


void Robot::roundRect(Pnt3f pnt,float height, float width, float lgth, float curve) {
	glPushMatrix();
	glTranslatef(pnt.x, pnt.y, pnt.z);
	//draw spheres
	glPushMatrix();
	gluSphere(qobj, curve, 50, 50);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 50, 50);
	glRotatef(-90, 1, 0, 0);

	glTranslatef(-width, 0, 0);
	gluSphere(qobj, curve, 50, 50);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 50, 50);
	glRotatef(-90, 1, 0, 0);

	glTranslatef(0, -height, 0);
	gluSphere(qobj, curve, 50, 50);
	glTranslatef(width, 0, 0);
	gluSphere(qobj, curve, 50, 50);
	glTranslatef(0, 0, -lgth);
	gluSphere(qobj, curve, 50, 50);
	glTranslatef(-width, 0, 0);
	gluSphere(qobj, curve, 50, 50);
	glTranslatef(0, height, 0);
	gluSphere(qobj, curve, 50, 50);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 50, 50);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(width, 0, 0);
	gluSphere(qobj, curve, 50, 50);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, curve, curve, height, 50, 50);
	glRotatef(-90, 1, 0, 0);
	glPopMatrix();

	//draw edges
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	gluCylinder(qobj, curve, curve,lgth, 50, 50);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-width, 0, -lgth);
	gluCylinder(qobj, curve, curve, lgth, 50, 50);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height, 0);
	glRotatef(180, 0, 1, 0);
	gluCylinder(qobj, curve, curve, lgth, 50, 50);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-width, -height, -lgth);
	gluCylinder(qobj, curve, curve, lgth, 50, 50);
	glRotatef(90, 0, 1, 0);
	gluCylinder(qobj, curve, curve, width, 50, 50);
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
	glPopMatrix();
}

void Robot::walk() {
	if (armswing) {
		if (right_bicep_xangle > 60)
			right_bicep_xangle--;
		if (left_bicep_xangle < 120)
			left_bicep_xangle++;
		if (right_bicep_xangle <= 60 || left_bicep_xangle >= 120)
			armswing = false;
	}
	else {
		if (left_bicep_xangle > 60)
			left_bicep_xangle--;
		if (right_bicep_xangle < 120)
			right_bicep_xangle++;
		if (left_bicep_xangle <= 60 || right_bicep_xangle >= 120)
			armswing = true;
	}
}