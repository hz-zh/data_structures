#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#define MAX 10
#include <iostream>
#include "StackInterface.h"

template<class T>
class arrayStack : public StackInterface<T> {
private:
	T stack[MAX];
	int TOS;
public:
	arrayStack();
	bool isEmpty() const;
	bool push(const T& newEntry);
	bool pop();
	T peek() const;
	void printStack();
	~arrayStack();
};

#include "arrayStack.cpp"
#endif 