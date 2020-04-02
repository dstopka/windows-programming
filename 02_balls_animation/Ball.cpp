#include "stdafx.h"
#include "Ball.h"


Ball::Ball( int nOffX, int nOffY, 
			const int left, const int top, const int right, const int bottom, 
			COLORREF color ) : CRect( left, top, right, bottom ), 
								nOffsetX_(nOffX), nOffsetY_( nOffY )
{
	this->createObjects( color );
}

Ball::Ball( int nOffX, int nOffY, const CRect& rect, COLORREF color )
	: CRect(rect), nOffsetX_( nOffX ), nOffsetY_( nOffY )
{
	this->createObjects( color );
}

Ball::Ball( int nOffX, int nOffY, const CPoint& point, const CSize& size, COLORREF color ) 
	: CRect(point, size), nOffsetX_( nOffX ), nOffsetY_( nOffY )
{
	this->createObjects( color );
}

Ball::~Ball()
{
}

inline void Ball::setColor( COLORREF color )
{
	pen_->DeleteObject();
	brush_->DeleteObject();
	pen_->CreatePen( PS_SOLID, 1, color );
	brush_->CreateSolidBrush( color );
}

inline void Ball::setBallSize( const CRect& rect )
{
	top = rect.top;
	bottom = rect.bottom;
	left = rect.left;
	right = rect.right;
}

void Ball::paint(CDC& memDC)
{
	CPen* oldPen = memDC.SelectObject( pen_.get() );
	CBrush* oldBrush = memDC.SelectObject( brush_.get() );
	memDC.Ellipse( left, top, right, bottom );
	memDC.SelectObject( oldPen );
	memDC.SelectObject( oldBrush );
}

inline void Ball::createObjects( COLORREF color )
{
	pen_ = std::make_unique<CPen>( PS_SOLID, 1, color );
	brush_ = std::make_unique<CBrush>( color );
}

void Ball::setOffset( int nOffsetX, int nOffsetY )
{
	nOffsetX_ = nOffsetX;
	nOffsetY_ = nOffsetY;
}
