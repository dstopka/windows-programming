#include "stdafx.h"
#include "BallsField.h"
#include "RandomGenerator.h"
#include "Colors.h"

BallsField::BallsField()
{
	std::srand( time( nullptr ) );
	this->addBall();
}

void BallsField::paint( CDC* pDC )
{
	CDC memDC;
	bool b = memDC.CreateCompatibleDC( pDC );
	ASSERT( b );
	CBitmap bmp;
	b = bmp.CreateCompatibleBitmap( pDC, boundRect_.Width(), boundRect_.Height() );
	ASSERT( b );
	auto oldBitmap = memDC.SelectObject( &bmp );
	memDC.FillSolidRect( boundRect_, GREY );

	this->paintBalls( memDC );

	b = pDC->BitBlt( 0, 0, boundRect_.Width(), boundRect_.Height(), &memDC, 0, 0, SRCCOPY );
	ASSERT( b );

	memDC.SelectObject( oldBitmap );
	bmp.DeleteObject();
	memDC.DeleteDC();
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

void BallsField::offsetBalls()
{
	for(auto& x : balls_ )
	{
		x.offset( boundRect_ );
	}
}

void BallsField::offsetBalls( int cx, int cy )
{
	for ( auto& x : balls_ )
	{
		x.OffsetRect(-cx, -cy);
	}
}

void BallsField::setBoundRect( CRect& boundRect )
{
	boundRect_ = boundRect;
}
