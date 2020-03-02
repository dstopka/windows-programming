#pragma once
#include <array>
#include <memory>
#include <vector>
#include "ColorRect.h"
#include "Grid.h"

class Chart
{
public:
	Chart();
	~Chart();

	Grid &getGrid();
	std::vector<ColorRect> &getRects();

private:
	Grid grid;
	std::vector<CString> labelsX;
	std::vector<CString> labelsY;
	std::vector<ColorRect> rects;
};
