#include "Robot.h"
#include <iostream>



Robot::Robot()
{
	qobj = gluNewQuadric();
	spin_angle = 0;
	squat_length = 0;
	jump_height = 0;
	down_angle = 0;
	ankle = 0;
	front_length = 0;
	
	right_bicep_xangle = 90;
	left_bicep_xangle = 90;
	right_bicep_yangle = 0;
	left_bicep_yangle = 0;
	right_bicep_zangle = 0;
	left_bicep_zangle = 0;

	right_arm_xangle = -30;
	left_arm_xangle = -30;
	right_arm_zangle = 0;
	left_arm_zangle = 0;
	right_arm = 1;
	left_arm = 1;
	right_leg = 0.7;
	left_leg = 0.7;
	right_big_legxangle = 90;
	left_big_legxangle = 90;
	right_small_legxangle = 0;
	left_small_legxangle = 0;
	right_finger_angle = -20;
	left_finger_angle = 20;
	right_knuckle_angle = 0;
	left_knuckle_angle = 0;
	right_thumb_angle = 0;
	left_thumb_angle = 0;
	right_wrist_angle = 0;
	left_wrist_angle = 0;
	right_wrist_offset = 0;
	left_wrist_offset = 0;
	head_rotate = 0;
	armswing = true;
	legwalk = false;
	knee_down = true;
	shooting = true;
	projectile = false;
	punching = true;
	punchonehand = false;
	projectile_space = 0;
	shoot_count = 0;
}


Robot::~Robot()
{
}

void Robot::initAction()
{
	head_rotate = 0;
	spin_angle = 0;
	down_angle = 0;
	squat_length = 0;
	jump_height = 0;
	ankle = 0;
	front_length = 0;
	right_arm = 1;
	left_arm = 1;
	right_leg = 0.7;
	left_leg = 0.7;
	right_bicep_xangle = 90;
	left_bicep_xangle = 90;
	right_bicep_yangle = 0;
	left_bicep_yangle = 0;
	right_arm_xangle = -30;
	left_arm_xangle = -30;
	left_arm_yangle = 0;
	right_arm_yangle = 0;
	right_arm_zangle = 0;
	left_arm_zangle = 0;
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
	right_wrist_angle = 0;
	left_wrist_angle = 0;
	right_wrist_offset = 0;
	left_wrist_offset = 0;
	armswing = true;
	legwalk = false;
	knee_down = true;
	do_push = false;
	projectile = false;
	shooting = true;
	punching = true;
	punchonehand = false;
	projectile_space = 0;
	shoot_count = 0;
}

void Robot::drawRobot()
{
	//glRotatef(-90, 1, 0, 0);
	//glRotatef(-90, 0, 1, 0);
	glPushMatrix();	//push and pop whole body
	glTranslatef(0, jump_height, 0);
	glRotatef(spin_angle, 0, 1, 0);
	glRotatef(down_angle, 1, 0, 0);

	glPushMatrix();  //push and pop head, body, left and right hands
	glTranslatef(0, squat_length, 0);
	glTranslatef(0, 0, front_length);

	drawBody();

	glPushMatrix();
	glTranslatef(-1.25, 1.65, 0);
	drawLeftArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.25, 1.65, 0);
	drawRightArm();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 0, 0);
	drawLeftLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0, 0);
	drawRightLeg();
	glPopMatrix();

	glPopMatrix();
}

