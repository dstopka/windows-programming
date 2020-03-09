#include "stdafx.h"
#include "ColorRect.h"


ColorRect::ColorRect(CRect* rect, int penWidth, COLORREF penColor, COLORREF bgColor) : CRect(rect)
{
	this->createAttr(penWidth, penColor, bgColor);
}

ColorRect::ColorRect(const CRect& rect, int penWidth, COLORREF penColor, COLORREF bgColor) : CRect(rect)
{
	this->createAttr(penWidth, penColor, bgColor);
}

ColorRect::ColorRect(const CPoint& leftTop, const CPoint& rightBottom, int penWidth, COLORREF penColor,
                     COLORREF bgColor) : CRect(leftTop.x, leftTop.y, rightBottom.x, rightBottom.y)
{
	this->createAttr(penWidth, penColor, bgColor);
}

ColorRect::ColorRect(const CPoint& point, const CSize& size, int penWidth, COLORREF penColor, COLORREF bgColor) : CRect(
	point, size)
{
	this->createAttr(penWidth, penColor, bgColor);
}

ColorRect::~ColorRect()
{
}

void ColorRect::paint( CDC * pDC ) const
{
	CPen* oldPen = static_cast<CPen*>(pDC->SelectObject( pen_.get() ));
	CBrush* oldBrush = static_cast<CBrush*>(pDC->SelectObject( brush_.get() ));
	pDC->Rectangle( left, top, right, bottom );
	static_cast<CPen*>(pDC->SelectObject( oldPen ));
	static_cast<CBrush*>(pDC->SelectObject( oldBrush ));
}

void
ColorRect::setAttr(int penWidth, COLORREF penColor, COLORREF bgColor)
{
	pen_->DeleteObject();
	brush_->DeleteObject();

	pen_->CreatePen(  PS_SOLID, penWidth, penColor );
	brush_->CreateSolidBrush(bgColor);
}

std::shared_ptr<CPen>
ColorRect::getPen() const
{
	return this->pen_;
}

std::shared_ptr<CBrush>
ColorRect::getBrush() const
{
	return this->brush_;
}

void
ColorRect::createAttr(int penWidth, COLORREF penColor, COLORREF bgColor)
{
	pen_ = std::make_shared<CPen>(PS_SOLID, penWidth, penColor);
	brush_ = std::make_shared<CBrush>(bgColor);
}
