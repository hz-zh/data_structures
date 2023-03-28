/*
Author: David Hurtgen

Ungraded Homework, array implementation of priority queue
All expected results are commented
*/

#include <iostream>
#include "ArrayPriorityQueue.h"

int main() {
	ArrayPriorityQueue<int> myPq;
	myPq.enqueue(6);
	myPq.enqueue(8);
	myPq.enqueue(4);
	myPq.printPriorityQueue();				//468
	std::cout << myPq.isEmpty() << "\n";	//0
	myPq.dequeue();
	myPq.printPriorityQueue();				//46
	std::cout << myPq.peek() << "\n";		//6

	return 0;
}