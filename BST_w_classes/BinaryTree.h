#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
// include library for nullptr
#include <cstddef>
#include "BinaryNode.h"

class BinaryTree {
	BinaryNode<int>* root;
	bool _add(BinaryNode<int>*, int);
public:
	BinaryTree() : root(nullptr) {}
	BinaryTree(int newEntry) : root(new BinaryNode<int>(newEntry)) {}

	BinaryNode<int>* getRoot() const;
	bool isEmpty(BinaryNode<int>*); // can be any root, not just base root
	bool add(int);
	void printTree(BinaryNode<int>*);
};

// class implementation
BinaryNode<int>* BinaryTree::getRoot() const {
	return root;
}

bool BinaryTree::isEmpty(BinaryNode<int>* rt) {
	return rt == nullptr;
}

bool BinaryTree::add(int newEntry) {
	//if (root != nullptr) 
	return _add(root, newEntry);
	//else return false;
}


bool BinaryTree::_add(BinaryNode<int>* rt, int newEntry) {
	// stop cases:
	//		if the tree is empty add as root
	//		elif the value is less than cur and there is no left node, put at left
	//			else there is a left node: cur = cur->getLeftChildPtr()
	//		else the value is greater than cur and there is no right node, put at right
	//			else there is a right node: cur = cur->getRightChildPtr()
	std::cout << "entering _add" << std::endl;
	if (root == nullptr) {
		std::cout << "root == nullptr" << std::endl;
		root = new BinaryNode<int>(newEntry);
		return true;
	}
	
	if (newEntry < rt->getValue()) {
		if (isEmpty(rt->getLeftChildPtr())) {
			rt->setLeftChildPtr(new BinaryNode<int>(newEntry));
			//return true;
		}
		else {
			_add(rt->getLeftChildPtr(), newEntry);
		}
	}
	else {
		if (isEmpty(rt->getRightChildPtr())) {
			rt->setRightChildPtr(new BinaryNode<int>(newEntry));
			//return true;
		}
		else {
			_add(rt->getRightChildPtr(), newEntry);
		}
	}
	return true;
}

void BinaryTree::printTree(BinaryNode<int>* cur) {
	if (cur != nullptr) {
		printTree(cur->getLeftChildPtr());
		std::cout << cur->getValue() << " ";
		printTree(cur->getRightChildPtr());
	}
}

#endif