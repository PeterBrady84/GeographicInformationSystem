//
//  Created by Peter Brady on 13/03/2017
//  Copyright (c) 2017 Peter Brady.
//  X00115070
//
#include "BinarySearchTree.h"
#include <iostream>
#include <iomanip>
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

// private insert city method
void BinarySearchTree::insert(City city, TreeNode*& node) {
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
TreeNode* BinarySearchTree::deleteByName(TreeNode* node, string name) {
	if (node != nullptr) {
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
				node->city.name = temp->city.name;
				node->rightPtr = deleteByName(node->rightPtr, temp->city.name);
			}
		}
	}
	return node;
}

// public delete by coordinates method
void BinarySearchTree::deleteByCoord(pair<string, string> coords) {
	deleteByCoord(root, coords);
}

// private recursive delete by coordinates methods
TreeNode* BinarySearchTree::deleteByCoord(TreeNode* node, pair<string, string> coords) {
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
				node->city.name = temp->city.name;
				node->rightPtr = deleteByName(node->rightPtr, temp->city.name);
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
	return searchByName(root, name);
}

// private recursive search by name methods
bool BinarySearchTree::searchByName(TreeNode* node, string name) const {
	if (node == nullptr) {
		return false;
	}
	else if (node->city.name == name) {
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
bool BinarySearchTree::searchByCoords(pair<string, string> coords) const {
	return searchByCoords(root, coords);
}

// private recursive search by coordinates method
bool BinarySearchTree::searchByCoords(TreeNode* node, pair<string, string> coords) const {
	if (node == nullptr) {
		return false;
	}
	else if (node->city.gpsCoordinates.first == coords.first && node->city.gpsCoordinates.second == coords.second) {
		return true;
	}
	else {
		return searchByCoords(node->leftPtr, coords) || searchByCoords(node->rightPtr, coords);
	}
}

// private minimum value method
TreeNode* BinarySearchTree::minVal(TreeNode* node) {
	if (node == nullptr)
		return 0;
	if (node->leftPtr)
		return minVal(node->leftPtr);
	return node;
}













int BinarySearchTree::height() const
{
	return 0;
}

int BinarySearchTree::height(TreeNode* node) const
{
	return 0;
}

// public show binary search tree in order
void BinarySearchTree::showInOrder() const {
	return showInOrder(root);
}

// private recursive show binary search tree in order
void BinarySearchTree::showInOrder(TreeNode* node) const {
	if (node != nullptr) {
		showInOrder(node->leftPtr);
		cout << node->city.name << " ";
		showInOrder(node->rightPtr);
	}
}

void BinarySearchTree::showPreOrder() const
{
}

void BinarySearchTree::showPreOrder(TreeNode* node) const
{
}

void BinarySearchTree::showPostOrder() const
{
}

void BinarySearchTree::showPostOrder(TreeNode* node) const
{
}

// public pretty print method
void BinarySearchTree::prettyPrint() const {
	prettyPrint(root, 5);
}

// http://stackoverflow.com/a/26699993
// private recursive pretty print method
void BinarySearchTree::prettyPrint(TreeNode *node, int indent) const {
	if (node != nullptr) {
		if (node->rightPtr) {
			prettyPrint(node->rightPtr, indent + 6);
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
			prettyPrint(node->leftPtr, indent + 6);
		}
	}
}
