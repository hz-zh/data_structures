#pragma once
#include "Binary_Node.h"
#include <iostream>


int main() {
	Binary_Node<int>* root = new Binary_Node<int>(1, new Binary_Node<int>(2), new Binary_Node<int>(3));

	std::cout << root->getLeftNode()->getNodeValue() << std::endl;
	std::cout << root->getRightNode()->getNodeValue() << std::endl;

}