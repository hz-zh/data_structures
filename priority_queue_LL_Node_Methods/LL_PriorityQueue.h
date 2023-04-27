#ifndef LL_PQ_
#define LL_PQ_

#include <iostream>
#include "PriorityQueueInterface.h"
#include "Node.h"
using namespace std;

template<class ItemType>
class LL_PriorityQueue : public PriorityQueueInterface<ItemType>{
  private:
    Node<ItemType> *root;
	Node<ItemType> *lastNode;
  public:
	  LL_PriorityQueue();
    
      bool isEmpty() const;

	  bool enqueue(const ItemType& newEntry);

	  bool dequeue();

	  ItemType peek() const;

	  void printQueue(int direction = 0) const;

	  ~LL_PriorityQueue();
};

#include "LL_PriorityQueue.cpp"
#endif
