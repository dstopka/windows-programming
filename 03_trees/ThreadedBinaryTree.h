#pragma once
#include "Node.h"
#include "RandomGenerator.h"

#define MIN_VALUE 'a'
#define MAX_VALUE 'z'

class ThreadedBinaryTree
{
public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	//ThreadedBinaryTree( const ThreadedBinaryTree& tree );
	//ThreadedBinaryTree& operator=( const ThreadedBinaryTree& tree );
	void clear();
	void insert(const char key );
	void printInOrder( std::shared_ptr<CRect> clientWindow, CDC *pDC );
	bool findKey( const char key ) const;

private:
	std::shared_ptr<struct Node> root_;
	bool direction_left_;
	bool direction_right_;

};