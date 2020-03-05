#pragma once
#include <array>
#include <memory>
#include <vector>
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
	void paintLabelsX( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	void paintLabelsY( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	
private:
	std::array<CString, 3> labelsSimpleSorts;
	std::array<CString, 3> labelsEfficientSorts;
	Grid grid;
	std::vector<CString> labelsX;	
	std::vector<ColorRect> sortBars;
	std::array<int, MAX_ELEMENTS> sortArr;
	sorts sortsType;
};
