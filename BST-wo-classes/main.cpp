#include <iostream>
#include "BinaryNode.h"

bool isEmpty(BinaryNode<int>*);
void printTree(BinaryNode<int>*);
BinaryNode<int>* add(BinaryNode<int>* rt, int newEntry);
bool BS_contains(BinaryNode<int>*, int);
bool ES_contains(BinaryNode<int>*, int);
void printLeaves(BinaryNode<int>*);
BinaryNode<int>* remove(BinaryNode<int>* cur, int removeValue);
void printOnlyChildren(BinaryNode<int>* rt);
int getTreeHeight(BinaryNode<int>* cur);

int main() {
	BinaryNode<int>* root = nullptr;
	// BinaryNode<int>* root = new BinaryNode<int>(12, new BinaryNode<int>(5), new BinaryNode<int>(15));
	
	root = add(root, 10);
	root = add(root, 15);
	root = add(root, 5);
	root = add(root, 20);
	root = add(root, 25);

	std::cout << getTreeHeight(root) << endl;

	//remove(root, 5);


	//std::cout << BS_contains(root, 10) << std::endl;
	//std::cout << ES_contains(root, 10) << std::endl;

	//printLeaves(root);
	printTree(root);
}

bool isEmpty(BinaryNode<int>* rt) {
	return rt == nullptr;

}

// In-order print
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

bool BS_contains(BinaryNode<int>* rt, int anEntry) {
	BinaryNode<int>* cur = rt;
	std::cout << "ES_contains finds: " << cur->getValue() << " ";
	if (!isEmpty(cur)) {
		if (cur->getValue() == anEntry) { return true; }
		else if (cur->getValue() > anEntry) {
			return BS_contains(cur->getLeftChildPtr(), anEntry);
		}
		else if (cur->getValue() < anEntry) {
			BS_contains(cur->getRightChildPtr(), anEntry);
		}
	}
	return false;
}

bool ES_contains(BinaryNode<int>* rt, int anEntry) {
	std::cout << "ES_contains finds: " << rt->getValue() << " "; 
	if (rt == nullptr) { return false;}
	if (rt->getValue() == anEntry) {
		return true;
	}
	return ES_contains(rt->getLeftChildPtr(), anEntry) || ES_contains(rt->getRightChildPtr(), anEntry);
}

void printLeaves(BinaryNode<int>* rt) {
	if (!isEmpty(rt)) {
		if (rt->getLeftChildPtr() == nullptr && rt->getRightChildPtr() == nullptr) {
			std::cout << rt->getValue() << std::endl;
		}
		printLeaves(rt->getLeftChildPtr());
		printLeaves(rt->getRightChildPtr());
	}
}

// FINISH THIS
void printOnlyChildren(BinaryNode<int>* rt) {
	if ((rt->getRightChildPtr() == nullptr && rt->getLeftChildPtr() != nullptr) || (rt->getRightChildPtr() == nullptr || rt->getLeftChildPtr() != nullptr)) {
		std::cout << rt->getValue() << endl;
	}
}

int getTreeHeight(BinaryNode<int>* cur) {
	if (cur != nullptr) {
		int left_height = getTreeHeight(cur->getLeftChildPtr());
		int right_height = getTreeHeight(cur->getRightChildPtr());

		if (left_height > right_height) {
			return left_height + 1;
		}
		else return right_height + 1;
	}
	else return 0;
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
		if (BS_contains(cur, removeValue)) {
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
			else {
				std::cout << "\nRemoving " << cur->getValue() << "...\n";
				// if cur has right child only or no child
				if (cur->getLeftChildPtr() == nullptr) {
					// hold right ptr
					BinaryNode<int>* temp = cur->getRightChildPtr();
					delete(cur);
					return temp;
				}
				// if cur has left child only or no child
				else if (cur->getRightChildPtr() == nullptr) {
					// hold left ptr
					BinaryNode<int>* temp = cur->getLeftChildPtr();
					delete(cur);
					return temp;
				}
				BinaryNode<int>* temp2 = getInOrderSuccessor(cur->getRightChildPtr());
				cur->setValue(temp2->getValue());
				cur->setRightChildPtr(remove(cur->getRightChildPtr(), temp2->getValue()));
			}
		}
	}
}