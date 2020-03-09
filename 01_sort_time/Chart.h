#pragma once
#include <array>
#include <memory>
#include <vector>
#include <functional>
#include <map>

#include "ColorRect.h"
#include "Grid.h"

#define MAX_ELEMENTS			50000
#define SIMPLE_SORTS_ELEMENTS	10000
#define COLORS_NUMBER			6
#define VERTICAL_DIVISION		21
#define SORTS_GROUP_NUMBER		3

enum sorts { ALL, SIMPLE, EFFICIENT };

class Chart
{
public:
	Chart();
	~Chart();

	void setSortsType(enum sorts choice);
	void paint( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	static void createFont( std::shared_ptr<CFont> fontObj, CString fontType, int height, int width );
	
private:
	void loadSortsLabels();
	void loadColors();
	void calculateLabelsY();
	void paintLabelsX( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	void paintLabelsY( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	void createBars( std::shared_ptr<CRect> clientWindow );
	void callSort( std::function<void( int*, int )> sort );
	void sort();
	void resetSorts();
	
private:
	Grid grid_;
	std::map<std::string, std::array<CString, SORTS_GROUP_NUMBER>> labelsAxisX_;
	std::array<CString, VERTICAL_DIVISION> labelsAxisY_;
	
	sorts sortsType_;
	std::vector<ColorRect> sortBars_;
	std::array<COLORREF, COLORS_NUMBER> barColors_;

	int* sortArray_;
	std::vector<unsigned long> sortTimes_;
	unsigned long max_;

	std::shared_ptr<CFont> fontAxisX_;
	std::shared_ptr<CFont> fontAxisY_;
};
