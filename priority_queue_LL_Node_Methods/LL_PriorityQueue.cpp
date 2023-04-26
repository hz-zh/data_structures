#include <iostream>
#include "LL_PriorityQueue.h"
#include "Node.h"
using namespace std;

template<class ItemType>
LL_PriorityQueue<ItemType>::LL_PriorityQueue(){
	cout << "New queue created..." << endl;
    root = NULL;
}

template<class ItemType>
bool LL_PriorityQueue<ItemType>::isEmpty() const {
    if (root == NULL) return true;
	else return false;
}

template<class ItemType>
bool LL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {
	Node<ItemType> *current = root;
	if (!isEmpty()){
		//priority less than root
		//add as first node
		if (newEntry < current->getNodeValue()) {
			// Incorrect
			//Node<ItemType> *temp = new Node<ItemType>(newEntry, nullptr, root);

			// Correct
			Node<ItemType> *temp = new Node<ItemType>(newEntry, current, nullptr);
			root = temp;
			current->setPrevNode(root);
			return true;
		}
		//priority higher than root
		//add at appropriate position
		else {
			while (current->getNextNode() != NULL) {
				if (newEntry >= current->getNodeValue() && newEntry <= current->getNextNode()->getNodeValue()) {
					// insert a new node between current and current->getNextNode()
					Node<ItemType> *temp = new Node<ItemType>(newEntry, current->getNextNode(), current);
					/// relink the queue ///
					current->setNextNode(temp);
					current = current->getNextNode();
					// set the previous of the following node to temp
					// *Missing this in the exam* //
					current->getNextNode()->setPrevNode(temp);
					return true;
				}
				else {
					current = current->getNextNode();
				}
			}

			//if priority of newEntry is highest, add as last node
			Node<ItemType> *temp = new Node<ItemType>(newEntry, nullptr, current);
			current->setNextNode(temp);
			current = current->getNextNode();
			lastNode = current;
			return true;
		}
    }
	//add first node
    else{
        root = new Node<ItemType>(newEntry);
		lastNode = root;
    }
	return true;
}

template<class ItemType>
bool LL_PriorityQueue<ItemType>::dequeue() {
	Node<ItemType> *current = root;
	//Node<ItemType> *beforeDeleted = NULL;
	if (!isEmpty()){
		if (current->getNextNode() == NULL){
			root = NULL;
			lastNode = root;
		}
	// move lastNode back one node
	lastNode = lastNode->getPrevNode();
	// set the next node of the new last node to NULL, losing the old first node
	lastNode->setNextNode(NULL);
	return true;
	}
	return false;
}

template<class ItemType>
ItemType LL_PriorityQueue<ItemType>::peek() const {
	if (!isEmpty())
		return lastNode->getNodeValue();
	return 0;
}

template<class ItemType>
void LL_PriorityQueue<ItemType>::printQueue(int direction) const {
	// print forwards
	if (!direction) {
		Node<ItemType> *current = root;
		cout << "Printing forwards..." << endl;
		while (true) {		
			if (current->getNextNode() == NULL){
				cout << current->getNodeValue() << " ";
				break;
			}
			else{
				cout << current->getNodeValue() << " ";
				current = current->getNextNode();
			}
		}
	}
	// print backwards
	else {
		Node<ItemType> *current = lastNode;
		cout << "Printing backwards..." << endl;
		while (true) {		
			if (current->getPrevNode() == NULL){
				cout << current->getNodeValue() << " ";
				break;
			}
			else{
				cout << current->getNodeValue() << " ";
				current = current->getPrevNode();
			}
		}
	}
	cout << endl;
}

template<class ItemType>
LL_PriorityQueue<ItemType>::~LL_PriorityQueue() {
	cout << "Queue deleted..." << endl;
}

