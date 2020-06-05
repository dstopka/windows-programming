#pragma once
#include <memory>

struct Node
{
	int keyValue;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	bool rTag;
	bool lTag;
};