#include "stdafx.h"
#include "BallsField.h"
#include "RandomGenerator.h"
#include "Colors.h"

BallsField::BallsField()
{
}

void BallsField::addBall()
{
	if(balls_.size() < 10 )
	{
		auto color = Colors::colors[Random::random(static_cast<size_t>(0), Colors::colors.size())];
		auto size = Random::random( BALL_MIN_SIZE, BALL_MAX_SIZE );
		auto offX = Random::random( OFFSET_VEC_MIN, OFFSET_VEC_MAX );
		auto offY = Random::random( OFFSET_VEC_MIN, OFFSET_VEC_MAX );
		balls_.push_back( Ball(offX, offY, 0, 0, size, size, color ));
	}
}

void BallsField::deleteBall()
{
	if ( balls_.size() > 1 )
	{
		balls_.pop_back();
	}
}

void BallsField::paintBalls( CDC& memDC )
{
	for ( auto& x : balls_ )
		x.paint(  memDC );
}

void BallsField::changeBallsOffset()
{
}
