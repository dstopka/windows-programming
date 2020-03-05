#include "stdafx.h"
#include "Chart.h"
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "sorts.h"
#include "resource.h"


Chart::Chart()
{
	grid = Grid();
	this->loadSortsLabels();
	sortArr = new int[MAX_ELEMENTS];
	std::srand( std::time( nullptr ) );
	max = 40;
}


Chart::~Chart()
{
	delete sortArr;
}

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
	this->fillArray();
	this->sort();
}

void Chart::paint( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	grid.calculateLines( clientWindow );
	grid.paint( pDC );
	paintLabelsX( clientWindow, pDC );
	for ( auto &x : sortBars )
		x.paint( pDC );
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

void Chart::fillArray()
{
	int* p = sortArr;
	for ( int i = 0; i < MAX_ELEMENTS; ++i, ++p )
		*p = rand() % MAX_ELEMENTS;
}

unsigned long Chart::callSort( std::function<void( int*, int )> sort )
{
	int* arr = new int[MAX_ELEMENTS];
	std::copy( sortArr, sortArr + MAX_ELEMENTS, stdext::checked_array_iterator<int*>(arr, MAX_ELEMENTS ));
	unsigned long startTime = GetTickCount();
	sort( arr, MAX_ELEMENTS );
	unsigned long endTime = GetTickCount();
	delete []arr;

	return endTime - startTime;
}

void Chart::sort()
{
	unsigned long sortTime;
	int idx = 0;
	if ( sortsType == ALL || sortsType == SIMPLE )
	{
		sortTime = callSort( BubbleSort );
		max = sortTime > max ? sortTime : max;
		sortBars.push_back( ColorRect(CPoint(10,10), CPoint(50, 50), 1, PINK, PINK) );
	}
	//if ( sortsType == ALL || sortsType == EFFICIENT )
		
}
