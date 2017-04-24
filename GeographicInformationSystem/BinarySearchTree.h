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
	void deleteByName(string name) const;
	void deleteByCoord(pair<double, double> coords) const;
	bool searchByName(string name) const;
	bool searchByCoords(pair<double, double> coords) const;
	int height() const;
	void showInOrder() const;
	void showPreOrder() const;
	void showPostOrder() const;
	void prettyPrint() const;
	void nearByCities(pair<double, double> coords, double distance) const;

private:
	static void deleteTree(TreeNode *& node); // used by destructor
	void insert(City city, TreeNode *& node) const;
	TreeNode* deleteByName(TreeNode *node, string name) const;
	TreeNode* deleteByCoord(TreeNode *node, pair<double, double> coords) const;
	bool searchByName(TreeNode *node, string name) const;
	bool searchByCoords(TreeNode *node, pair<double, double> coords) const;
	int height(TreeNode *node) const;
	void showInOrder(TreeNode *node) const;
	void showPreOrder(TreeNode *node) const;
	void showPostOrder(TreeNode *node) const;
	void prettyPrint(TreeNode * node, int indent) const;
	static TreeNode* minVal(TreeNode *node);
	void nearByCities(TreeNode * node, pair<double, double> coords, double distance) const;
	static double deg2rad(double deg);
	static double rad2deg(double rad);
	double distanceEarth(pair<double, double> location1, pair<double, double> location2) const;
	TreeNode *root;
};


#endif // BINARYSEARCHTREE_H_
