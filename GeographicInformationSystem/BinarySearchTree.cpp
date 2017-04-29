//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#define _USE_MATH_DEFINES
#define earthRadiusKm 6371.0
#include "BinarySearchTree.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

// default constructor for binary search tree
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// destructor for binary search tree
BinarySearchTree::~BinarySearchTree() {
	deleteTree(root);
}

// private recursive delete Tree method used by destructor
void BinarySearchTree::deleteTree(TreeNode*& node) {
	if (node != nullptr) {
		deleteTree(node->leftPtr);
		deleteTree(node->rightPtr);
		delete node;
		node = nullptr;
	}
}

// public insert city method
void BinarySearchTree::insert(City city) {
	insert(city, root);
}

/***************************************************************************************

*    Usage: Modified
*    Title: Absolute C++, 6th Edition
*    Author: Savitch, J
*    Date: 2016
*    ISBN-13: 978-0133970784
*
***************************************************************************************/

// private insert city method
void BinarySearchTree::insert(City city, TreeNode*& node) const {
	// check that gps coordinates are not already in the tree
	if (!searchByCoords(city.gpsCoordinates)) {
		if (node == nullptr) {
			node = new TreeNode(city, nullptr, nullptr);
		}
		else {
			if (city.name.compare(node->city.name) < 0) {
				insert(city, node->leftPtr);
			}
			else {
				insert(city, node->rightPtr);
			}
		}
	}
	else {
		cout << "Error : A city already exists for the coordinates : " <<
			city.gpsCoordinates.first << " " << city.gpsCoordinates.second << endl;
	}
}

// public delete by name method
void BinarySearchTree::deleteByName(string name) {
	deleteByName(root, name);
}

// private recursive delete by name methods
TreeNode* BinarySearchTree::deleteByName(TreeNode *& node, string name) const {
	if (node == nullptr) {
		return node;
	}
	if (name < node->city.name) {
		node->leftPtr = deleteByName(node->leftPtr, name);
	}
	else if (name > node->city.name) {
		node->rightPtr = deleteByName(node->rightPtr, name);
	}
	else {
		if (node->isLeaf()) {
			delete node;
			node = nullptr;
		}
		else if (node->leftPtr == nullptr) {
			TreeNode* temp = node;
			node = node->rightPtr;
			delete temp;
		}
		else if (node->rightPtr == nullptr) {
			TreeNode* temp = node;
			node = node->leftPtr;
			delete temp;
		}
		else {
			TreeNode* temp = minVal(node->rightPtr);
			node->city = temp->city;
			node->rightPtr = deleteByName(node->rightPtr, temp->city.name);
		}
	}
	return node;
}

// public delete by coordinates method
void BinarySearchTree::deleteByCoord(pair<double, double> coords) {
	deleteByCoord(root, coords);
}

// private recursive delete by coordinates methods
TreeNode* BinarySearchTree::deleteByCoord(TreeNode *& node, pair<double, double> coords) const {
	if (node != nullptr) {
		if (node->city.gpsCoordinates.first == coords.first && node->city.gpsCoordinates.second == coords.second)
		{
			if (node->isLeaf()) {
				delete node;
				node = nullptr;
			}
			else if (node->leftPtr == nullptr) {
				TreeNode* temp = node;
				node = node->rightPtr;
				delete temp;
			}
			else if (node->rightPtr == nullptr) {
				TreeNode* temp = node;
				node = node->leftPtr;
				delete temp;
			}
			else {
				TreeNode* temp = minVal(node->rightPtr);
				node->city = temp->city;
				node->rightPtr = deleteByCoord(node->rightPtr, temp->city.gpsCoordinates);
			}
		}
		else {
			node->leftPtr = deleteByCoord(node->leftPtr, coords);
			node->rightPtr = deleteByCoord(node->rightPtr, coords);
		}
	}
	return node;
}

// public search by name method
bool BinarySearchTree::searchByName(string name) const {
	if (searchByName(root, name)) {
		return true;
	}
	else {
		cout << "City name '" << name << "' not found!" << endl << endl;
		return false;
	}
}

// private recursive search by name methods
bool BinarySearchTree::searchByName(TreeNode* node, string name) const {
	if (node == nullptr) {
		return false;
	}
	else if (node->city.name == name) {
		cout << node->city << endl;
		return true;
	}
	else if (node->city.name > name) {
		if (node->leftPtr == nullptr) {
			return false;
		}
		else {
			return searchByName(node->leftPtr, name);
		}
	}
	else if (node->city.name < name) {
		if (node->rightPtr == nullptr) {
			return false;
		}
		else {
			return searchByName(node->rightPtr, name);
		}
	}
	else {
		return false;
	}
}

// public search by coordinates method
bool BinarySearchTree::searchByCoords(pair<double, double> coords) const {
	return searchByCoords(root, coords);
}

