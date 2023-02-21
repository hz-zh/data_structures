#ifndef STACK_IMPL
#define STACK_IMPL

#define MAX 10;
#include <iostream>
#include "arrayStack.h"

template <class T>
arrayStack<T>::arrayStack() : TOS(-1) {
	for (int i = 0; i < MAX; i++) {
		stack[i] = 0;
	}
	std::cout << "stack created" << endl;
};

template<class T>
bool arrayStack<T>::isEmpty() const {
	if (stack[0] == -1) return false;
};

template<class T>
bool arrayStack<T>::push(const T& newEntry) {
	if (TOS < MAX - 1) {
		stack[++TOS] = newEntry;
		return true;
	}
	return false;
};





#endif