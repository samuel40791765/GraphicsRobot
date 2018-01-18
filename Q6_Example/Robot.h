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
	void punch();
	void SRK_punch();
	void run();
	void push_up();
	void body_shake();
	void shoot();

	//new stuff
	void spinkick();
	void yay();
	void pray();
	void armextend();
	void wave();
	void headspin();
	void legextend();
	void extendandgrab();
	void flail();
	void jumpup();
	void swim();
private:
	int bodysize = 0;
	int shoot_count = 0;
	float squat_length;
	float jump_height;
	float spin_angle;
	float down_angle;
	float ankle;
	float front_length;
	float head_rotate;
	float right_arm, left_arm;
	float right_leg, left_leg;
	float right_bicep_xangle,left_bicep_xangle;
	float right_bicep_yangle,left_bicep_yangle;
	float right_arm_xangle, left_arm_xangle;
	float right_arm_yangle, left_arm_yangle;
	float right_arm_zangle, left_arm_zangle;
	float right_big_legxangle, left_big_legxangle;
	float right_small_legxangle, left_small_legxangle;
	float right_knuckle_angle, left_knuckle_angle;
	float right_finger_angle, left_finger_angle;
	float right_thumb_angle, left_thumb_angle;
	float right_wrist_angle, left_wrist_angle;
	float right_wrist_offset ,left_wrist_offset;
	float projectile_space;
	bool armswing,legwalk;
	bool fist;
	bool knee_down;
	bool jump;
	bool do_push;
	bool shooting,projectile;
	bool punching;
	bool punchonehand;
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

