#include "Robot.h"



Robot::Robot()
{
	qobj = gluNewQuadric();
	right_bicep_xangle = 90;
	left_bicep_xangle = 90;
	right_arm_xangle = -30;
	left_arm_xangle = -30;
	right_big_legxangle = 90;
	left_big_legxangle = 90;
	right_small_legxangle = 0;
	left_small_legxangle = 0;
	right_finger_angle = -20;
	left_finger_angle = 0;
	right_knuckle_angle = 0;
	left_knuckle_angle = 0;
	right_thumb_angle = 0;
	left_thumb_angle = 0;
	armswing = true;
	legwalk = false;
}


Robot::~Robot()
{
}

void Robot::drawRobot()
{
	//glRotatef(-90, 1, 0, 0);
	//glRotatef(-90, 0, 1, 0);
	drawBody();

	glPushMatrix();
	glTranslatef(-1.25, 1.65, 0);
	drawLeftArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.25, 1.65, 0);
	drawRightArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 0, 0);
	drawLeftLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0, 0);
	drawRightLeg();
	glPopMatrix();
}

void Robot::drawBody()
{

	glPushMatrix();
	//glRotatef(angle, 0, 1, 0);
	glRotatef(0, 1, 0, 0);
	Material::SetWhiteMaterial();
	roundRect(Pnt3f(0.85, 1.8, 0.85), 1.7, 1.7, 1.7, 0.3);
	Material::SetBlackMaterial();
	roundRect(Pnt3f(0.8, 0.8, 1.2), 0.5, 0.5, 0.2, 0.1);
	Material::SetCyanMaterial();
	glTranslatef(0.75, 0.5, 1.25);
	gluSphere(qobj, 0.1, 30, 30);
	
	glDisable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColor3ub(48,213,200);
	glTranslatef(-0.75, 0.9, 0);
	glScalef(3.5, 3.5, 1);
	//gluSphere(qobj, 0.05, 30, 30);
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//drawHead
	//glTranslatef(0.5, 3, 0);
	//glRotatef(-70, 1, 0, 0);
	Material::SetWhiteMaterial();
	//gluCylinder(qobj, 0.1, 0.1, 2.5, 4, 4);
	roundRect(Pnt3f(0.5, 2.7, 0.5), 0.2, 1, 1, 0.5);

	Material::SetBlackMaterial();
	glTranslatef(0, 2.6, 0.9);
	glScalef(2.3, 1.3, 1);
	gluSphere(qobj, 0.3, 30, 30);
	glPopMatrix();

	Material::SetCyanMaterial();
	glPushMatrix();
	glTranslatef(-0.3, 2.6, 1.13);
	glScalef(1, 1.75, 1);
	gluSphere(qobj, 0.1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 2.6, 1.13);
	glScalef(1, 1.75, 1);
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
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluCylinder(qobj, 0.1, 0.2, 1, 20, 20);
	glPopMatrix();

	glTranslatef(0, 0, 1.05);
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
	glRotatef(right_thumb_angle, -0.5, 0, 1.2);
	//glTranslatef(0, 0.18, 0);
	glRotatef(-80, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.28, 20, 20);
	glTranslatef(0, 0.0, 0.29);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	/*glRotatef(20, 1, 0, 0);
	glRotatef(40, 0, 0, 1);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);*/
	glPopMatrix();

	glPushMatrix(); //index
	glRotatef(right_knuckle_angle, 0, 1, 0);
	glTranslatef(0, 0.1, 0.15);
	glRotatef(-20, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.11);
	glRotatef(right_finger_angle, 0, 1, 0);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.11);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //middle
	glRotatef(right_knuckle_angle, 0, 1, 0);
	glTranslatef(0, 0, 0.2);
	gluCylinder(qobj, 0.05, 0.05, 0.12, 20, 20);
	glTranslatef(0, 0.0, 0.17);
	glRotatef(right_finger_angle, 0, 1, 0);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.13);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //ring
	glRotatef(right_knuckle_angle, 0, 1, 0);
	glTranslatef(0, -0.1, 0.15);
	glRotatef(10, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.12);
	glRotatef(right_finger_angle, 0, 1, 0);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	gluCylinder(qobj, 0.05, 0.05, 0.06, 20, 20);
	glTranslatef(0, 0.0, 0.1);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //pinky
	glRotatef(right_knuckle_angle, 0, 1, 0);
	glTranslatef(0, -0.15, 0.08);
	glRotatef(30, 1, 0, 0);
	gluCylinder(qobj, 0.045, 0.045, 0.07, 20, 20);
	glTranslatef(0, 0.0, 0.085);
	glRotatef(right_finger_angle, 0, 1, 0);
	gluSphere(qobj, 0.045, 10, 10);
	glTranslatef(0, 0.0, 0.04);
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
	glRotatef(left_thumb_angle, 0.5, 0, 1.2);
	//glTranslatef(0, 0.18, 0);
	glRotatef(-80, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.28, 20, 20);
	glTranslatef(0, 0.0, 0.29);
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
	glTranslatef(0, 0.0, 0.11);
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
	gluSphere(qobj, 0.25, 10, 10);
	glPopMatrix();
	glRotatef(-15, 0, 1, 0);
	Material::SetBlackMaterial();
	gluCylinder(qobj, 0.1, 0.1, 1, 20, 20);
	glTranslatef(0, 0, 1.2);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(15, 0, 1, 0);
	glRotatef(left_arm_xangle, 1, 0, 0);
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluCylinder(qobj, 0.1, 0.2, 1, 20, 20);
	glPopMatrix();
	glTranslatef(0, 0, 1.05);
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
	Material::SetBlackMaterial();
	glScalef(1, 1.3, 1);
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(right_big_legxangle, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.1, 0.7, 20, 20);
	glTranslatef(0, 0, 0.7);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glTranslatef(-0.2, -0.2, -0.3);
	roundRect(Pnt3f(0.5, 0.7, 0.5), 0.7, 0.5, 0.05, 0.1);

	glPopMatrix();

}

