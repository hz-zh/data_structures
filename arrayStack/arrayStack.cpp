#ifndef STACK_IMPL
#define STACK_IMPL

#define MAX 10
#include <iostream>
#include "arrayStack.h"


template<class T>
arrayStack<T>::arrayStack() : TOS(-1) {
    for (int i = 0; i < MAX; i++)    stack[i] = 0;
	std::cout << "Stack created...\n";
};

template<class T>
bool arrayStack<T>::isEmpty() const {
	if (TOS < 0) return true;
	else return false;
};

template<class T>
bool arrayStack<T>::push(const T& newEntry) {
    if (TOS < MAX - 1) {
        stack[++TOS] = newEntry;
        return true;
    }
    return false;
};

template<class T>
bool arrayStack<T>::pop() {
    
    if (!isEmpty()) {
        TOS--;
        return true;
    }
    else
        return false;
};

template<class T>
T arrayStack<T>::peek() const {
	if (!isEmpty())
		return stack[TOS];
	return T(0);
};

template<class T>
void arrayStack<T>::printStack(){
    std::cout << "STACK\n-----\n";
    while(!isEmpty()){
        std::cout << peek() << "\n";
      pop();
    }
    std::cout << "-----\nStack is empty\n";
};

template<class T>
arrayStack<T>::~arrayStack() {
    std::cout << "stack deleted...\n";
};

#endif