#pragma once
#include "atltypes.h"
#include <memory>
class ColorRect : public CRect
{
public:
	ColorRect(CRect *rect = NULL, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK);
	ColorRect( const CRect &rect, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	ColorRect( const CPoint &leftTop, const CPoint &rightBottom, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	ColorRect( const CPoint &point, const CSize &size, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	~ColorRect();

	void paint( CDC *pDC ) const;
	void setAttr( int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	std::shared_ptr<CPen> getPen() const;
	std::shared_ptr<CBrush> getBrush() const;

private:
	void createAttr( int penWidth, COLORREF penColor, COLORREF bgColor );
	std::shared_ptr<CPen> pen_;
	std::shared_ptr<CBrush> brush_;
};

