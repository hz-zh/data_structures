#include "Node.h"
#include <iostream>

using namespace std;

void printList(Node<int>*);
/** 
 * @pre  none
 * @post  a linked list of length n has been created and the pointer placed at the root.
 * @param  n the number of nodes to be created
 * @return a type Node* pointer at the root					*/
Node<int>* createIntList(int n);

int main() {
	Node<int>* root = new Node<int>(10);
	Node<int>* second = new Node<int>(20);
	Node<int>* third = new Node<int>(30);

	root->setNextNode(second);
	second->setNextNode(third);

	printList(root);
	
	// alternative
	//Node<int>* root = new Node<int>(5, new Node<int>(6, new Node<int>(7, nullptr)));

	// Create a list //
	Node<int>* list2Root = createIntList(20);
	printList(list2Root);

	return 0;
};

void printList( Node<int>* cur) {
	while (cur) {
		cout << cur->getNodeValue() << endl;
		cur = cur->getNextNode();
	}
};

Node<int>* createIntList(int n) {
	Node<int>* cur = new Node<int>(1);
	Node<int>* root = cur;
	for( int i = 0; i < n-1; i++ ) {
		Node<int>* next = new Node<int>(i+2);
		cur->setNextNode(next);
		cur = cur->getNextNode();
	}
	//Node<int>* tail = cur;		// may become useful in later versions to return the tail
	return root;
};