#pragma once
#include <array>
#include <memory>
#include <vector>
#include <functional>
#include <map>

#include "ColorRect.h"
#include "Grid.h"

#define MAX_ELEMENTS 10000

enum sorts { ALL, SIMPLE, EFFICIENT };

class Chart
{
public:
	Chart();
	Chart( const Chart& chart );
	Chart( const Chart&& chart ) noexcept;
	Chart& operator=( const Chart& chart );
	Chart& operator=( Chart&& chart ) noexcept;
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
	std::map<std::string, std::array<CString, 3>> labelsAxisX_;
	std::array<CString, 21> labelsAxisY_;
	
	sorts sortsType_;
	std::vector<ColorRect> sortBars_;
	std::array<COLORREF, 6> barColors_;

	int* sortArray_;
	std::vector<unsigned long> sortTimes_;
	unsigned long max_;

	std::shared_ptr<CFont> fontAxisX_;
	std::shared_ptr<CFont> fontAxisY_;
};
