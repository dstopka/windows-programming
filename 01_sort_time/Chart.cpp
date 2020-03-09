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
	this->loadSortsLabels();
	sortArray_ = new int[MAX_ELEMENTS];
	std::srand( std::time( nullptr ) );
	max_ = 40;
	this->loadColors();
	fontAxisX_ = std::make_shared<CFont>();
	fontAxisY_ = std::make_shared<CFont>();
	createFont( fontAxisX_, L"Open Sans", -16, -10 );
	createFont( fontAxisY_, L"Calibri", -16, -10 );
}


Chart::~Chart()
{
	delete []sortArray_;
}

void
Chart::setSortsType( enum sorts choice )
{
	sortsType_ = choice;
	this->resetSorts();
	this->sort();
	std::random_shuffle( barColors_.begin(), barColors_.end() );
}

void
Chart::paint( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	sortBars_.clear();
	grid_.calculateLines( clientWindow );
	grid_.paint( pDC );
	calculateLabelsY();
	paintLabelsY( clientWindow, pDC );
	paintLabelsX( clientWindow, pDC );
	createBars( clientWindow );
	for ( auto &x : sortBars_ )
		x.paint( pDC );
}

void
Chart::loadSortsLabels()
{
	CString str;
	str.LoadStringW( IDS_BUBBLE_SORT );
	labelsAxisX_["Simple Sorts"][0] = str;
	str.LoadStringW( IDS_SELECT_SORT );
	labelsAxisX_["Simple Sorts"][1] = str;
	str.LoadStringW( IDS_INSERT_SORT );
	labelsAxisX_["Simple Sorts"][2] = str;
	str.LoadStringW( IDS_QUICK_SORT );
	labelsAxisX_["Efficient Sorts"][0] = str;
	str.LoadStringW( IDS_HEAP_SORT );
	labelsAxisX_["Efficient Sorts"][1] = str;
	str.LoadStringW( IDS_HALF_SORT );
	labelsAxisX_["Efficient Sorts"][2] = str;
}

void
Chart::loadColors()
{
	barColors_[0] = MINT;
	barColors_[1] = VIOLET;
	barColors_[4] = GRASS;
	barColors_[3] = SALMON;
	barColors_[2] = SKY_BLUE;
	barColors_[5] = PINK;
}

void
Chart::calculateLabelsY()
{
	CString str;
	for ( int i = 0; i < 20; ++i )
	{
		str.Format( L"%lu", static_cast<unsigned long>(max_ / 19.0 * (19 - i)) );
		labelsAxisY_[i+1] = str;
	}

	str.Format( L"%lu", max_ + max_ / 38 );
	labelsAxisY_[0] = str;
}

void
Chart::paintLabelsX( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	CFont* oldFont = static_cast<CFont*>(pDC->SelectObject( fontAxisX_.get() ));
	
	int idx = 0;
	if(sortsType_ == ALL || sortsType_ == SIMPLE)
		for(auto &string : labelsAxisX_["Simple Sorts"] )
			pDC->TextOutW( 148 + (95 * idx++), clientWindow->Height() * 0.91 + 10, string );
	
	if ( sortsType_ == ALL || sortsType_ == EFFICIENT )
		for ( auto &string : labelsAxisX_["Efficient Sorts"] )
			pDC->TextOutW( 148 + (95 * idx++), clientWindow->Height() * 0.91 + 10, string );
	
	pDC->SelectObject( oldFont );
}

void
Chart::paintLabelsY( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	CFont* oldFont = static_cast<CFont*>(pDC->SelectObject( fontAxisY_.get() ));
	for(int i = 0; i <= 20; ++i )
		pDC->TextOutW( 55, static_cast<int>(clientWindow->Height() * 0.9 / 20 * i), labelsAxisY_[i] );
	pDC->SelectObject( oldFont );
}

void
Chart::createBars( std::shared_ptr<CRect> clientWindow )
{
	for ( size_t i = 0; i < sortTimes_.size(); ++i )
	{
		CPoint leftBottom = CPoint( 165 + 95 * i, clientWindow->Height() * 0.9 + 10 );
		CSize barSize = CSize( 30, -((clientWindow->Height() * 0.9 - clientWindow->Height() * 0.9 / 20.0) / max_ * sortTimes_[i]) );
		sortBars_.push_back( ColorRect( leftBottom, barSize, 1, BLACK, barColors_[i] ) );
	}
}

void
Chart::callSort( std::function<void( int*, int )> sort )
{
	int nSize = sortsType_ == SIMPLE ? SIMPLE_SORTS_ELEMENTS : MAX_ELEMENTS;
	int *arr = new int[nSize];
	for ( int i = 0; i < nSize; ++i )
		arr[i] = sortArray_[i];	
	unsigned long startTime = GetTickCount();
	sort( arr, nSize );
	unsigned long endTime = GetTickCount();
	unsigned long sortTime = endTime - startTime;
	max_ = sortTime > max_ ? sortTime : max_;
	sortTimes_.push_back( sortTime );
	
	delete []arr;
}

void
Chart::sort()
{
	if ( sortsType_ == ALL || sortsType_ == SIMPLE )
	{
		callSort( BubbleSort );
		callSort( SelectionSort );
		callSort( InsertionSort );
	}
	
	if ( sortsType_ == ALL || sortsType_ == EFFICIENT )
	{
		callSort( callQuickSort );
		callSort( HeapSort );
		callSort( HalfSort );
	}		
}

void
Chart::resetSorts()
{
	sortTimes_.clear();
	sortBars_.clear();
	max_ = 40;
	delete []sortArray_;
	if ( sortsType_ == SIMPLE )
	{
		sortArray_ = new int[SIMPLE_SORTS_ELEMENTS];
		fillArray( sortArray_, SIMPLE_SORTS_ELEMENTS );
	}
	else
	{
		sortArray_ = new int[MAX_ELEMENTS];
		fillArray( sortArray_, MAX_ELEMENTS );
	}
}

void
Chart::createFont( std::shared_ptr<CFont> fontObj, CString fontType, int height, int width)
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

