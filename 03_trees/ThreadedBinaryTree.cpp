#include "stdafx.h"
#include "ThreadedBinaryTree.h"

ThreadedBinaryTree::ThreadedBinaryTree()
{
	root_ = std::make_shared<struct Node>();
	root_->right = root_->left = root_;
	root_->lTag = root_->rTag = 0;
	root_->keyValue = Random::random(MIN_VALUE, MAX_VALUE);
}

ThreadedBinaryTree::~ThreadedBinaryTree()
{
}

void
ThreadedBinaryTree::clear()
{
	root_ = std::make_shared<struct Node>();
	root_->right = root_->left = root_;
	root_->lTag = root_->rTag = 0;
	root_->keyValue = Random::random( MIN_VALUE, MAX_VALUE );
}

void
ThreadedBinaryTree::insert(const char key )
{
	auto newNode = std::make_shared<struct Node>();
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

void
ThreadedBinaryTree::printInOrder( std::shared_ptr<CRect> clientWindow, CDC *pDC )
{
	int offset = 0;
	auto current = root_->left;
	while ( current->lTag )
	{
		current = current->left;
	}
	while ( current != root_ )
	{
		CString key = CString( current->keyValue );
		pDC->TextOutW( 10 + offset * 10, static_cast<int>(clientWindow->Height() * 0.9), key );
		offset++;
		if ( !current->rTag )
		{
			current = current->right;
		}
		else
		{
			current = current->right;
			while ( current->lTag )
			{
				current = current->left;
			}
		}
	}
}


bool ThreadedBinaryTree::findKey( const char key ) const
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

