#pragma once
#include "Node.h"
#include "RandomGenerator.h"

#define TREE_TYPE char
#define MIN_VALUE 'a'
#define MAX_VALUE 'z'

template <typename T>
class ThreadedBinaryTree
{
public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	//ThreadedBinaryTree( const ThreadedBinaryTree& tree );
	//ThreadedBinaryTree& operator=( const ThreadedBinaryTree& tree );
	void clear();
	void insert(const T key );
	void printInOrder();
	bool findKey( const T key ) const;

private:
	std::shared_ptr<struct Node<T>> root_;
	bool direction_left_;
	bool direction_right_;

};