#include "stdafx.h"
#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	this->pen = std::make_shared<CPen>();
}


Grid::~Grid()
{
}

void Grid::paint( CDC *pDC )
{
	this->pen->CreatePen( PS_SOLID, 1, RGB( 0, 0, 0 ) );
	CPen *pOldPen = pDC->SelectObject( pen.get() );
	pDC->MoveTo( outline.top );
	pDC->LineTo( outline.intersection );
	pDC->LineTo( outline.right);
	this->pen->DeleteObject();
	this->pen->CreatePen( PS_SOLID, 1, RGB( 200, 200, 200 ) );
	for(auto &x : lines )
	{
		pDC->MoveTo( x[0] );
		pDC->LineTo( x[1] );
	}
	this->pen->DeleteObject();
	pDC->SelectObject( pOldPen );
}

void Grid::calculateLines( std::shared_ptr<CRect> clientWindow)
{
	this->outline.top = { 30, 10 };
	this->outline.intersection = { 30, (int)(clientWindow->Height() * .9) };
	this->outline.right = { (int)(clientWindow->Width() * .9), (int)(clientWindow->Height() * .9) };
	for ( auto i = 0; i < 20; ++i )
	{
		this->lines[i][0] = { 30, 30 + (int)((clientWindow->Height() * .9) / 20 * i) };
		this->lines[i][1] = { (int)(clientWindow->Width() * .9), 30 +(int)((clientWindow->Height() * .9) / 20 * i) };
	}
	std::cout << this->lines[0][0].x << std::endl;
}
