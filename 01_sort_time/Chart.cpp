#include "stdafx.h"
#include "Chart.h"

#include "resource.h"


Chart::Chart()
{
	grid = Grid();
	this->loadSortsLabels();
}


Chart::~Chart()
{}

Grid& Chart::getGrid()
{
	return this->grid;
}

std::vector<ColorRect>& Chart::getRects()
{
	return this->sortBars;
}

void Chart::setSortsType( enum sorts choice )
{
	sortsType = choice;	
}

void Chart::paint( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	grid.calculateLines( clientWindow );
	grid.paint( pDC );
	paintLabelsX( clientWindow, pDC );		
}

void Chart::loadSortsLabels()
{
	CString str;
	str.LoadStringW( IDS_BUBBLE_SORT );
	labelsSimpleSorts[0] = str;
	str.LoadStringW( IDS_SELECT_SORT );
	labelsSimpleSorts[1] = str;
	str.LoadStringW( IDS_INSERT_SORT );
	labelsSimpleSorts[2] = str;
	str.LoadStringW( IDS_QUICK_SORT );
	labelsEfficientSorts[0] = str;
	str.LoadStringW( IDS_HALF_SORT );
	labelsEfficientSorts[1] = str;
	str.LoadStringW( IDS_HEAP_SORT );
	labelsEfficientSorts[2] = str;
}

void Chart::paintLabelsX( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	int idx = 0;
	if(sortsType == ALL || sortsType == SIMPLE)
		for(auto &string : labelsSimpleSorts )
			pDC->TextOutW( 150 + (100 * idx++), clientWindow->Height() * .9 + 10, string );
	if ( sortsType == ALL || sortsType == EFFICIENT )
		for ( auto &string : labelsEfficientSorts )
			pDC->TextOutW( 150 + (100 * idx++), clientWindow->Height() * .9 + 10, string );
}

void Chart::paintLabelsY( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
}

