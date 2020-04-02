#pragma once

#include <vector>
#include "Ball.h"

#define BALL_MIN_SIZE 40
#define BALL_MAX_SIZE 140
#define OFFSET_VEC_MIN 1
#define OFFSET_VEC_MAX 10

class BallsField
{
public:
	BallsField();

public:
	void addBall();
	void deleteBall();
	void paintBalls( CDC& memDC );
	void changeBallsOffset();

private:
	std::vector<Ball> balls_;
};

