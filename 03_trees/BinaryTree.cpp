#include "stdafx.h"
#include "BinaryTree.h"

#include <queue>

#include "RandomGenerator.h"


BinaryTree::BinaryTree()
{
	root_ = std::make_shared<Node>();
	root_->keyValue = 0;
	root_->left = root_;
	root_->right = root_;
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::createRandTree()
{
	clear();
	for ( auto i = 0; i < N_ELEMENTS; i++ )
	{
		auto newKey = Random::random( MIN_VALUE, MAX_VALUE );
		if ( !search( root_, newKey) )
		{
			insert( newKey );
		}
		else
		{
			i--;
		}
	}
}

void BinaryTree::draw( std::shared_ptr<CRect> clientWindow, CDC * pDC )
{
	if ( root_ )
	{
		int dep = depth( root_ );
		drawNode( root_, static_cast<int>(clientWindow->Width() * 0.5), static_cast<int>(clientWindow->Height() * 0.1), static_cast<int>(pow( 2, dep - 1 ) * 16 + 50), pDC );
	}
}

void BinaryTree::insert( const int key )
{
	if (root_->right == root_ && root_->left == root_)
	{
		root_->keyValue = key;
		root_->left = nullptr;
		root_->right = nullptr;
	}
	else
	{
		std::queue<std::shared_ptr<Node>> q;
		q.push( root_ );
		auto newNode = std::make_shared<Node>();
		newNode->keyValue = key;
		newNode->left = nullptr;
		newNode->right = nullptr;
		
		while ( !q.empty() ) {
			std::shared_ptr<Node> temp = q.front();
			q.pop();

			if ( !temp->left ) 
			{
				temp->left = newNode;				
				break;
			}
			else
				q.push( temp->left );

			if ( !temp->right ) {
				temp->right = newNode;
				break;
			}
			else
				q.push( temp->right );
		}
	}	
}

void BinaryTree::clear()
{
	root_ = std::make_shared<Node>();
	root_->keyValue = 0;
	root_->left = root_;
	root_->right = root_;
}

bool BinaryTree::search( std::shared_ptr<Node> node, const int key )
{
	if ( node == nullptr || (node->left == root_ && node->right == root_) )
		return false;
	
	if ( node->keyValue == key )
		return true;

	if ( node->keyValue < key )
		return search( node->right, key );

	return search( node->left, key );
}

int BinaryTree::depth( std::shared_ptr<Node> node )
{
	if ( node == nullptr )
		return 0;

	int leftDepth = depth( node->left );
	int rightDepth = depth( node->right );

	if ( leftDepth > rightDepth )
		return leftDepth + 1;
	else
		return rightDepth + 1;
}

void BinaryTree::drawNode( std::shared_ptr<Node> node, int x, int y, int offset, CDC * pDC )
{
	if ( node->right )
	{
		pDC->MoveTo( x + 27, y + 27 );
		pDC->LineTo( x + offset + 5, y + 55 );
		drawNode( node->right, x + offset, y + 50, int( offset * 0.5 ), pDC );
	}

	pDC->Ellipse( x, y, x + 32, y + 32 );
	CString key;
	key.Format( L"%d", node->keyValue );
	pDC->TextOutW( x + 8, y + 6, key );

	if ( node->left )
	{
		pDC->MoveTo( x + 5, y + 27 );
		pDC->LineTo( x - offset + 27, y + 55 );
		drawNode( node->left, x - offset, y + 50, int( offset * 0.5 ), pDC );
	}
}
