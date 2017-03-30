//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include "City.h"
#include "TreeNode.h"

class BinarySearchTree {
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void insert(City city);
	void deleteByName(string name);
	void deleteByCoord(pair<string, string> coords);
	bool searchByName(string name) const;
	bool searchByCoords(pair<string, string> coords) const;
	int height() const;
	void showInOrder() const;
	void showPreOrder() const;
	void showPostOrder() const;
	void prettyPrint();
	void postOrder(TreeNode * node, int indent);
	// TODO add cities within certain distance method
private:
	void deleteTree(TreeNode *& node); // used by destructor
	void insert(City city, TreeNode *& node);
	TreeNode* deleteByName(TreeNode *node, string name);
	TreeNode* deleteByCoord(TreeNode *node, pair<string, string> coords);
	bool searchByName(TreeNode *node, string name) const;
	bool searchByCoords(TreeNode *node, pair<string, string> coords) const;
	int height(TreeNode *node) const;
	void showInOrder(TreeNode *node) const;
	void showPreOrder(TreeNode *node) const;
	void showPostOrder(TreeNode *node) const;
	TreeNode* minVal(TreeNode *node);
	// TODO add cities within certain distance recursive method
	TreeNode *root;
};


#endif // BINARYSEARCHTREE_H_
