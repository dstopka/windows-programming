#pragma once
#include "Node.h"

#define MIN_VALUE 1
#define MAX_VALUE 30
#define N_ELEMENTS 10

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void createRandTree();
	void draw( std::shared_ptr<CRect> clientWindow, CDC *pDC );

private:
	std::shared_ptr<Node> root_;
	void insert( const int key );
	void clear();
	bool search( std::shared_ptr<Node> node, const int key );
	int depth( std::shared_ptr<Node> node );
	void drawNode( std::shared_ptr<Node> node, int x, int y, int offset, CDC * pDC );
};

