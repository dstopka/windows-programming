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
	void calculateLabelsY();
	void paintLabelsX( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	void paintLabelsY( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	void fillArray();
	unsigned long callSort( std::function<void( int*, int )> sort );
	void sort();
	
private:
	std::array<CString, 3> labelsSimpleSorts;
	std::array<CString, 3> labelsEfficientSorts;
	Grid grid;
	std::vector<CString> labelsX;	
	std::vector<ColorRect> sortBars;
	int* sortArr;
	sorts sortsType;
	unsigned long max;
};
