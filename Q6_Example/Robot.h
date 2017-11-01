#pragma once
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

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
	void drawRightHand();
	void drawLeftHand();
	void drawRightLeg();
	void drawLeftLeg();
	void SetRubyMaterial();
	void SetBrassMaterial();
};

