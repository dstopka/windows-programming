#include "stdafx.h"
#include "RobsonAlgorithm.h"

#include <iostream>

RobsonTraversal::RobsonTraversal( std::shared_ptr<Node> root )
{
	root_ = root;
	previous_ = present_ = root;
	top_ = stack_ = nullptr;
}

RobsonTraversal::~RobsonTraversal()
{
}


std::string RobsonTraversal::inVisit()
{
	visitType_ = visitType::inOrder;
	std::string result = "";
	start( result );
	return result;
}

std::string RobsonTraversal::postVisit()
{
	visitType_ = visitType::postOrder;
	std::string result = "";
	start( result );
	return result;
}

std::string RobsonTraversal::preVisit()
{
	visitType_ = visitType::preOrder;
	std::string result = "";
	start(result);
	return result;
}

void RobsonTraversal::start(std::string& res)
{
	auto move_value = 0;
	while ( true )
	{
		if ( move_value == 0 )
		{
			if ( (present_->left == nullptr) && (present_->right == nullptr) )
			{
				res += std::to_string( present_->keyValue );
				res += " -> ";
				avail_ = present_;
			}
			else
			{
				if ( present_->left != nullptr )
				{
					if ( visitType_ == visitType::preOrder )
					{
						res += std::to_string( present_->keyValue );
						res += " -> ";
					}
					next_ = present_->left;
					present_->left = previous_;
					previous_ = present_;
					present_ = next_;
					continue;
				}
				if ( visitType_ == visitType::preOrder )
				{
					res += std::to_string( present_->keyValue );
					res += " -> ";
				}
				else if ( visitType_ == visitType::inOrder )
				{
					res += std::to_string( present_->keyValue );
					res += " -> ";
				}
				next_ = present_->right;
				present_->right = previous_;
				previous_ = present_;
				present_ = next_;
				continue;
			}
		}
		move_value = 0;
		if ( present_ == root_ )
		{
			return;
		}
		if ( previous_->right == nullptr )
		{
			if ( visitType_ == visitType::inOrder )
			{
				res += std::to_string( present_->keyValue );
				res += " -> ";
			}
			else if ( visitType_ == visitType::postOrder )
			{
				res += std::to_string( present_->keyValue );
				res += " -> ";
			}
			next_ = previous_->left;
			previous_->left = present_;
			present_ = previous_;
			previous_ = next_;
			move_value = 1;
			continue;
		}
		if ( previous_->left == nullptr )
		{
			if ( visitType_ == visitType::postOrder )
			{
				res += std::to_string( present_->keyValue );
				res += " -> ";
			}
			next_ = previous_->right;
			previous_->right = present_;
			present_ = previous_;
			previous_ = next_;
			move_value = 1;
			continue;
		}
		if ( previous_ == top_ )
		{
			if ( visitType_ == visitType::postOrder )
			{
				res += std::to_string( present_->keyValue );
				res += " -> ";
			}
			next_ = stack_;
			top_ = stack_->right;
			stack_ = stack_->left;
			next_->left = next_->right = nullptr;
			next_ = previous_->left;
			previous_->left = previous_->right;
			previous_->right = present_;
			present_ = previous_;
			previous_ = next_;
			move_value = 1;
			continue;
		}

		if ( visitType_ == visitType::inOrder )
		{
			res += std::to_string( present_->keyValue );
			res += " -> ";
		}
		avail_->left = stack_;
		avail_->right = top_;
		stack_ = avail_;
		top_ = previous_;
		next_ = previous_->right;
		previous_->right = present_;
		present_ = next_;
	}
}
