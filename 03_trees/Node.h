#pragma once
#include <memory>

template <typename T>
struct Node
{
	T keyValue;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	bool rTag;
	bool lTag;
};