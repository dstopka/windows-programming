#pragma once

#include <vector>
#include "Ball.h"

class BallsField
{
public:
	BallsField();
	~BallsField();

public:
	void addBall();
	void deleteBall();
	void drawBalls();
	void changeBallsOffset();

private:


private:
	std::vector<Ball> balls_;
};

