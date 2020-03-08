#pragma once

#include <array>
#include <memory>

struct Outline
{
	CPoint top;
	CPoint intersection;
	CPoint right;
};

class Grid
{
public:
	Grid();
	~Grid();
	void paint( CDC *pDC );
	void calculateLines( std::shared_ptr<CRect> clientWindow);

private:
	//void setAttr( int penWidth = 0, COLORREF penColor = BLACK, COLORREF bgColor = BLACK );
	Outline outline_;
	std::array<std::array<CPoint, 2>, 20> lines_;
	std::shared_ptr<CPen> penGrid_;
	std::shared_ptr<CPen> penOutline_;
};

