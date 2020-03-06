#include "stdafx.h"
#include "Chart.h"
#include <random>
#include <iterator>
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
	loadColors();
	fontAxisX = std::make_shared<CFont>();
	fontAxisY = std::make_shared<CFont>();
	createFont( fontAxisX, L"Times New Roman", -16, -9 );
	createFont( fontAxisY, L"Calibri", -16, -10 );
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
	this->resetSorts();
	sortsType = choice;
	this->fillArray();
	this->sort();
}

void Chart::paint( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	sortBars.clear();
	grid.calculateLines( clientWindow );
	grid.paint( pDC );
	calculateLabelsY();
	paintLabelsY( clientWindow, pDC );
	paintLabelsX( clientWindow, pDC );
	createBars( clientWindow );
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
	str.LoadStringW( IDS_HEAP_SORT );
	labelsEfficientSorts[1] = str;
	str.LoadStringW( IDS_HALF_SORT );
	labelsEfficientSorts[2] = str;
}

void Chart::loadColors()
{
	barColors[0] = MINT;
	barColors[1] = VIOLET;
	barColors[4] = GRASS;
	barColors[3] = SALMON;
	barColors[2] = SKY_BLUE;
	barColors[5] = PINK;
}

void Chart::calculateLabelsY()
{
	CString str;
	for ( int i = 0; i < 20; ++i )
	{
		str.Format( L"%lu", static_cast<unsigned long>(max / 19.0 * (19 - i)) );
		labelsY[i+1] = str;
	}
	//str.Format( L"%lu", 10 - ((max + max / 38) % 10) + (max + max / 38) );
	str.Format( L"%lu", max + max / 38 );
	labelsY[0] = str;
}

void Chart::paintLabelsX( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	CFont* oldFont = (CFont*)pDC->SelectObject( fontAxisX.get() );
	int idx = 0;
	if(sortsType == ALL || sortsType == SIMPLE)
		for(auto &string : labelsSimpleSorts )
			pDC->TextOutW( 150 + (100 * idx++), clientWindow->Height() * .91 + 10, string );
	if ( sortsType == ALL || sortsType == EFFICIENT )
		for ( auto &string : labelsEfficientSorts )
			pDC->TextOutW( 150 + (100 * idx++), clientWindow->Height() * .91 + 10, string );
	pDC->SelectObject( oldFont );
}

void Chart::paintLabelsY( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	CFont* oldFont = (CFont*)pDC->SelectObject( fontAxisY.get() );
	for(int i = 0; i <= 20; ++i )
		pDC->TextOutW( 60, static_cast<int>(clientWindow->Height() * .9 / 20 * i), labelsY[i] );
	pDC->SelectObject( oldFont );
}

void Chart::fillArray()
{
	int *p = sortArr;
	for ( int i = 0; i < MAX_ELEMENTS; ++i, ++p )
		*p = rand() % MAX_ELEMENTS;
}

void Chart::createBars( std::shared_ptr<CRect> clientWindow )
{
	for(int i = 0; i < sortTimes.size(); ++i )
		sortBars.push_back( ColorRect( CPoint( clientWindow->Height() * .9 + 10, 170 + 97 * i),
			CSize( -((clientWindow->Height() * .9 - clientWindow->Height() * .9 / 20) / max * sortTimes[i]), 30 ), 1, BLACK, barColors[i] ) );
}

void Chart::callSort( std::function<void( int*, int )> sort )
{
	unsigned long sortTime;
	int *arr = new int[MAX_ELEMENTS];
	for ( int i = 0; i < MAX_ELEMENTS; ++i )
		arr[i] = sortArr[i];
	unsigned long startTime = GetTickCount();
	sort( arr, MAX_ELEMENTS );
	unsigned long endTime = GetTickCount();
	sortTime = endTime - startTime;
	max = sortTime > max ? sortTime : max;
	sortTimes.push_back( sortTime );
	delete []arr;
}

void Chart::sort()
{
	if ( sortsType == ALL || sortsType == SIMPLE )
	{
		callSort( BubbleSort );
		callSort( SelectionSort );
		callSort( InsertionSort );
	}
	if ( sortsType == ALL || sortsType == EFFICIENT )
	{
		callSort( callQuickSort );
		callSort( HeapSort );
		callSort( HalfSort );
	}
		
}

void Chart::resetSorts()
{
	sortTimes.clear();
	sortBars.clear();
	max = 40;
}

void Chart::createFont( std::shared_ptr<CFont> fontObj, CString fontType, int height, int width)
{
	LOGFONT logFont;
	memset( &logFont, 0, sizeof( LOGFONT ) );
	lstrcpy( logFont.lfFaceName, fontType.GetBuffer() );
	logFont.lfCharSet = DEFAULT_CHARSET;
	logFont.lfWeight = FW_REGULAR;
	logFont.lfHeight = height;
	logFont.lfWidth = width;
	if ( !fontObj->CreateFontIndirect( &logFont ) )
		TRACE0( "Could not create font for the trends\n" );
}

