#pragma once
class Robot
{
public:
	Robot();
	~Robot();
	void drawRobot();
private:
	void drawBody();
	void drawRightHand();
	void drawLeftHand();
	void drawRightLeg();
	void drawLeftLeg();
};

