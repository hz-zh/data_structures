//definitions of the implemented class
#include <iostream>
#include "LLStack.h"
#include "Node.h"

template <class ItemType>
LLStack<ItemType>::LLStack() {
	std::cout << "New stack created...\n";
	root = nullptr;				//init the root ptr		
}

template <class ItemType>
bool LLStack<ItemType>::isEmpty() const {
	return root == nullptr;
}

template <class ItemType>
bool LLStack<ItemType>::push(const ItemType& newEntry) {
	//when LL is not empty
	//when LL is empty
	if (!isEmpty()) {
		Node<ItemType>* temp = new Node<ItemType>(newEntry, root);
		root = temp;
		return true;
	}
	else {
		root = new Node<ItemType>(newEntry);
		return true;
	}
	return false;
}

template <class ItemType>
bool LLStack<ItemType>::pop() {
	if (!isEmpty()) {
		if (root->getNextNode() != nullptr) {
			root = root->getNextNode();
			return true;
		}
		else {
			root = nullptr;
			return true;
		}
	}
	return false;
}

template <class ItemType>
ItemType LLStack<ItemType>::peek() const {
	if (!isEmpty()) {
		return root->getNodeValue();
	}
	return -1;
}

template <class ItemType>
LLStack<ItemType>::~LLStack() {
	std::cout << "Stack deleted...\n";
}