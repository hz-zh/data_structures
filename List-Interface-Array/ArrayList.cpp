#include "ArrayList.h"

using namespace std;

template <class ItemType>
ArrayList<ItemType>::ArrayList() {
	maxItems = MAX_SIZE_;
	itemCount = 0;
};

template <class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
	return itemCount == 0;
};

template <class ItemType>
int ArrayList<ItemType>::getLength() const {
	return itemCount;
};


template <class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
	if (newPosition < maxItems) {
		if ((newPosition >= 0) && (newPosition < getLength() + 1)) {
			for (int i = getLength() - 1; i >= newPosition; i--) {
				items[i + 1] = items[i];
			}
			items[newPosition] = newEntry;
			itemCount++;
		}
		else {
			cout << "Location for insert is outside of active list." << endl;
			return false;
		}
	}
	else {
		cout << "Location for insert outside of list bounds" << endl;
		return false;
	}
	return true;
};

template <class ItemType>
bool ArrayList<ItemType>::remove(int position) {
	if (position < maxItems) {
		if ((position >= 0) && (position < getLength() + 1)) {
			for (int i = position; i <= getLength() - 1; i++) {
				items[i] = items[i+1];
			}
			itemCount--;
		}
		else {
			cout << "Location for remove is outside of active list." << endl;
			return false;
		}
	}
	else {
		cout << "Location for remove outside of list bounds" << endl;
		return false;
	}
	return true;
};

template <class ItemType>
void ArrayList<ItemType>::clear() {

};

template <class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	return items[position];
};

template <class ItemType>
void ArrayList<ItemType>::replace(int position, const ItemType& newEntry) {
	items[position] = newEntry;
};

template <class ItemType>
void ArrayList<ItemType>::printList() const {
	for (int i = 0; i < itemCount; i++) {
		cout << "Item " << i << ": " << items[i] << endl;
	}
};