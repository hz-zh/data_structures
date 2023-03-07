#ifndef STL_LIST_
#define STL_LIST_
#include "ListInterface.h"
#include <list>

template<class ItemType>
class STLList : public ListInterface<ItemType> {
private:
	std::list<ItemType> myList;
public:
	STLList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const;
	void replace(int position, const ItemType& newEntry);
	void printList() const;
	~STLList();
};
#include "STLList.cpp"
#endif