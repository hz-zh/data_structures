#ifndef PQ_ARRAY_
#define PQ_ARRAY_

#include "PriorityQueueInterface.h"

#define SIZE 10

template<class ItemType>
class PQ_Array : public PriorityQueueInterface<ItemType> {
private:
	int itemCount;
	ItemType items[SIZE];
public:
	PQ_Array();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peek() const;
	void printPriorityQueue() const;
	~PQ_Array();
};	// end PQ_Array
#include "priorityQueueArray.cpp"
#endif