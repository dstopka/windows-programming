#pragma once
#include "atltypes.h"
#include <memory>
#define BLACK RGB(0,0,0)
class ColorRect : public CRect
{
public:
	ColorRect(CRect *rect = NULL, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK);
	ColorRect( const CRect &rect = NULL, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	ColorRect( const CPoint &leftTop, const CPoint &rightBottom, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	ColorRect( const CPoint &point, const CSize &size, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	~ColorRect();

	void paint( CDC *pDC );
	void setAttr( int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	std::shared_ptr<CPen> getPen();
	std::shared_ptr<CBrush> getBrush();

private:
	void createAttr( int penWidth, COLORREF penColor, COLORREF bgColor );
	std::shared_ptr<CPen> pen;
	std::shared_ptr<CBrush> brush;
};

