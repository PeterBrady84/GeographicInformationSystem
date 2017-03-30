//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#ifndef TREENODE_H_
#define TREENODE_H_
#include "City.h"

class TreeNode {
public:
	TreeNode();
	TreeNode(City city, TreeNode *left, TreeNode *right);
	bool isLeaf() const;
	friend class BinarySearchTree;
private:
	City city;
	TreeNode *leftPtr;
	TreeNode *rightPtr;
};

#endif // TREENODE_H_
