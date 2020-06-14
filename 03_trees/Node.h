#pragma once
#include <memory>

struct Node
{
	int keyValue;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
};

struct ThreadedNode
{
	int keyValue;
	std::shared_ptr<ThreadedNode> left;
	std::shared_ptr<ThreadedNode> right;
	bool rTag;
	bool lTag;
};