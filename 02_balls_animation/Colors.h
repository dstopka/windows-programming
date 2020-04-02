#pragma once

#include <vector>

#define BLACK		RGB(0, 0, 0)
#define GREY		RGB(200, 200, 200)
#define MINT		RGB(66, 245, 176)
#define VIOLET		RGB(245, 66, 242)
#define GRASS		RGB(147, 245, 66)
#define SALMON		RGB(245, 156, 66)
#define SKY_BLUE	RGB(66, 126, 245)
#define PINK		RGB(245, 66, 138)

namespace Colors
{
	static const std::vector<COLORREF> colors = { MINT, VIOLET, GRASS, SALMON, SKY_BLUE };
};