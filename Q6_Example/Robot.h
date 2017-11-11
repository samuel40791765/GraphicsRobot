#pragma once
#include <vector>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "Pnt3f.H"
#include "Material.h"
#include <math.h>

class Robot
{
public:
	Robot();
	~Robot();
	void drawRobot();
	void initAction();
	void walk();
	void clenchfist();
	void SRK_punch();
private:
	int bodysize = 0;
	float squat_length;
	float jump_height;
	float spin_angle;
	float right_bicep_xangle,left_bicep_xangle;
	float right_arm_xangle, left_arm_xangle;
	float right_big_legxangle, left_big_legxangle;
	float right_small_legxangle, left_small_legxangle;
	float right_knuckle_angle, left_knuckle_angle;
	float right_finger_angle, left_finger_angle;
	float right_thumb_angle, left_thumb_angle;
	bool armswing,legwalk;
	bool fist;
	bool knee_down;
	bool jump;
	GLUquadric* qobj;
	void drawBody();
	void drawRightArm();
	void drawLeftArm();
	void drawRightHand();
	void drawLeftHand();
	void drawRightLeg();
	void drawLeftLeg();
	void roundRect(Pnt3f pnt, float height, float width, float lgth, float curve);

	
};

