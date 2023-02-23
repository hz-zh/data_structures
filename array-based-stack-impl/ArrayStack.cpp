#ifndef STACK_IMPL
#define STACK_IMPL

#define MAX 10
#include <iostream>
#include "ArrayStack.h"


template<class ItemType>
ArrayStack<ItemType>::ArrayStack() :TOS(-1) {
    for (int i = 0; i < MAX; i++)    stack[i] = 0;
	std::cout << "Stack created...\n";
}

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
	if (TOS < 0) return true;
	else return false;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry) {
    if (TOS < MAX - 1) {
        stack[++TOS] = newEntry;
        return true;
    }
    return false;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop() {
    
    if (!isEmpty()) {
        TOS--;
        return true;
    }
    else
        return false;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
	if (!isEmpty())
		return stack[TOS];
	return ItemType(0);
}

template<class ItemType>
void ArrayStack<ItemType>::printStack(){
    std::cout << "STACK\n-----\n";
    while(!isEmpty()){
        std::cout << peek() << "\n";
      pop();
    }
    std::cout << "-----\nStack is empty\n";
}

template<class ItemType>
ArrayStack<ItemType>::~ArrayStack() {
    std::cout << "stack deleted...\n";
}

#endif