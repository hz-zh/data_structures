#ifndef PQ_LL_
#define PQ_LL_

#include "PriorityQueueInterface.h"
#include "Node.h"


template<class ItemType>
class PQ_LL : public PriorityQueueInterface<ItemType> {
private:
	Node<ItemType>* root;
	Node<ItemType>* bud;
public:
	PQ_LL();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peek() const;
	void printQueue() const;
	~PQ_LL();
};
#include "PQ_LL.cpp"
#endif
