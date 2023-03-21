#include "LinkedList.h"

int main() {

	LinkedList myList;
	myList.printLinkedList();
	myList.addNewNode(5);
	myList.addNewNode(6);
	myList.addNewNode(7);
	myList.addNewNode(8);
	myList.addNewNode(9);
	myList.printLinkedList();

	myList.addSomeNodes();

	myList.printLinkedList();

	system("pause");
	return 0;
}