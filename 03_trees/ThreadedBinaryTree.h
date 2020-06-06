#pragma once
#include <string>

#include "Node.h"
#include "RandomGenerator.h"

#define MIN_VALUE 1
#define MAX_VALUE 100

class ThreadedBinaryTree
{
public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	//ThreadedBinaryTree( const ThreadedBinaryTree& tree );
	//ThreadedBinaryTree& operator=( const ThreadedBinaryTree& tree );
	void clear();
	void insert(const char key );
	std::string printInOrder() const;
	void draw( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	bool findKey( const char key ) const;

private:
	void drawNode( std::shared_ptr<Node> node, int x, int y, int lvl, std::shared_ptr<CRect> clientWindow, CDC * pDC );
	std::shared_ptr<struct Node> root_;
	bool direction_left_;
	bool direction_right_;

};