// private recursive search by coordinates method
bool BinarySearchTree::searchByCoords(TreeNode* node, pair<double, double> coords) const {
	if (node == nullptr) {
		return false;
	}
	else if (node->city.gpsCoordinates.first == coords.first && node->city.gpsCoordinates.second == coords.second) {
		cout << node->city << endl;
		return true;
	}
	else {
		return searchByCoords(node->leftPtr, coords) || searchByCoords(node->rightPtr, coords);
	}
}

// private minimum value method
TreeNode* BinarySearchTree::minVal(TreeNode* node) {
	if (node == nullptr)
		return nullptr;
	if (node->leftPtr)
		return minVal(node->leftPtr);
	return node;
}

// public height method
int BinarySearchTree::height() const {
	return height(root);
}

/***************************************************************************************

*    Usage: Used
*    Title: Total Height of a Binary Search Tree
*    Author: Pippin1289
*    Date: 2013
*    Available: http://stackoverflow.com/a/19321003/3633676
*
***************************************************************************************/

// private recursive height method
int BinarySearchTree::height(TreeNode *node) const {
	// when node is null return -1
	if (node == nullptr)
		return -1;
	// recursively call height method
	else
		// for every level of nodes return 1
		return 1 + max(height(node->leftPtr), height(node->rightPtr));
}

/***************************************************************************************

*    Usage: Modified
*    Title: Tree Traversals (Inorder, Preorder and Postorder)
*    Author: Geeks For Geeks
*    Date: Unknown
*    Available: http://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
*
***************************************************************************************/

// public showInOrder method
void BinarySearchTree::showInOrder() const {
	return showInOrder(root);
}

// private recursive shoInOrder method
void BinarySearchTree::showInOrder(TreeNode *node) const {
	if (node != nullptr) {
		showInOrder(node->leftPtr);
		cout << node->city.name << ", ";
		showInOrder(node->rightPtr);
	}
}

// public showPostOrder method
void BinarySearchTree::showPostOrder() const {
	return showPostOrder(root);
}

// private recursive showPostOrder method
void BinarySearchTree::showPostOrder(TreeNode *node) const {
	if (node != nullptr) {
		// first recur on left subtree
		showPostOrder(node->leftPtr);
		// then recur on right subtree
		showPostOrder(node->rightPtr);
		// now deal with the node
		cout << node->city.name << ", ";
	}
}

// public showPreOrder method
void BinarySearchTree::showPreOrder() const {
	return showPreOrder(root);
}

// private recursive showPreOrder method
void BinarySearchTree::showPreOrder(TreeNode *node) const {
	if (node != nullptr) {
		/* first print data of node */
		cout << node->city.name << ", ";
		/* then recur on left sutree */
		showPreOrder(node->leftPtr);
		/* now recur on right subtree */
		showPreOrder(node->rightPtr);
	}
}

// public nearByCities method
void BinarySearchTree::nearByCities(pair<double, double> coords, double distance) const {
	nearByCities(root, coords, distance);
}

// private nearByCities method
void BinarySearchTree::nearByCities(TreeNode * node, pair<double, double> coords, double distance) const {
	if (node != nullptr) {
		if (distanceEarth(coords, node->city.gpsCoordinates) < distance) {
			cout << node->city << "Distance : " << distanceEarth(coords, node->city.gpsCoordinates)
				<< " Km" << endl << endl;
		}
		nearByCities(node->leftPtr, coords, distance);
		nearByCities(node->rightPtr, coords, distance);
	}
}

/***************************************************************************************

*    Usage: Used
*    Title: Calculating the distance between 2 latitudes and longitudes that are saved in a text file
*    Author: MrTJ
*    Date: 2012
*    Available: http://stackoverflow.com/a/10205532
*
***************************************************************************************/

// This function converts decimal degrees to radians
double BinarySearchTree::deg2rad(double deg) {
	return (deg * M_PI / 180);
}

//  This function converts radians to decimal degrees
double BinarySearchTree::rad2deg(double rad) {
	return (rad * 180 / M_PI);
}

// public calculate distances between two points method
double BinarySearchTree::distanceEarth(pair<double, double> location1, pair<double, double> location2) const {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(location1.first);
	lon1r = deg2rad(location1.second);
	lat2r = deg2rad(location2.first);
	lon2r = deg2rad(location2.second);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

// public pretty print method
void BinarySearchTree::prettyPrint() const {
	prettyPrint(root, 0);
}

/***************************************************************************************

*    Usage: Modified
*    Title: Print a Binary Tree in a pretty way
*    Author: Vaultah
*    Date: 2015
*    Available: http://stackoverflow.com/a/26699993
*
***************************************************************************************/

// private recursive pretty print method
void BinarySearchTree::prettyPrint(TreeNode *node, int indent) const {
	if (node != nullptr) {
		if (node->rightPtr) {
			prettyPrint(node->rightPtr, indent + 7);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (node->rightPtr) {
			cout << "    /\n" << setw(indent) << ' ';
		}
		cout << node->city.name << "\n ";
		if (node->leftPtr) {
			cout << setw(indent + 3) << ' ' << " \\\n";
			prettyPrint(node->leftPtr, indent + 7);
		}
	}
}
