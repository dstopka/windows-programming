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

void ColorRect::paint(CDC* pDC)
{
	CPen* oldPen = static_cast<CPen*>(pDC->SelectObject(this->pen_.get()));
	CBrush* oldBrush = static_cast<CBrush*>(pDC->SelectObject(this->brush_.get()));
	pDC->Rectangle(this->top, this->left, this->bottom, this->right);
	static_cast<CPen*>(pDC->SelectObject(oldPen));
	static_cast<CBrush*>(pDC->SelectObject(oldBrush));
}

void ColorRect::setAttr(int penWidth, COLORREF penColor, COLORREF bgColor)
{
}

std::shared_ptr<CPen> ColorRect::getPen()
{
	return this->pen_;
}

std::shared_ptr<CBrush> ColorRect::getBrush()
{
	return this->brush_;
}

void ColorRect::createAttr(int penWidth, COLORREF penColor, COLORREF bgColor)
{
	this->pen_ = std::make_shared<CPen>(PS_SOLID, penWidth, penColor);
	this->brush_ = std::make_shared<CBrush>(bgColor);
}
