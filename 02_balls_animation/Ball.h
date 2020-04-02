#pragma once
#include <memory>

#include "atltypes.h"
#include "Colors.h"

class Ball : public CRect
{
public:
	Ball(int nOffX, int nOffY, const int left = 0,
			const int top = 0,
			const int right = 0, 
			const int bottom = 0,
			COLORREF color = BLACK);
	Ball( int nOffX, int nOffY, const CRect& rect, COLORREF color = BLACK );
	Ball( int nOffX, int nOffY, const CPoint& point, const CSize& size, COLORREF color = BLACK );
	~Ball();

public:
	inline void setColor( COLORREF );
	inline void setBallSize( const CRect& );
	void paint( CDC& memDC );
	void setOffset( int nOffsetX, int nOffsetY );
	void setBall( const CRect& rect, COLORREF color, int nOffX, int nOffY );
	void setBoundRect( const CRect& boundRect );

private:
	inline void createObjects( COLORREF color );

private:
	std::unique_ptr<CPen> pen_;
	std::unique_ptr<CBrush> brush_;
	std::unique_ptr<CRect> boundRect_;
	int nOffsetX_;
	int nOffsetY_;
};

