#include "stdafx.h"
#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	this->penOutline = std::make_shared<CPen>(PS_SOLID, 1, BLACK);
	this->penGrid = std::make_shared<CPen>(PS_SOLID, 1, GREY);
}


Grid::~Grid()
{
}

void Grid::paint(CDC* pDC)
{
	CPen* pOldPen = pDC->SelectObject(penOutline.get());
	pDC->MoveTo(outline.top);
	pDC->LineTo(outline.intersection);
	pDC->LineTo(outline.right);
	pDC->SelectObject(penGrid.get());
	for (auto& x : lines)
	{
		pDC->MoveTo(x[0]);
		pDC->LineTo(x[1]);
	}
	pDC->SelectObject(pOldPen);
}

void Grid::calculateLines(std::shared_ptr<CRect> clientWindow)
{
	this->outline.top = {100, 10};
	this->outline.intersection = {100, static_cast<int>(clientWindow->Height() * .9)};
	this->outline.right = {static_cast<int>(clientWindow->Width() * .9), static_cast<int>(clientWindow->Height() * .9)};
	for (auto i = 19; i > 0; --i)
	{
		this->lines[i][0] = {100, static_cast<int>(clientWindow->Height() * .9 / 20 * i)};
		this->lines[i][1] = {static_cast<int>(clientWindow->Width() * .9), static_cast<int>(clientWindow->Height() * .9 / 20 * i)};
	}
	this->lines[0][0] = {100, 10};
	this->lines[0][1] = {static_cast<int>(clientWindow->Width() * .9), 10};
}

std::array<double, 20> Grid::getLinesY()
{
	std::array<double, 20> y;
	for ( int i = 0; i < 20; ++i )
		y[i] = lines[i][0].x;
	return y;
}
