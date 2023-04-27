#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
// include library for nullptr
#include <cstddef>
#include "BinaryNode.h"

// class implementation
class BinaryTree {
	BinaryNode<int>* root;
	bool _add(BinaryNode<int>*, int);
	bool _contains(BinaryNode<int>*, int);
	bool _remove(BinaryNode<int>*, int);
	bool _isLeaf(BinaryNode<int>*);
	BinaryNode<int>* _hasOneLeaf(BinaryNode<int>*);
public:
	BinaryTree() : root(nullptr) {}
	BinaryTree(int newEntry) : root(new BinaryNode<int>(newEntry)) {}

	BinaryNode<int>* getRoot() const;
	bool isEmpty(BinaryNode<int>*); // can be any root, not just base root
	bool add(int);
	void printTree(BinaryNode<int>*); // can be any root 
	bool contains(int); // cannot be any root; assuming client does not know where the node lies
	bool remove(int); // cannot be any root; assuming client does not know where the node lies
};
// end class declaration

BinaryNode<int>* BinaryTree::getRoot() const {
	return root;
}

bool BinaryTree::isEmpty(BinaryNode<int>* rt) {
	return rt == nullptr;
}

bool BinaryTree::add(int newEntry) {
	return _add(root, newEntry);
}

bool BinaryTree::contains(int entry) {
	return _contains(root, entry);
}

bool BinaryTree::remove(int entry) {
	return _remove(root, entry);
}

bool BinaryTree::_isLeaf(BinaryNode<int>* rt) {
	return (rt->getLeftChildPtr() == nullptr && rt->getRightChildPtr() == nullptr);
}

BinaryNode<int>* BinaryTree::_hasOneLeaf(BinaryNode<int>* rt) {
	if (rt->getLeftChildPtr() == nullptr && rt->getRightChildPtr() != nullptr) {
		return rt->getRightChildPtr();
	}
	else if (rt->getLeftChildPtr() != nullptr && rt->getRightChildPtr() == nullptr) {
		return rt->getLeftChildPtr();
	}
	else return nullptr;
}

bool BinaryTree::_contains(BinaryNode<int>* rt, int entry) {
	/* cases:
		if the tree is empty, return false
		if entry is equal to rt return true
		if entry is < rt, recurse to left (rt->getLeftChildPtr)
		else entry is > rt, recurse to right (rt->getRightChildPtr)
	*/
	while (rt != nullptr) {
		std::cout << "Entering _contains" << std::endl;
	
		if (rt->getValue() == entry) {
			std::cout << "Tree contains " << rt->getValue() << std::endl;
			return true;
		}
		if (rt->getValue() > entry) {
			std::cout << "looping to left\n"; 
			rt = rt->getLeftChildPtr();
			}
		else if (rt->getValue() < entry) {
			std::cout << "looping to right\n"; 
			rt = rt->getRightChildPtr();
			}
	}
	std::cout << "Tree does not contain " << entry << std::endl; 
	return false;
}

bool BinaryTree::_remove(BinaryNode<int>* rt, int entry) {
	/* cases:
			if the tree is empty, return false
			if entry is equal to rt, call remove sequence
			if entry is < rt, recurse to left (rt->getLeftChildPtr)
			elif entry is > rt, recurse to right (rt->getRightChildPtr)

	remove sequence:
		case 1:
			node is a leaf. Set node to nullptr
		case 2:
			node has one child. Delete node and assign parent->next(left or right) to child
		case 3:
			node has two children. Find node's inorder successor; copy that value to node; delete successor (and assign parent->next() to child)
	*/
	if (isEmpty(rt)) return false;
	if (rt->getLeftChildPtr()->getValue() == entry) {
		if (_isLeaf(rt->getLeftChildPtr())) rt->setLeftChildPtr(nullptr);
		else if (_hasOneLeaf(rt->getLeftChildPtr()) != nullptr) {
			
		}
	}
}


bool BinaryTree::_add(BinaryNode<int>* rt, int newEntry) {
	// cases:
	//		if the tree is empty add as root
	//		elif the value is less than rt and there is no left node, put at left
	//			else there is a left node: rt = rt->getLeftChildPtr()
	//		else the value is greater than rt and there is no right node, put at right
	//			else there is a right node: rt = rt->getRightChildPtr()
	std::cout << "Entering _add" << std::endl;
	if (root == nullptr) {
		root = new BinaryNode<int>(newEntry);
		return true;
	}
	
	if (newEntry < rt->getValue()) {
		if (isEmpty(rt->getLeftChildPtr())) {
			rt->setLeftChildPtr(new BinaryNode<int>(newEntry));
		}
		else {
			_add(rt->getLeftChildPtr(), newEntry);
		}
	}
	else {
		if (isEmpty(rt->getRightChildPtr())) {
			rt->setRightChildPtr(new BinaryNode<int>(newEntry));
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