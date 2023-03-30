#ifndef PQ_LL_IMP
#define PQ_LL_IMP

using namespace std;
#include "PQ_LL.h"

template<class ItemType>
PQ_LL<ItemType>::PQ_LL() : {
	root = NULL;
	cout << "created queue object..." << endl;
}

template<class ItemType>
bool PQ_LL<ItemType>::isEmpty() const {

}

template<class ItemType>
bool PQ_LL<ItemType>::enqueue(const ItemType& newEntry) {
	Node<ItemType>* current = root;

	if (!isEmpty()) {
		// add as first node
		if (newEntry < current->getNodeValue()) {
			Node<ItemType>* temp = new Node<ItemType>(newEntry, root);
			root = temp;
			return true;
		}
		// priority higher than root
		// insert at position
		else {
			while (current->getNextNode() != NULL) {
				if (newEntry >= current->getNodeValue() && newEntry <= current->getNextNode()->getNodeValue()) {
					Node<ItemType>* temp = new Node<ItemType>(newEntry, current->getNextNode());
					current->setNextNode(temp);
					return true;
				}
				else {
					current = current->getNextNode();
				}
			}
			Node<ItemType>* temp = new Node<ItemType>(newEntry);
			current->setNextNode(temp);
			current = current->getNextNode();
			bud = current;
			return true;
		}
	}
}
template<class ItemType>
bool PQ_LL<ItemType>::dequeue() {

}
template<class ItemType>
ItemType PQ_LL<ItemType>::peek() const {

}

template<class ItemType>
void PQ_LL<ItemType>::printQueue() const {

}

template<class ItemType>
PQ_LL<ItemType>::~PQ_LL() {
	cout << "Deleting queue..." << endl;
}

#endif