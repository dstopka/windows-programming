#include "stdafx.h"
#include "ThreadedBinaryTree.h"

template<typename T>
ThreadedBinaryTree<T>::ThreadedBinaryTree()
{
	root_ = std::make_shared<struct Node<T>>();
	root_->right = root_->left = root_;
	root_->lTag = root_->rTag = 0;
	root_->keyValue = Random::random(MIN_VALUE, MAX_VALUE);
}

template<typename T>
ThreadedBinaryTree<T>::~ThreadedBinaryTree()
{
}

template<typename T>
void
ThreadedBinaryTree<T>::clear()
{
	root_ = std::make_shared<struct Node<T>>();
	root_->right = root_->left = root_;
	root_->lTag = root_->rTag = 0;
	root_->keyValue = nullptr;
}

template<typename T>
void
ThreadedBinaryTree<T>::insert(const T key )
{
	auto newNode = std::make_shared<struct Node<T>>();
	newNode->keyValue = key;

	if(root_ == root_->left && root_ == root_->right )
	{
		newNode->left = root_;
		newNode->right = root_;
		root_->left = newNode;
		root_->lTag = true;
		newNode->lTag = newNode->rTag = false;
	}
	else
	{
		auto current = root_->left;
		for(;;)
		{
			if(current->keyValue > newNode->keyValue )
			{
				if ( !current->lTag )
				{
					direction_left_ = true;
					direction_right_ = false;
					break;
				}
				current = current->left;
			}
			else
			{
				if( !current->rTag )
				{
					direction_right_ = true;
					direction_left_ = false;
					break;
				}
				current = current->right;
			}
		}
		if(direction_left_ )
		{
			newNode->left = current->left;
			newNode->right = current;
			current->left = newNode;
			newNode->lTag = newNode->rTag = false;
			current->lTag = true;
			
		}
		else if (direction_right_ )
		{
			newNode->right = current->right;
			newNode->left = current;
			current->right = newNode;
			newNode->lTag = newNode->rTag = false;
			current->rTag = true;
		}
	}
}

template<typename T>
void
ThreadedBinaryTree<T>::printInOrder()
{
	auto current = root_->left;
	while ( current->l_tag )
	{
		current = current->left;
	}
	while ( current != root_ )
	{
		//std::cout << current->value << " ";

		if ( !current->r_tag )
		{
			current = current->right;
		}
		else
		{
			current = current->right;
			while ( current->l_tag )
			{
				current = current->left;
			}
		}
	}
	//std::cout << std::endl;
}

template<typename T>
bool ThreadedBinaryTree<T>::findKey( const T key ) const
{
	auto current = root_;
	for(;; )
	{
		if ( current->keyValue > key )
		{
			if ( !current->lTag )
				return false;
			current = current->left;
		}
		else if ( current->keyValue < key )
		{
			if ( !current->rTag )
				return false;
			current = current->right;
		}
		else
			return true;
	}
}

