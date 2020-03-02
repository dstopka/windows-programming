#include "stdafx.h"
#include "Chart.h"


Chart::Chart()
{
	this->grid = Grid();
}


Chart::~Chart()
{}

Grid& Chart::getGrid()
{
	return this->grid;
}

std::vector<ColorRect>& Chart::getRects()
{
	return this->rects;
}
