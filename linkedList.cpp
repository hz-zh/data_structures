#include "Node.h"
#include <iostream>

using namespace std;

void printList(Node<int>*);

int main() {
	Node<int>* root = new Node<int>(10);
	Node<int>* second = new Node(20);
	Node<int>* third = new Node(30);

	root->setNextNode(second);
	second->setNextNode(third);

	// alternative
	//Node<int>* root = new Node<int>(5, new Node<int>(6, new Node<int>(7, nullptr)));



};

void printList(Node<int>* cur) {
	cur = root->next;
	while (cur->next) {
		cout << cur << endl;
		cur = cur->next;

	}
}