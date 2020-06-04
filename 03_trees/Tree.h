#pragma once
#include "Node.h"

template <typename T>
class ThreadedBinaryTree
{
public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	//ThreadedBinaryTree( const ThreadedBinaryTree& tree );
	//ThreadedBinaryTree& operator=( const ThreadedBinaryTree& tree );
	void clear();
	void insert( T key );
	void printTree();

private:
	std::shared_ptr<struct Node> root;
	
};