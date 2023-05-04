#ifndef GENERIC_NODE
#define GENERIC_NODE

#include <vector>

template<class ItemType>
class Generic_Node {
private:
	ItemType value;
	std::vector<Generic_Node*> child;
public:
	// constructor using initializers
	Generic_Node() : value(0) {}; // new Generic_Node with value 0
	Generic_Node() : value(val) {}; // new Generic_Node with value val

	// class methods
	Generic_Node<ItemType>* getChild(int) const;
	void addChild(int);
	ItemType getChildValue() const;
	void setChildValue(ItemType);
};

template<class ItemType>
Generic_Node<ItemType>* Generic_Node<ItemType>::getChild(int pos) const {
	if (pos <= node.size()) {
		return node[pos];
	}
	return nullptr;
};

template<class ItemType>
void Generic_Node<ItemType>::addChild(int val) {
	child.push_back(new Generic_Node(val));
};

template<class ItemType>
ItemType Generic_Node<ItemType>::getChildValue() const {
	return value; // get this node value
};

template<class ItemType>
void Generic_Node<ItemType>::setChildValue(ItemType v) {
	value = v;		// set this node value
};


#endif