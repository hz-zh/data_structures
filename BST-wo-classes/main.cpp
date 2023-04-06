#include <iostream>
#include "BinaryNode.h"

bool isEmpty(BinaryNode<int>*);
void printTree(BinaryNode<int>*);
BinaryNode<int>* add(BinaryNode<int>* rt, int newEntry);

int main() {
	BinaryNode<int>* root = nullptr;
	// BinaryNode<int>* root = new BinaryNode<int>(12, new BinaryNode<int>(5), new BinaryNode<int>(15));
	
	root = add(root, 10);
	root = add(root, 15);
	root = add(root, 5);
	root = add(root, 20);


	printTree(root);
}

bool isEmpty(BinaryNode<int>* rt) {
	return rt == nullptr;

}

void printTree(BinaryNode<int>* rt) {
	if (!isEmpty(rt)) {
		printTree(rt->getLeftChildPtr());
		std::cout << rt->getValue() << " ";
		printTree(rt->getRightChildPtr());
	}
}

BinaryNode<int>* add(BinaryNode<int>* rt, int newEntry) {
	BinaryNode<int>* cur = rt;

	// if the tree is empty, create a new root node
	if (isEmpty(rt)) { 
		rt = new BinaryNode<int>(newEntry);
		return rt;
	}
	// if tree has nodes
	else {
		// if newEntry > curr->getValue
		if (newEntry > cur->getValue()) {
			if (cur->getRightChildPtr() == nullptr) {
				// rightChildPtr is vacant, add node here
				cur->setRightChildPtr(new BinaryNode<int>(newEntry));
			}
			// there is already a node at right
			else {
				add(cur->getRightChildPtr(), newEntry);
			}
		}
		else if (newEntry < cur->getValue()) {
			if (cur->getLeftChildPtr() == nullptr) {
				// leftChildPtr is vacant, add node here
				cur->setLeftChildPtr(new BinaryNode<int>(newEntry));
			}
			// there is already a node at left
			else {
				add(cur->getLeftChildPtr(), newEntry);
			}
		}
		return rt;
	}
}