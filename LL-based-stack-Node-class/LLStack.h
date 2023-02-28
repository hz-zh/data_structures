#ifndef LL_STACK_
#define LL_STACK_
#include "StackInterface.h"
#include "Node.h"

template <class ItemType>
class LLStack : public StackInterface<ItemType> {
	Node<ItemType>* root;				//Underlying DS
public:
	LLStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const;
	~LLStack();
};

#include "LLStack.cpp"

#endif