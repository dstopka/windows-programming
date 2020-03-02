#include "stdafx.h"
#include "ColorRect.h"


ColorRect::ColorRect( CRect *rect, int penWidth, COLORREF penColor, COLORREF bgColor ) : CRect()
{
}

ColorRect::ColorRect( const CRect &rect, int penWidth, COLORREF penColor, COLORREF bgColor )
{
}

ColorRect::ColorRect( const CPoint &leftTop, const CPoint &rightBottom, int penWidth, COLORREF penColor, COLORREF bgColor )
{
}

ColorRect::ColorRect( const CPoint &point, const CSize &size, int penWidth, COLORREF penColor, COLORREF bgColor )
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

std::unique_ptr<CPen> ColorRect::getPen()
{
	return std::unique_ptr<CPen>();
}

std::unique_ptr<CBrush> ColorRect::getBrush()
{
	return std::unique_ptr<CBrush>();
}

void ColorRect::createAttr( int penWidth, COLORREF penColor, COLORREF bgColor )
{
}
