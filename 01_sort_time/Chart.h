#pragma once
#include <array>
#include <memory>
#include <vector>
#include <functional>
#include "ColorRect.h"
#include "Grid.h"

#define MAX_ELEMENTS 10000

enum sorts { ALL, SIMPLE, EFFICIENT };

class Chart
{
public:
	Chart();
	~Chart();
	Grid &getGrid();
	std::vector<ColorRect> &getRects();
	void setSortsType(enum sorts choice);
	void paint( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	
private:
	void loadSortsLabels();
	void loadColors();
	void calculateLabelsY();
	void paintLabelsX( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	void paintLabelsY( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	void fillArray();
	void createBars( std::shared_ptr<CRect> clientWindow );
	void callSort( std::function<void( int*, int )> sort );
	void sort();
	void resetSorts();
	void createFont( std::shared_ptr<CFont> fontObj, CString fontType, int height, int width );
	
private:
	std::array<CString, 3> labelsSimpleSorts;
	std::array<CString, 3> labelsEfficientSorts;
	Grid grid;
	std::array<CString, 21> labelsY;	
	std::vector<ColorRect> sortBars;
	std::vector<unsigned long> sortTimes;
	int* sortArr = new int[MAX_ELEMENTS];
	std::array<COLORREF, 6> barColors;
	sorts sortsType;
	unsigned long max;
	std::shared_ptr<CFont> fontAxisX;
	std::shared_ptr<CFont> fontAxisY;
};