void Robot::drawBody()
{

	glPushMatrix();
	//glRotatef(angle, 0, 1, 0);
	
	Material::SetWhiteMaterial();
	roundRect(Pnt3f(0.85, 1.8, 0.85), 1.7, 1.7, 1.7, 0.3);
	Material::SetBlackMaterial();
	roundRect(Pnt3f(0.8, 0.8, 1.2), 0.5, 0.5, 0.2, 0.1);
	Material::SetCyanMaterial();
	glTranslatef(0.75, 0.5, 1.25);
	gluSphere(qobj, 0.1, 30, 30);

	glDisable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColor3ub(48, 213, 200);
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
	glRotatef(head_rotate, 0, 1, 0);
	roundRect(Pnt3f(0.5, 2.7, 0.5), 0.2, 1, 1, 0.5);

	Material::SetBlackMaterial();
	glTranslatef(0, 2.6, 0.9);
	glScalef(2.3, 1.3, 1);
	gluSphere(qobj, 0.3, 30, 30);
	glPopMatrix();

	Material::SetCyanMaterial();
	glPushMatrix();
	glRotatef(head_rotate, 0, 1, 0);
	glTranslatef(-0.3, 2.6, 1.13);
	glScalef(1, 1.75, 1);
	gluSphere(qobj, 0.1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(head_rotate, 0, 1, 0);
	glTranslatef(0.3, 2.6, 1.13);
	glScalef(1, 1.75, 1);
	gluSphere(qobj, 0.1, 30, 30);
	glPopMatrix();


}

void Robot::drawRightArm()
{
	glRotatef(right_bicep_yangle, 0, 1, 0);
	glRotatef(right_bicep_zangle, 0, 0, 1);
	glRotatef(right_bicep_xangle, 1, 0, 0);
	glPushMatrix();
	Material::SetWhiteMaterial();
	glPushMatrix();
	glScalef(1.5, 1, 1);
	gluSphere(qobj, 0.25, 10, 10);
	glPopMatrix();
	glRotatef(15, 0, 1, 0);
	Material::SetBlackMaterial();
	gluCylinder(qobj, 0.1, 0.1, right_arm, 20, 20);
	glTranslatef(0, 0, right_arm);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(-15, 0, 1, 0);
	glRotatef(right_arm_xangle, 1, 0, 0);
	glRotatef(right_arm_yangle, 0, 1, 0);
	glRotatef(right_arm_zangle, 0, 0, 1);
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluCylinder(qobj, 0.1, 0.2, 1, 20, 20);
	glPopMatrix();
	glTranslatef(0, 0, 1.05);
	if (projectile) {
		Material::SetCyanMaterial();
		glPushMatrix();
		glTranslatef(0, 0, projectile_space);
		gluSphere(qobj, 0.5, 30, 30);
		glPopMatrix();
	}
	glTranslatef(right_wrist_offset, 0, 0);
	glRotatef(right_wrist_angle, 0, 180, 0);
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
	glRotatef(left_knuckle_angle, 0, 1, 0);
	glTranslatef(0, 0.1, 0.15);
	glRotatef(-20, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.11);
	glRotatef(left_finger_angle, 0, 1, 0);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.11);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //middle
	glRotatef(left_knuckle_angle, 0, 1, 0);
	glTranslatef(0, 0, 0.2);
	gluCylinder(qobj, 0.05, 0.05, 0.12, 20, 20);
	glTranslatef(0, 0.0, 0.17);
	glRotatef(left_finger_angle, 0, 1, 0);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.1, 20, 20);
	glTranslatef(0, 0.0, 0.13);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //ring
	glRotatef(left_knuckle_angle, 0, 1, 0);
	glTranslatef(0, -0.1, 0.15);
	glRotatef(10, 1, 0, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.08, 20, 20);
	glTranslatef(0, 0.0, 0.12);
	glRotatef(left_finger_angle, 0, 1, 0);
	gluSphere(qobj, 0.05, 10, 10);
	glTranslatef(0, 0.0, 0.04);
	glRotatef(20, 0, 1, 0);
	gluCylinder(qobj, 0.05, 0.05, 0.06, 20, 20);
	glTranslatef(0, 0.0, 0.1);
	gluSphere(qobj, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix(); //pinky
	glRotatef(left_knuckle_angle, 0, 1, 0);
	glTranslatef(0, -0.15, 0.08);
	glRotatef(30, 1, 0, 0);
	gluCylinder(qobj, 0.045, 0.045, 0.07, 20, 20);
	glTranslatef(0, 0.0, 0.085);
	glRotatef(left_finger_angle, 0, 1, 0);
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
	glRotatef(left_bicep_yangle, 0, 1, 0);
	glRotatef(left_bicep_zangle, 0, 0, 1);
	glRotatef(left_bicep_xangle, 1, 0, 0);
	glPushMatrix();
	Material::SetWhiteMaterial();
	glPushMatrix();
	glScalef(1.5, 1, 1);
	gluSphere(qobj, 0.25, 10, 10);
	glPopMatrix();
	glRotatef(-15, 0, 1, 0);
	Material::SetBlackMaterial();
	gluCylinder(qobj, 0.1, 0.1, left_arm, 20, 20);
	glTranslatef(0, 0, left_arm);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glRotatef(15, 0, 1, 0);
	glRotatef(left_arm_xangle, 1, 0, 0);
	glRotatef(left_arm_yangle, 0, 1, 0);
	glRotatef(left_arm_zangle, 0, 0, 1);
	glPushMatrix();
	glScalef(1, 1.3, 1);
	gluCylinder(qobj, 0.1, 0.2, 1, 20, 20);
	glPopMatrix();
	glTranslatef(0, 0, 1.05);
	glTranslatef(left_wrist_offset, 0, 0);
	glRotatef(left_wrist_angle, 0, 180, 0);
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
	gluCylinder(qobj, 0.1, 0.1, right_leg, 20, 20);
	
	glTranslatef(0, 0, right_leg);
	glRotatef(ankle, 1, 0, 0);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glTranslatef(-0.2, -0.2, -0.4);
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
	gluCylinder(qobj, 0.1, 0.1, left_leg, 20, 20);
	glTranslatef(0, 0, left_leg);
	glRotatef(ankle, 1, 0, 0);
	Material::SetWhiteMaterial();
	gluSphere(qobj, 0.2, 10, 10);
	glTranslatef(-0.2, -0.2, -0.4);
	roundRect(Pnt3f(0.4, 0.7, 0.5), 0.7, 0.5, 0.05, 0.1);


	glPopMatrix();
}


