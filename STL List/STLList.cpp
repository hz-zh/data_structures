#ifndef STL_LIST_IMPLEMENTATION_
#define STL_LIST_IMPLEMENTATION_
#include <iostream>
#include "STLList.h"
#include <list>


template<class ItemType>
STLList<ItemType>::STLList() {

};

template<class ItemType>
bool STLList<ItemType>::isEmpty() const {
	return myList.empty();
};

template<class ItemType>
int STLList<ItemType>::getLength() const {
	return myList.size();
};

template<class ItemType>
bool STLList<ItemType>::insert(int position, const ItemType& newEntry) {
	if (position > 0) {
		std::list<int>::iterator iter = myList.begin();
		for (int i = 0; i <= position; i++) {
			iter++;
		}
		myList.insert(iter, newEntry);
		return true;
	}
	std::cout << "insert says: Position is out of range of the list!" << std::endl;
	return false;
};

template<class ItemType>
bool STLList<ItemType>::remove(int position) {
	if (position > 0) {
		std::list<int>::iterator iter = myList.begin();
		for (int i = 0; i <= position; i++) {
			iter++;
		}
		myList.erase(iter);
		return true;
	}
	std::cout << "remove says: Position is out of range of the list!" << std::endl;
	return false;
};

template<class ItemType>
void STLList<ItemType>::clear() {

};

template<class ItemType>
ItemType STLList<ItemType>::getEntry(int position) const {

};

template<class ItemType>
void STLList<ItemType>::replace(int position, const ItemType& newEntry) {

};

template<class ItemType>
void STLList<ItemType>::printList() const {
	std::list<int>::iterator iter = myList.begin();
	for (int i = 0; i <= myList.size(); i++) {
		iter++;
		std::cout << *iter << " ";
	}
};

template<class ItemType>
STLList<ItemType>::~STLList() {
	std::cout << "List deleted..." << std::endl;
}

#endif