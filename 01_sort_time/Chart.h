#pragma once
#include <array>
#include <memory>
#include "ColorRect.h"
#include "Grid.h"

class Chart
{
public:
	Chart();
	~Chart();

	std::shared_ptr<Grid> getGrid();

private:
	std::shared_ptr<Grid> grid;	
};