void Robot::roundRect(Pnt3f pnt, float height, float width, float lgth, float curve) {
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
	gluCylinder(qobj, curve, curve, lgth, 50, 50);
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
	glVertex3f(0, 0, 0 - lgth - curve);
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

		if (left_finger_angle < 110)
			left_finger_angle++;
		if (left_knuckle_angle < 70)
			left_knuckle_angle++;
		if (left_thumb_angle > -60)
			left_thumb_angle--;

		if (right_finger_angle <= -110 && left_finger_angle >= 110)
			fist = false;
	}
	else {
		if (right_finger_angle < -20)
			right_finger_angle++;
		if (right_knuckle_angle < 0)
			right_knuckle_angle++;
		if (right_thumb_angle > 0)
			right_thumb_angle--;

		if (left_finger_angle > 20)
			left_finger_angle--;
		if (left_knuckle_angle > 0)
			left_knuckle_angle--;
		if (left_thumb_angle < 0)
			left_thumb_angle++;

		if (right_finger_angle >= -20 && left_finger_angle <= 20)
			fist = true;
	}
}
void Robot::SRK_punch()
{
	//std::cout << "knee down: " << knee_down << "  " << "jump: " << jump << std::endl;
	if (knee_down) {
		//squat
		if (squat_length > -0.5) {
			squat_length -= 0.01;
		}
		else {
			knee_down = false;
			jump = true;
		}
		//fist
		if (right_finger_angle > -110)	//fist
			right_finger_angle-=4;
		if (right_knuckle_angle > -70)
			right_knuckle_angle-=4;
		if (right_thumb_angle < 60)
			right_thumb_angle+=4;
		if (left_finger_angle < 110)
			left_finger_angle+=4;
		if (left_knuckle_angle < 70)
			left_knuckle_angle+=4;
		if (left_thumb_angle > -60)
			left_thumb_angle-=4;


		//right arm up
		if (right_arm_xangle > -75) {
			right_arm_xangle--;
			left_arm_xangle--;
		}

	}
	else {
		if (squat_length < 0.0) {
			squat_length += 0.05;
		}
		else {
			if (jump&&jump_height < 2.0){
				jump_height += 0.07;
				if (right_arm_xangle < -30) {
					right_arm_xangle += 20;
				}
				if (right_bicep_xangle > -70) {
					right_bicep_xangle -= 20;
				}
				if (spin_angle > -360)
					spin_angle -= 12;
			}
			else if(jump&&jump_height >= 2.0){
				jump = false;
			}
			if (!jump&&jump_height > 0.0) {
				jump_height -= 0.07;
				if (right_bicep_xangle < 90) {
					right_bicep_xangle += 20;
				}
				if (left_arm_xangle < -30) {
					left_arm_xangle += 10;
				}
				if (right_finger_angle < -20)	//fist
					right_finger_angle+=4;
				if (right_knuckle_angle < 0)
					right_knuckle_angle+=4;
				if (right_thumb_angle > 0)
					right_thumb_angle-=4;
				if (left_finger_angle > 20)
					left_finger_angle-=4;
				if (left_knuckle_angle > 0)
					left_knuckle_angle-=4;
				if (left_thumb_angle < 0)
					left_thumb_angle+=4;


			}
			else if(!jump&&jump_height <= 0.0){
				knee_down = true;
				spin_angle = 0;
			}
			
		}

	}
}

