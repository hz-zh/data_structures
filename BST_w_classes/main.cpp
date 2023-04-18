#include <iostream>
#include "BinaryTree.h"

int main() {

	BinaryTree myTree;

	myTree.add(5);
	myTree.add(10);
	myTree.add(15);
	myTree.add(20);

	std::cout << "\nTree: ";
	myTree.printTree(myTree.getRoot());

	return 0;
}