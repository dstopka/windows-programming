#include "stdafx.h"
#include "Chart.h"


Chart::Chart()
{
	this->grid = std::make_shared<Grid>();
}


Chart::~Chart()
{}

std::shared_ptr<Grid> Chart::getGrid()
{
	return this->grid;
}
