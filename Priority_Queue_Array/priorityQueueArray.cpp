#include "priorityQueueArray.h"

using namespace std;

#define SIZE 10

template<class ItemType>
PQ_Array<ItemType>::PQ_Array() : {}

template<class ItemType>
bool PQ_Array<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
bool PQ_Array<ItemType>::enqueue(const ItemType& newEntry) {
	bool ableToQueue = itemCount < SIZE;
	for (int i = 0; i < SIZE; i++) {
		if (newEntry > items[i]) {
			items[i + 1]
		}
	}
	if (ableToQueue) {
		items[itemCount + 1] = newEntry;
		itemCount++;
	}
	return ableToQueue;
}

template<class ItemType>
bool PQ_Array<ItemType>::dequeue() {

}

template<class ItemType>
ItemType PQ_Array<ItemType>::peek() const {
	return items[itemCount - 1];
}

template<class ItemType>
PQ_Array<ItemType>::~PQ_Array() {
	cout << "Deleting queue..." << endl;
}

template<class ItemType>
void PQ_Array<ItemType>::printPriorityQueue() const {
	for (int i = SIZE; i >= 0; i++)
}
