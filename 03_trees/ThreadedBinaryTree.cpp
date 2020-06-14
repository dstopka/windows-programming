#include "stdafx.h"
#include "ThreadedBinaryTree.h"
#include <math.h>

ThreadedBinaryTree::ThreadedBinaryTree()
{
	srand( time( nullptr ) );
	root_ = std::make_shared<struct Node>();
	root_->right = root_->left = root_;
	root_->lTag = false;
	root_->rTag = true;
	root_->keyValue = MAX_VALUE;
	insertPen_ = std::make_shared<CPen>( PS_SOLID, 1, RGB(255, 0, 0) );
	brush_ = std::make_shared<CBrush>( RGB( 255, 0, 0 ) );
}

ThreadedBinaryTree::~ThreadedBinaryTree()
{
}

void
ThreadedBinaryTree::clear()
{
	root_ = std::make_shared<struct Node>();
	root_->right = root_->left = root_;
	root_->lTag = false;
	root_->rTag = true;
	root_->keyValue = MAX_VALUE;
}

void
ThreadedBinaryTree::insert( std::shared_ptr<CRect> clientWindow, CDC * pDC, const int key )
{
	int offset = pow( 2, depth_ - 1 ) * 16 + 50;
	CBrush* oldBrush = static_cast<CBrush*>(pDC->SelectObject( brush_.get() ));
	int x = clientWindow->Width() * 0.5;
	int y = clientWindow->Height() * 0.1;
	
	int dep = 0;
	auto newNode = std::make_shared<struct Node>();
	newNode->keyValue = key;

	if ( root_ == root_->left && root_ == root_->right )
	{
		newNode->left = root_;
		newNode->right = root_;
		root_->left = newNode;
		root_->lTag = true;
		newNode->lTag = newNode->rTag = false;
		depth_ = 1;
		pDC->Ellipse( x, y, x + 32, y + 32 );
		CString keyStr;
		keyStr.Format( L"%d", newNode->keyValue );
		pDC->TextOutW( x + 8, y + 6, keyStr );
		Sleep( 500 );
	}
	else
	{
		auto current = root_->left;
		
		for ( ;;)
		{
			pDC->Ellipse( x, y, x + 32, y + 32 );
			CString keyStr;
			keyStr.Format( L"%d",current ->keyValue );
			pDC->TextOutW( x + 8, y + 6, keyStr );
			Sleep( 500 );
			if ( current->keyValue > newNode->keyValue )
			{
				if ( !current->lTag )
				{
					direction_left_ = true;
					direction_right_ = false;
					break;
				}
				current = current->left;
				dep++;
				x -= offset;
				y += 50;
				offset *= 0.5;
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
				dep++;
				x += offset;
				y += 50;
				offset *= 0.5;
			}
		}
		if ( direction_left_ )
		{
			newNode->left = current->left;
			newNode->right = current;
			current->left = newNode;
			newNode->lTag = newNode->rTag = false;
			current->lTag = true;
			dep++;
			x -= offset;
			y += 50;
		}
		else if ( direction_right_ )
		{
			newNode->right = current->right;
			newNode->left = current;
			current->right = newNode;
			newNode->lTag = newNode->rTag = false;
			current->rTag = true;
			dep++;
			x += offset;
			y += 50;
		}
		pDC->Ellipse( x, y, x + 32, y + 32 );
		CString keyStr;
		keyStr.Format( L"%d", newNode->keyValue );
		pDC->TextOutW( x + 8, y + 6, keyStr );
		Sleep( 1000 );
	}

	if ( dep > depth_ )
		depth_ = dep;

	static_cast<CBrush*>(pDC->SelectObject( oldBrush ));
}

void
ThreadedBinaryTree::insert( const int key )
{
	int dep = 0;
	auto newNode = std::make_shared<struct Node>();
	newNode->keyValue = key;

	if ( root_ == root_->left && root_ == root_->right )
	{
		newNode->left = root_;
		newNode->right = root_;
		root_->left = newNode;
		root_->lTag = true;
		newNode->lTag = newNode->rTag = false;
		depth_ = 1;
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
				dep++;
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
				dep++;
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

	if ( dep + 1 > depth_ )
		depth_ = dep + 1;

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
		result += std::to_string( current->keyValue );
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

void
ThreadedBinaryTree::draw( std::shared_ptr<CRect> clientWindow, CDC * pDC )
{
	if ( root_->lTag )
		drawNode( root_->left, clientWindow->Width() * 0.5, clientWindow->Height() * 0.1, pow(2, depth_ - 1) * 16 + 50, clientWindow, pDC );
}


bool
ThreadedBinaryTree::findKey( const char key ) const
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

void
ThreadedBinaryTree::drawNode( std::shared_ptr<Node> node, int x, int y, int offset, std::shared_ptr<CRect> clientWindow, CDC * pDC )
{
	if ( node->rTag )
	{
		pDC->MoveTo( x + 27, y + 27 );
		pDC->LineTo( x + offset + 5, y + 55 );
		drawNode( node->right, x + offset, y + 50, int( offset * 0.5), clientWindow, pDC );
	}

	pDC->Ellipse( x, y, x + 32, y + 32 );
	CString key;
	key.Format( L"%d", node->keyValue );
	pDC->TextOutW( x + 8, y + 6, key );

	if ( node->lTag )
	{
		pDC->MoveTo( x + 5, y + 27 );
		pDC->LineTo( x - offset + 27, y + 55 );
		drawNode( node->left, x - offset, y + 50, int( offset * 0.5), clientWindow, pDC );
	}
}

