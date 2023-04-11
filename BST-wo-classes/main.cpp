#include <iostream>
#include "BinaryNode.h"

bool isEmpty(BinaryNode<int>*);
void printTree(BinaryNode<int>*);
BinaryNode<int>* add(BinaryNode<int>* rt, int newEntry);
bool contains(BinaryNode<int>*, int);
void printLeaves(BinaryNode<int>*);

int main() {
	BinaryNode<int>* root = nullptr;
	// BinaryNode<int>* root = new BinaryNode<int>(12, new BinaryNode<int>(5), new BinaryNode<int>(15));
	
	root = add(root, 10);
	root = add(root, 15);
	root = add(root, 5);
	root = add(root, 20);

	std::cout << contains(root, 10) << std::endl;

	printLeaves(root);
	//printTree(root);
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

bool contains(BinaryNode<int>* rt, int anEntry) {
	BinaryNode<int>* cur = rt;
	if (!isEmpty(cur)) {
		if (cur->getValue() == anEntry) { return true; }
		contains(cur->getLeftChildPtr(), anEntry);
		contains(cur->getRightChildPtr(), anEntry);
		return false;
	}
	else return false;
}

void printLeaves(BinaryNode<int>* rt) {
	/*if (!isEmpty(rt)) {
		if (rt->getLeftChildPtr() == nullptr && rt->getRightChildPtr() == nullptr) {
			std::cout << rt->getValue() << std::endl;
		}
		printLeaves(rt->getLeftChildPtr());
		printLeaves(rt->getRightChildPtr());
	}*/
	if (!isEmpty(rt)) {
		if (rt->getRightChildPtr() != nullptr) {
			if (rt->getLeftChildPtr() == nullptr && rt->getRightChildPtr() == nullptr) {
				std::cout << " Right side leaf: " << rt->getValue() << std::endl;
			}
			printLeaves(rt->getRightChildPtr());
		}
		else if (rt->getLeftChildPtr() != nullptr) {
			if (rt->getLeftChildPtr() == nullptr && rt->getRightChildPtr() == nullptr) {
				std::cout << " Left side leaf: " << rt->getValue() << std::endl;
			}
			printLeaves(rt->getLeftChildPtr());
		}
		else {
			printLeaves(rt->getLeftChildPtr());
			printLeaves(rt->getRightChildPtr());
		}
	}
}

BinaryNode<int>* getInOrderSuccessor(BinaryNode<int>* cur) {
	std::cout << "Inside getInOrderSuccessor() starting -->" << cur->getValue() << std::endl;
	while (cur->getLeftChildPtr() != nullptr) {
		std::cout << cur->getValue() << " ";
		cur = cur->getLeftChildPtr();
	}
	std::cout << std::endl << "successor: " << cur->getValue() << endl;
	return cur;
}

BinaryNode<int>* remove(BinaryNode<int>* cur, int removeValue) {
	std::cout << "\nAt: " << cur->getValue() << " ";
	//BinaryNode<int>* cur = root REMOVED
	if (!isEmpty(cur)) {
		if (contains(cur, removeValue)) {
			// start recursive calls
			// if removeValue < cur 
			if (removeValue < cur->getValue()) {
				std::cout << "\n" << removeValue << " is less than " << cur->getValue() << std::endl;
				cur->setLeftChildPtr(remove(cur->getLeftChildPtr(), removeValue));
			}
			// if removeValue > cur 
			else if (removeValue > cur->getValue()) {
				std::cout << "\n" << removeValue << " is greater than " << cur->getValue() << endl;
				cur->setRightChildPtr(remove(cur->getRightChildPtr(), removeValue));
			}
		}
	}
}