void Robot::run()
{
	if (right_bicep_xangle >= -90) {
		right_bicep_xangle -= 20;
		left_bicep_xangle -= 20;
	}
	if (armswing) {
		if (right_bicep_xangle >= -120) {
			right_bicep_xangle -= 4;
			left_bicep_xangle -= 4;
		}
		if (right_arm_xangle >= -45) {
			right_arm_xangle -= 4;
			left_arm_xangle -= 4;
		}
		if (right_bicep_xangle <= -120 && right_arm_xangle <= -45)
			armswing = false;
	}
	else {
		if (right_bicep_xangle <= -90) {
			right_bicep_xangle += 4;
			left_bicep_xangle += 4;
		}
		if (right_arm_xangle <= -15) {
			right_arm_xangle += 4;
			left_arm_xangle += 4;
		}
		if (right_bicep_xangle >= -90 && right_arm_xangle >= -15)
			armswing = true;
	}
	if (legwalk) {
		if (right_big_legxangle > 60)
			right_big_legxangle -= 5;
		if (left_big_legxangle < 120)
			left_big_legxangle += 5;
		if (right_big_legxangle <= 60 || left_big_legxangle >= 120)
			legwalk = false;
	}
	else {
		if (left_big_legxangle > 60)
			left_big_legxangle -= 5;
		if (right_big_legxangle < 120)
			right_big_legxangle += 5;
		if (left_big_legxangle <= 60 || right_big_legxangle >= 120)
			legwalk = true;
	}
}
void Robot::push_up()
{
	if (right_finger_angle > -110)
		right_finger_angle--;
	if (right_knuckle_angle > -70)
		right_knuckle_angle--;
	if (right_thumb_angle < 60)
		right_thumb_angle++;

	if (left_finger_angle < 110)
		left_finger_angle++;
	if (left_knuckle_angle < 70)
		left_knuckle_angle++;
	if (left_thumb_angle > -60)
		left_thumb_angle--;
	if (down_angle < 75) {
		down_angle += 2;
	}
	if (right_bicep_xangle <= 90) {
		right_bicep_xangle += 3;
		left_bicep_xangle += 3;
	}
	if (!do_push) {
		if (down_angle < 85) {
			down_angle += 0.3;
		}
		if (right_bicep_xangle <= 110) {
			right_bicep_xangle += 0.5;
			left_bicep_xangle += 0.5;
		}
		
		if (right_arm_xangle >= -120) {
			right_arm_xangle -= 1;
			left_arm_xangle -= 1;
		}
		if (down_angle >= 85 && right_arm_xangle <= -120 && right_bicep_xangle >= 100) {
			do_push = true;
		}
	}
	else {
		if (down_angle > 75) {
			down_angle -= 0.3;
		}
		if (right_bicep_xangle >= 90) {
			right_bicep_xangle -= 0.5;
			left_bicep_xangle -= 0.5;
		}
		if (right_arm_xangle <= -90) {
			right_arm_xangle += 1;
			left_arm_xangle += 1;
		}
		if (down_angle <= 75 && right_arm_xangle >= -90 && right_bicep_xangle <= 90) {
			do_push = false;
		}

	}
}
void Robot::body_shake()
{
	if (armswing) {
		if (right_bicep_xangle >= 10) {
			right_bicep_xangle -= 4;
			left_bicep_xangle -= 4;
		}
		if (right_arm_xangle >= -45) {
			right_arm_xangle -= 4;
			left_arm_xangle -= 4;
		}
		if (ankle >= 0) {
			ankle -= 4;
		}
		if (jump_height >= 0) {
			jump_height -= 0.1;
		}
		if (front_length >= 0) {
			front_length -= 0.1;
		}
		if (right_bicep_xangle <= 10 && right_arm_xangle <= -45 && ankle <= 0 && jump_height <= 0.0 && front_length <= 0.1)
			armswing = false;
	}
	else {
		if (right_bicep_xangle <= 100) {
			right_bicep_xangle += 8;
			left_bicep_xangle += 8;
		}
		if (right_arm_xangle <= -15) {
			right_arm_xangle += 4;
			left_arm_xangle += 4;
		}
		if (ankle <= 50) {
			ankle += 16;
		}
		if (jump_height <= 0.4) {
			jump_height += 0.25;
		}
		if (front_length <= 0.2) {
			front_length += 0.1;
		}
		if (right_bicep_xangle >= 100 && right_arm_xangle >= -15 && ankle >= 50 && jump_height >= 0.4 && front_length >= 0.2)
			armswing = true;
	}
}

