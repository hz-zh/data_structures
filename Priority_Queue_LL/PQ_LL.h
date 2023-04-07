#ifndef PQ_LL_
#define PQ_LL_

#include "PriorityQueueInterface.h"
#include "Node.h"


template<class T>
class PQ_LL : public PriorityQueueInterface<T> {
private:
	Node<T>* root;
	Node<T>* bud;
	Node<T> dummy;
	int itemCount;
public:
	PQ_LL();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue();
	T peek() const;
	void printQueue() const;
};
#include "PQ_LL.cpp"
#endif
