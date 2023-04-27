#include <iostream>
#include "BinaryNode.h"

void printPreorder(BinaryNode<int>*);
BinaryNode<int>* create_LL_imbalance(BinaryNode<int>*);
BinaryNode<int>* LLRotate(BinaryNode<int>*);
BinaryNode<int>* create_RR_imbalance(BinaryNode<int>*);
BinaryNode<int>* RRRotate(BinaryNode<int>* rt);
BinaryNode<int>* create_RL_imbalance(BinaryNode<int>*);
BinaryNode<int>* RLRotate(BinaryNode<int>* rt);
BinaryNode<int>* create_LR_imbalance(BinaryNode<int>*);
BinaryNode<int>* LRRotate(BinaryNode<int>* rt);


int main() {
	BinaryNode<int>* root = nullptr;

	/*
	root = create_LL_imbalance(root);
	std::cout << "\nPreorder: ";
	printPreorder(root);
	root = LLRotate(root);
	std::cout << "\nPost LL Rotate: Preorder: ";
	printPreorder(root);

	root = nullptr;

	root = create_RR_imbalance(root);
	std::cout << "\nPreorder: ";
	printPreorder(root);
	root = RRRotate(root);
	std::cout << "\nPost RR Rotate: Preorder: ";
	printPreorder(root);
	*/
	root = nullptr;

	root = create_LR_imbalance(root);
	std::cout << "\nPreorder: ";
	printPreorder(root);
	root = LRRotate(root);
	std::cout << "\nPost LR Rotate: Preorder: ";
	printPreorder(root);

	root = nullptr;

	root = create_RL_imbalance(root);
	std::cout << "\nPreorder: ";
	printPreorder(root);
	root = RLRotate(root);
	std::cout << "\nPost RL Rotate: Preorder: ";
	printPreorder(root);

	return 0;
}

void printPreorder(BinaryNode<int>* cur) {
	if (cur != nullptr) {
		std::cout << cur->getValue() << " ";
		if (cur->getLeftChildPtr() != nullptr) std::cout << "<--- ";
		printPreorder(cur->getLeftChildPtr());
		if (cur->getRightChildPtr() != nullptr) std::cout << "---> ";
		printPreorder(cur->getRightChildPtr());
	}
}

BinaryNode<int>* create_LL_imbalance(BinaryNode<int>*) {
	return new BinaryNode<int>(30, new BinaryNode<int>(20, new BinaryNode<int>(10), nullptr), nullptr);
}
/*
				30  <--- temp1
				/\
	 temp2--> 20  any size tree
			  /\
			 10 any size tree
			 /\
		 NULL  NULL
*/

BinaryNode<int>* create_RR_imbalance(BinaryNode<int>*) {
	return new BinaryNode<int>(10, nullptr, new BinaryNode<int>(20, nullptr, new BinaryNode<int>(30)));
}
/*
				10   <-- temp1
				/\
   any size tree  20 <-- temp2
			 	  /\ 
	 any size tree	30
					/\
				NULL  NULL	 
*/

BinaryNode<int>* create_RL_imbalance(BinaryNode<int>*) {
	return new BinaryNode<int>(10, nullptr, new BinaryNode<int>(30, new BinaryNode<int>(20), nullptr));
}

BinaryNode<int>* create_LR_imbalance(BinaryNode<int>*) {
	return new BinaryNode<int>(30, new BinaryNode<int>(10, nullptr, new BinaryNode<int>(20)), nullptr);
}



BinaryNode<int>* LLRotate(BinaryNode<int>* rt) {
	BinaryNode<int>* temp1 = rt; // hold ptr to root
	BinaryNode<int>* temp2 = rt->getLeftChildPtr(); // hold ptr to node, left of root

	// set right subtree of temp2 to the left of temp1
	// left of temp1 is not lost, it is stored in temp2
	temp1->setLeftChildPtr(temp2->getRightChildPtr());

	// put temp1 to the right of temp2
	temp2->setRightChildPtr(temp1);

	// return the new root to main
	return temp2; 
}

BinaryNode<int>* RRRotate(BinaryNode<int>* rt) {
	BinaryNode<int>* temp1 = rt; // hold ptr to root
	BinaryNode<int>* temp2 = rt->getRightChildPtr(); // hold ptr to node, left of root

	// set left subtree of temp2 to the right of temp1
	// right of temp1 is not lost, it is stored in temp2
	temp1->setRightChildPtr(temp2->getLeftChildPtr());

	// put temp1 to the left of temp2
	temp2->setLeftChildPtr(temp1);

	// return the new root to main
	return temp2;
}

BinaryNode<int>* LRRotate(BinaryNode<int>* rt) {
	BinaryNode<int>* temp1 = rt; // hold ptr to root
	BinaryNode<int>* temp2 = rt->getLeftChildPtr(); // hold ptr to node, left of root
	BinaryNode<int>* temp3 = temp2->getRightChildPtr();

	temp1->setLeftChildPtr(temp3->getRightChildPtr());
	temp2->setRightChildPtr(temp3->getLeftChildPtr());
	temp3->setLeftChildPtr(temp2);
	temp3->setRightChildPtr(temp1);

	return temp3;
}

BinaryNode<int>* RLRotate(BinaryNode<int>* rt) {
	BinaryNode<int>* temp1 = rt; // hold ptr to root
	BinaryNode<int>* temp2 = rt->getRightChildPtr(); // hold ptr to node, left of root
	BinaryNode<int>* temp3 = temp2->getLeftChildPtr();

	temp1->setRightChildPtr(temp3->getLeftChildPtr());
	temp2->setLeftChildPtr(temp3->getRightChildPtr());
	temp3->setRightChildPtr(temp2);
	temp3->setLeftChildPtr(temp1);

	return temp3;
}