void Robot::shoot() {
	if (shooting) {
		if (right_bicep_xangle >= 3) {
			right_bicep_xangle--;
		}
		if (right_arm_xangle <= 0) {
			right_arm_xangle++;
		}
		if (right_wrist_angle<=180) {
			right_wrist_angle++;
		}
		if (right_wrist_offset <= 0.4) {
			right_wrist_offset += (0.4 / 180);
		}
		if (right_wrist_angle >= 180) {
			projectile = true;
			if (projectile_space <= 20) {
				projectile_space += 0.8;
			}
			if (projectile_space >= 20) {
				projectile = false;
				shoot_count++;
				projectile_space = 0;
			}
			if (shoot_count == 3) {
				shooting = false;
				shoot_count = 0;
			}
		}
	}
	else {
		if (right_bicep_xangle <= 90) {
			right_bicep_xangle++;
		}
		if (right_arm_xangle >= -30) {
			right_arm_xangle--;
		}
		if (right_wrist_angle >= 0) {
			right_wrist_angle-=3;
		}
		if (right_wrist_offset >= 0) {
			right_wrist_offset -= (1.2 / 180);
		}
		if (right_bicep_xangle >= 90) {
			shooting = true;
		}
	}
}

void Robot::punch() {
	if (punching) {
		if (right_finger_angle > -110)
			right_finger_angle--;
		if (right_knuckle_angle > -70)
			right_knuckle_angle--;
		if (right_thumb_angle < 60)
			right_thumb_angle++;

		if (left_finger_angle < 110)
			left_finger_angle++;
		if (left_knuckle_angle < 70)
			left_knuckle_angle++;
		if (left_thumb_angle > -60)
			left_thumb_angle--;

		if (right_arm_xangle > -70)
			right_arm_xangle--;

		if (left_arm_xangle > -70)
			left_arm_xangle--;


		if (right_finger_angle <= -110 && left_finger_angle >= 110) {
			if (!punchonehand) {
				if (left_arm_xangle < 0)
					left_arm_xangle += 15;
				if (left_bicep_xangle > 10)
					left_bicep_xangle -= (80 / (70 / 15));

				if (left_arm_zangle < 90)
					left_arm_zangle += 20;

				if (left_bicep_xangle <= 10)
					punchonehand = true;
			}
			else {
				if (left_arm_xangle > -70)
					left_arm_xangle -= 10;
				if (left_bicep_xangle < 90)
					left_bicep_xangle += (80 / (70 / 10));
				if (left_arm_zangle > 0)
					left_arm_zangle -= 20;
				if (right_arm_zangle < 90)
					right_arm_zangle += 20;
				if (right_arm_xangle < 0)
					right_arm_xangle += 10;

				if (right_bicep_xangle > 10)
					right_bicep_xangle -= (80 / (70 / 10));

				if (right_bicep_xangle <= 10) {
					punching = false;
					punchonehand = false;
				}
			}
			/*if (left_bicep_xangle >= 3) {
				left_bicep_xangle -= 20;
			}
			if (left_bicep_xangle >= 3) {
				left_bicep_xangle -= 20;
			}*/
			//punching = false;
		}
	}
	else {

		if (right_finger_angle < -20)
			right_finger_angle++;
		if (right_knuckle_angle < 0)
			right_knuckle_angle++;
		if (right_thumb_angle > 0)
			right_thumb_angle--;

		if (left_finger_angle > 20)
			left_finger_angle--;
		if (left_knuckle_angle > 0)
			left_knuckle_angle--;
		if (left_thumb_angle < 0)
			left_thumb_angle++;
		if (right_arm_zangle > 0)
			right_arm_zangle -= 20;
		if (right_bicep_xangle < 90) 
			right_bicep_xangle += 2;
		
		if (right_arm_xangle > -30) 
			right_arm_xangle--;
		
		if (left_arm_xangle < -30) 
			left_arm_xangle++;
		
		if (right_finger_angle >= -20 && left_finger_angle <= 20 && right_arm_xangle >= -30)
			punching = true;
	}
}

