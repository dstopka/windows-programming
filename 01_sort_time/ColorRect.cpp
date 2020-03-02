#include "stdafx.h"
#include "ColorRect.h"


ColorRect::ColorRect( CRect *rect, int penWidth, COLORREF penColor, COLORREF bgColor ) : CRect(rect)
{
}

ColorRect::ColorRect( const CRect &rect, int penWidth, COLORREF penColor, COLORREF bgColor ) :CRect(rect)
{
}

ColorRect::ColorRect( const CPoint &leftTop, const CPoint &rightBottom, int penWidth, COLORREF penColor, COLORREF bgColor ) : CRect(leftTop.x, leftTop.y, rightBottom.x, rightBottom.y)
{
}

ColorRect::ColorRect( const CPoint &point, const CSize &size, int penWidth, COLORREF penColor, COLORREF bgColor ) : CRect(point, size)
{
}

ColorRect::~ColorRect()
{
}

void ColorRect::paint( CDC *pDC )
{
	
}

void ColorRect::setAttr( int penWidth, COLORREF penColor, COLORREF bgColor )
{
}

std::shared_ptr<CPen> ColorRect::getPen()
{
	return this->pen;
}

std::shared_ptr<CBrush> ColorRect::getBrush()
{
	return this->brush;
}

void ColorRect::createAttr( int penWidth, COLORREF penColor, COLORREF bgColor )
{
}
