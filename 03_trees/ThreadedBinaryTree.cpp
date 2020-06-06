#include "stdafx.h"
#include "ThreadedBinaryTree.h"

ThreadedBinaryTree::ThreadedBinaryTree()
{
	srand( time( nullptr ) );
	root_ = std::make_shared<struct Node>();
	root_->right = root_->left = root_;
	root_->lTag = 0;
	root_->rTag = 1;
	root_->keyValue = MAX_VALUE;
}

ThreadedBinaryTree::~ThreadedBinaryTree()
{
}

void
ThreadedBinaryTree::clear()
{
	root_ = std::make_shared<struct Node>();
	root_->right = root_->left = root_;
	root_->lTag = 0;
	root_->rTag = 1;
	root_->keyValue = MAX_VALUE;
}

void
ThreadedBinaryTree::insert( const char key )
{
	auto newNode = std::make_shared<struct Node>();
	newNode->keyValue = key;

	if ( root_ == root_->left && root_ == root_->right )
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
		for ( ;;)
		{
			if ( current->keyValue > newNode->keyValue )
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
				if ( !current->rTag )
				{
					direction_right_ = true;
					direction_left_ = false;
					break;
				}
				current = current->right;
			}
		}
		if ( direction_left_ )
		{
			newNode->left = current->left;
			newNode->right = current;
			current->left = newNode;
			newNode->lTag = newNode->rTag = false;
			current->lTag = true;

		}
		else if ( direction_right_ )
		{
			newNode->right = current->right;
			newNode->left = current;
			current->right = newNode;
			newNode->lTag = newNode->rTag = false;
			current->rTag = true;
		}
	}
}

std::string
ThreadedBinaryTree::printInOrder() const
{
	std::string result( "" );
	auto current = root_->left;
	while ( current->lTag )
	{
		current = current->left;
	}
	while ( current != root_ )
	{
		result += std::to_string(current->keyValue);
		result += " ";
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
	
	return result;
}

void ThreadedBinaryTree::draw( std::shared_ptr<CRect> clientWindow, CDC * pDC )
{
	if ( root_->lTag )
		drawNode( root_->left, clientWindow->Width() * 0.5, clientWindow->Height() * 0.1, 1, clientWindow, pDC );
}


bool ThreadedBinaryTree::findKey( const char key ) const
{
	auto current = root_->left;
	for ( ;; )
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

void ThreadedBinaryTree::drawNode( std::shared_ptr<Node> node, int x, int y, int lvl, std::shared_ptr<CRect> clientWindow, CDC * pDC )
{

	if ( node->rTag )
	{
		pDC->MoveTo( x + 27, y + 27 );
		pDC->LineTo( x + 200 / lvl + 5, y + 55 );
		drawNode( node->right, x + 200 / lvl, y + 50, lvl + 1, clientWindow, pDC );
	}

	pDC->Ellipse( x, y, x + 32, y + 32 );
	CString key;
	key.Format( L"%d", node->keyValue );
	pDC->TextOutW( x + 11, y + 5, key );

	if ( node->lTag )
	{
		pDC->MoveTo( x + 5, y + 27 );
		pDC->LineTo( x - 200 / lvl + 27, y + 55 );
		drawNode( node->left, x - 200 / lvl, y + 50, lvl + 1, clientWindow, pDC );
	}
}