void Robot::spinkick() {
	if (knee_down) {
		//squat
		if (squat_length > -0.5) {
			squat_length -= 0.01;
		}
		else {
			knee_down = false;
			jump = true;
		}

		if (right_bicep_xangle < 150) {
			right_bicep_xangle += 5;
			left_bicep_xangle += 5;
		}

	}
	else {
		if (squat_length < 0.0) {
			squat_length += 0.05;
		}
		else {
			if (jump&&jump_height < 2.0) {
				jump_height += 0.07;
				if (right_arm_xangle < -30) {
					right_arm_xangle += 20;
					left_arm_xangle += 20;
				}
				if (right_bicep_xangle > -70) {
					right_bicep_xangle -= 20;
					left_bicep_xangle -= 20;
				}
				if (left_big_legxangle >= 20) {
					left_big_legxangle -= 10;
					left_leg += 0.2;
				}
				if (spin_angle > -360)
					spin_angle -= 12;
			}
			else if (jump&&jump_height >= 2.0) {
				jump = false;
			}
			if (!jump&&jump_height > 0.0) {
				jump_height -= 0.07;
				if (right_bicep_xangle < 90) {
					right_bicep_xangle += 20;
					left_bicep_xangle += 20;
				}
				if (left_arm_xangle < -30) {
					left_arm_xangle += 10;
					right_arm_xangle += 10;
				}

				if (left_big_legxangle <= 90) {
					left_big_legxangle += 10;
					left_leg -= 0.2;
				}
			}
			else if (!jump&&jump_height <= 0.0) {
				knee_down = true;
				spin_angle = 0;
			}

		}

	}
}
void Robot::yay() {
	right_bicep_xangle += 20;
	left_bicep_xangle += 20;
	if (right_bicep_xangle >= 360)
		right_bicep_xangle -= 360;
	if (left_bicep_xangle >= 360)
		left_bicep_xangle -= 360;
}
void Robot::pray() {
	if (squat_length > -0.5) {
		squat_length -= 0.05;
	}
	if (right_bicep_xangle >= 60) {
		right_bicep_xangle -= 8;
		left_bicep_xangle -= 8;
	}
	if (right_bicep_yangle >= -10) {
		right_bicep_yangle -= 5;
		left_bicep_yangle += 5;
	}
	if (right_arm_yangle >= -30) {
		right_arm_yangle -= 5;
		left_arm_yangle += 5;
	}
	if (right_arm_yangle <= -30) {
		if (armswing) {
			if (right_bicep_xangle >= -15) {
				right_bicep_xangle -= 5;
				left_bicep_xangle -= 5;
			}
			if (right_bicep_xangle <= -15)
				armswing = false;
		}
		else {
			if (right_bicep_xangle <= 15) {
				right_bicep_xangle += 5;
				left_bicep_xangle += 5;
			}
			if (right_bicep_xangle >= 15)
				armswing = true;
		}
	}
}
void Robot::armextend() {
	if (left_arm_xangle <= 0) {
		left_arm_xangle += 5;
		right_arm_xangle += 5;
	}
	if (right_bicep_xangle > 10) {
		right_bicep_xangle -= 5;
		left_bicep_xangle -= 5;
	}
	if (right_bicep_xangle <= 10) {
		if (armswing) {
			if (right_arm <= 3.5) {
				right_arm += 0.1;
				left_arm += 0.1;
			}
			if (right_arm >= 3.5)
				armswing = false;
		}
		else {
			if (right_arm >= 1) {
				right_arm -= 0.1;
				left_arm -= 0.1;
			}
			if (right_arm <=1)
				armswing = true;
		}
	}
}
void Robot::wave() {
	if (right_bicep_xangle >= -80) {
		right_bicep_xangle -= 10;
		right_arm_zangle += 5;
	}
	if (right_arm_xangle < 0)
		right_arm_xangle += 10;

	if (right_bicep_xangle <= -80) {
		if (armswing) {
			if (right_arm_yangle >= -30)
				right_arm_yangle -= 5;
			if (right_arm_yangle <= -30)
				armswing = false;
		}
		else {
			if (right_arm_yangle <= 30)
				right_arm_yangle += 5;
			if (right_arm_yangle >= 30)
				armswing = true;
		}
	}

}
void Robot::headspin() {
	head_rotate += 10;
	if (head_rotate > 360)
		head_rotate -= 360;;
}

