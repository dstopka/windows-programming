#pragma once
#include <string>

#include "Node.h"
#include "RandomGenerator.h"

#define MIN_VALUE 1
#define MAX_VALUE 30

class ThreadedBinaryTree
{
public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	void clear();
	void insert( std::shared_ptr<CRect> clientWindow, CDC * pDC, const int key );
	void insert( const int key );
	std::string printInOrder() const;
	std::string printPreOrder();
	std::string printPostOrder();
	void draw( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	bool findKey( const char key ) const;

private:
	void drawNode( std::shared_ptr<Node> node, int x, int y, int lvl, std::shared_ptr<CRect> clientWindow, CDC * pDC );
	void printPreOrder( std::string& res, std::shared_ptr<struct Node> node );
	void printPostOrder( std::string& res, std::shared_ptr<struct Node> node );
	int depth_;
	std::shared_ptr<struct Node> root_;
	bool direction_left_;
	bool direction_right_;
	std::shared_ptr<CBrush> brush_;
};