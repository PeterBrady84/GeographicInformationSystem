//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#include "TreeNode.h"

// default constructor for treenode
TreeNode::TreeNode()
	: city(), leftPtr(nullptr), rightPtr(nullptr) {}

// overloaded constructor for treenode
TreeNode::TreeNode(City city, TreeNode *left, TreeNode *right)
	: city(city), leftPtr(left), rightPtr(right) {}

// is leaf method for treenode, i.e is it the last in its path
bool TreeNode::isLeaf() const {
	if (leftPtr == nullptr && rightPtr == nullptr)
		return true;
	else
		return false;
}