void Robot::legextend() {
	if (armswing) {
		if (right_leg <= 2.5) {
			right_leg += 0.1;
			left_leg += 0.1;
			jump_height += 0.12;
		}
		if (right_leg >= 2.5)
			armswing = false;
	}
	else {
		if (right_leg >= 0.7) {
			right_leg -= 0.1;
			left_leg -= 0.1;
			jump_height -= 0.12;
		}
		if (right_leg <= 1)
			armswing = true;
	}
}
void  Robot::extendandgrab() {
	if (right_bicep_xangle > 10) {
		right_bicep_xangle -= 5;
	}
	if (right_arm_xangle <= 0) {
		right_arm_xangle += 5;
	}

	if (right_bicep_xangle <= 10) {
		if (armswing) {
			if (right_arm <= 4) {
				right_arm += 0.1;
			}
			if (right_arm >= 4)
				punchonehand = true;

			if (punchonehand) {
				if (right_finger_angle > -110)
					right_finger_angle-=3;
				if (right_knuckle_angle > -70)
					right_knuckle_angle-=3;
				if (right_thumb_angle < 60)
					right_thumb_angle+=3;
				if (right_finger_angle <= -110)
					armswing = false;
			}
		}
		else {
			if (!punchonehand) {
				if (right_finger_angle < -20)
					right_finger_angle+=3;
				if (right_knuckle_angle < 0)
					right_knuckle_angle+=3;
				if (right_thumb_angle > 0)
					right_thumb_angle-=3;

				if (right_finger_angle >= -20)
					armswing = true;
			}
			if (punchonehand) {
				if (right_arm >= 1) {
					right_arm -= 0.1;
				}
				if (right_arm <= 1)
					punchonehand = false;
			}
		}
	}
}
void  Robot::flail() {
	if (armswing) {
		if (left_bicep_yangle >= -90) {
			left_bicep_yangle -= 10;
			right_bicep_yangle += 10;
		}

		if (right_bicep_xangle >= 30) {
			right_bicep_xangle -= 5;
			left_bicep_xangle -= 5;
		}
		if (left_bicep_yangle <= -90)
			armswing = false;
	}
	else {
		if (!punchonehand) {
			if (right_bicep_xangle >= -30) {
				right_bicep_xangle -= 15;
				left_bicep_xangle -= 15;
			}
			if (right_bicep_xangle <= -30)
				punchonehand = true;
		}
		else {
			if (right_bicep_xangle <= 70) {
				right_bicep_xangle += 15;
				left_bicep_xangle += 15;
			}
			if (right_bicep_xangle >= 70)
				punchonehand = false;
		}
	}
}
void  Robot::jumpup() {
	if (knee_down) {
		//squat
		if (squat_length > -0.5) {
			squat_length -= 0.01;
		}
		else {
			knee_down = false;
			jump = true;
		}

		if (right_bicep_xangle < 150) {
			right_bicep_xangle += 5;
			left_bicep_xangle += 5;
		}
		
	}
	else {
		if (squat_length < 0.0) {
			squat_length += 0.05;
		}
		else {
			if (jump&&jump_height < 2.0) {
				jump_height += 0.14;
				if (right_arm_xangle < -30) {
					right_arm_xangle += 20;
					left_arm_xangle += 20;
				}
				if (right_bicep_xangle > -70) {
					right_bicep_xangle -= 20;
					left_bicep_xangle -= 20;
				}
			}
			else if (jump&&jump_height >= 2.0) {
				jump = false;
			}
			if (!jump&&jump_height > 0.0) {
				jump_height -= 0.1;
				if (right_bicep_xangle < 90) {
					right_bicep_xangle += 20;
					left_bicep_xangle += 20;
				}
				if (left_arm_xangle < -30) {
					left_arm_xangle += 10;
					right_arm_xangle += 10;
				}

			}
			else if (!jump&&jump_height <= 0.0) {
				knee_down = true;
			}

		}

	}
}
void  Robot::swim() {
	if (armswing) {
		if (down_angle < 75) {
			down_angle += 3;
		}
		if (right_arm_zangle <= 80) {
			right_arm_zangle += 5;
			left_arm_zangle -= 5;
		}
		if (right_arm_xangle <= 0) {
			right_arm_xangle += 5;
			left_arm_xangle += 5;
		}
		if (right_bicep_xangle >= -80) {
			right_bicep_xangle -= 10;
			left_bicep_xangle -= 10;
		}
		if (down_angle >= 75)
			armswing = false;
	}
	else {
		if (!punchonehand) {
			if (right_bicep_xangle <= 280) {
				right_bicep_xangle += 15;
			}
			if (right_bicep_xangle >= 280) {
				right_bicep_xangle -= 360;
				punchonehand = true;
			}
		}
		else {
			if (left_bicep_xangle <= 280) {
				left_bicep_xangle += 15;
			}
			if (left_bicep_xangle >= 280) {
				left_bicep_xangle -= 360;
				punchonehand = false;
			}
		}
	}
}

