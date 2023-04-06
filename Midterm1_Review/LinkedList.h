#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <iostream>
#include "Node.h"


//linked list
class LinkedList {
	Node *root;
public:
	static int objCount;
	LinkedList();
	LinkedList(int val);

	void printLinkedList();
	void addNewNode(int);
	void addSomeNodes(); //write definition for this class method
};

int LinkedList::objCount = 0;

LinkedList::LinkedList() {
	root = NULL;
}

LinkedList::LinkedList(int val) {
	Node *temp = new Node(val);
	root = temp;
	objCount++;
}

void LinkedList::printLinkedList() {
	Node *current = root;

	std::cout << std::endl << "List: ";

	if (objCount > 0) {
		do {
			std::cout << current->getNodeValue() << " ";
			if (current->getNextNode() == NULL)
				break;
			else
				current = current->getNextNode();
		} while (true);
	}
	else {
		std::cout << std::endl << "List is empty!";
	}
}


void LinkedList::addNewNode(int val) {

	Node *current = root;
	if (objCount == 0) {
		Node *temp = new Node(val);
		root = temp;
		objCount++;
	}
	else if (objCount > 0) {
		while (current->getNextNode() != NULL) {
			current = current->getNextNode();
		}

		Node *temp = new Node(val);
		current->setNextNode(temp);
		objCount++;
	}
}

//write definition for addSomeNodes() function here
void LinkedList::addSomeNodes() {
	Node* temp = root;

	while (temp != nullptr) {
		Node* newNode = new Node(0);
		newNode->setNextNode(temp->getNextNode());
		temp->setNextNode(newNode);
		temp = temp->getNextNode()->getNextNode();
		objCount++;
	}
}

#endif