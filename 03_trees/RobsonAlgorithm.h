#pragma once
#include <string>

#include "Node.h"

class RobsonTraversal
{
	enum class visitType { preOrder, inOrder, postOrder };
	
public:
	RobsonTraversal(std::shared_ptr<Node> root);
	~RobsonTraversal();
	std::string printInOrder();
	std::string printPreOrder();
	std::string printPostOrder();
	std::string inVisit();

	std::string postVisit();

	std::string preVisit();

private:
	void start(std::string& res);
	std::shared_ptr<Node> root_;
	std::shared_ptr<Node> previous_;
	std::shared_ptr<Node> present_;
	std::shared_ptr<Node> top_;
	std::shared_ptr<Node> stack_;
	std::shared_ptr<Node> avail_{};
	std::shared_ptr<Node> next_{};
	visitType visitType_;
};

