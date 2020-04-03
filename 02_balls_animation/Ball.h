#pragma once
#include <memory>

#include "atltypes.h"
#include "Colors.h"

class Ball : public CRect
{
public:
	Ball(int nOffX, int nOffY, int left = 0,
			int top = 0,
			int right = 0, 
			int bottom = 0,
			COLORREF color = BLACK);
	Ball( const CRect& rect, int nOffX, int nOffY, COLORREF color = BLACK );
	Ball( const CPoint& point, const CSize& size, int nOffX, int nOffY, COLORREF color = BLACK );
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
	std::shared_ptr<CPen> pen_;
	std::shared_ptr<CBrush> brush_;
	std::shared_ptr<CRect> boundRect_;
	int nOffsetX_;
	int nOffsetY_;
};

