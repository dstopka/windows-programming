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
	void paint( CDC* pDC );
	void addBall();
	void deleteBall();
	void offsetBalls();
	void offsetBalls(int cx, int cy);
	void setBoundRect(CRect& boundRect );

private:
	void paintBalls( CDC& memDC );

private:
	std::vector<Ball> balls_;
	CRect boundRect_;
};