void Robot::drawLeftLeg()
{
	glPushMatrix();
	Material::SetBlackMaterial();
	glScalef(1, 1.3, 1);
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(left_big_legxangle, 1, 0, 0);
	gluCylinder(qobj, 0.1, 0.1, 0.7, 20, 20);
	glTranslatef(0, 0, 0.7);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glTranslatef(-0.2, -0.2, -0.3);
	roundRect(Pnt3f(0.4, 0.7, 0.5), 0.7, 0.5, 0.05, 0.1);


	glPopMatrix();
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

	if (legwalk) {
		if (right_big_legxangle > 60)
			right_big_legxangle--;
		if (left_big_legxangle < 120)
			left_big_legxangle++;
		if (right_big_legxangle <= 60 || left_big_legxangle >= 120)
			legwalk = false;
	}
	else {
		if (left_big_legxangle > 60)
			left_big_legxangle--;
		if (right_big_legxangle < 120)
			right_big_legxangle++;
		if (left_big_legxangle <= 60 || right_big_legxangle >= 120)
			legwalk = true;
	}
}

void Robot::clenchfist() {
	if (fist) {
		if (right_finger_angle > -110)
			right_finger_angle--;
		if (right_knuckle_angle > -70)
			right_knuckle_angle--;
		if (right_thumb_angle < 60)
			right_thumb_angle++;
		if (right_finger_angle <= -110 )
			fist = false;
	}
	else {
		if (right_finger_angle < -20)
			right_finger_angle++;
		if (right_knuckle_angle < 0)
			right_knuckle_angle++;
		if (right_thumb_angle > 0)
			right_thumb_angle--;
		if (right_finger_angle >= -20)
			fist = true;
	}
}