#include "stdafx.h"
#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	this->penOutline_ = std::make_shared<CPen>(PS_SOLID, 1, BLACK);
	this->penGrid_ = std::make_shared<CPen>(PS_SOLID, 1, GREY);
}


Grid::~Grid()
{
}

void
Grid::paint(CDC* pDC)
{
	CPen* pOldPen = pDC->SelectObject(penOutline_.get());
	pDC->MoveTo(outline_.top);
	pDC->LineTo(outline_.intersection);
	pDC->LineTo(outline_.right);
	pDC->SelectObject(penGrid_.get());
	for (auto& x : lines_)
	{
		pDC->MoveTo(x[0]);
		pDC->LineTo(x[1]);
	}
	pDC->SelectObject(pOldPen);
}

void
Grid::calculateLines(std::shared_ptr<CRect> clientWindow)
{
	this->outline_.top = {100, 10};
	this->outline_.intersection = {100, static_cast<int>(clientWindow->Height() * .9) + 10};
	this->outline_.right = {static_cast<int>(clientWindow->Width() * .9), static_cast<int>(clientWindow->Height() * .9) + 10};
	for (auto i = 19; i > 0; --i)
	{
		this->lines_[i][0] = {100, static_cast<int>(clientWindow->Height() * .9 / 20 * i) + 10};
		this->lines_[i][1] = {static_cast<int>(clientWindow->Width() * .9), static_cast<int>(clientWindow->Height() * .9 / 20 * i) + 10};
	}
	this->lines_[0][0] = {100, 10};
	this->lines_[0][1] = {static_cast<int>(clientWindow->Width() * .9), 10};
}