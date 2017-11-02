#pragma once
#include <vector>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "Pnt3f.H"
#include <math.h>

class Robot
{
public:
	Robot();
	~Robot();
	void drawRobot(float angle);
private:
	int bodysize = 0;
	GLUquadric* qobj;
	void drawBody(float angle);
	void drawRightArm();
	void drawLeftArm();
	void drawRightHand();
	void drawLeftHand();
	void drawRightLeg();
	void drawLeftLeg();
	void SetRubyMaterial();
	void SetBrassMaterial();
	void roundRect(Pnt3f pnt, float height, float width, float lgth, float curve);
};