void Robot::jack() {
	if (armswing) {
		if (left_bicep_yangle >= -90) {
			left_bicep_yangle -= 10;
			right_bicep_yangle += 10;
		}

		if (right_bicep_xangle >= 30) {
			right_bicep_xangle -= 5;
			left_bicep_xangle -= 5;
		}
		if (left_bicep_yangle <= -90)
			armswing = false;
	}
	else {
		if (knee_down) {
			//squat
			if (squat_length > -0.5) {
				squat_length -= 0.1;
			}
			else {
				knee_down = false;
				jump = true;
			}

		}
		else {
			if (squat_length < 0.0) {
				squat_length += 0.1;
			}
			else {
				if (jump&&jump_height < 2.0) {
					jump_height += 0.14;
					if (right_arm_xangle < -30) {
						right_arm_xangle += 20;
						left_arm_xangle += 20;
					}
					if (right_bicep_xangle > -70) {
						right_bicep_xangle -= 20;
						left_bicep_xangle -= 20;
					}
				}
				else if (jump&&jump_height >= 2.0) {
					jump = false;
				}
				if (!jump&&jump_height > 0.0) {
					jump_height -= 0.14;
					if (right_bicep_xangle < 30) {
						right_bicep_xangle += 20;
						left_bicep_xangle += 20;
					}
					if (left_arm_xangle < -30) {
						left_arm_xangle += 10;
						right_arm_xangle += 10;
					}

				}
				else if (!jump&&jump_height <= 0.0) {
					knee_down = true;
				}

			}

		}
	}

	
}