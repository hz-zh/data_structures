#ifndef _Node_Class
#define _Node_Class

template<class ItemType>
class Node {
private:
	ItemType value;
	Node* next;
public:
	// constructors using initializers
	Node() : value(0), next(nextptr) {}					// new Node
	Node(ItemType val) : value(val), next(nullptr) {}		// new Node(10)
	Node(ItemType val, Node* n) : value(val), next(n) {}		// new Node(10, mullptr)

	// class methods
	Node<ItemType>* getNextNode() const;
	void setNextNode(Node<ItemType>*);
	ItemType getNodeValue() const;
	void setNodeVal(ItemType);
};

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNextNode() const {
	return next;
};

template<class ItemType>
void Node<ItemType>::setNextNode(Node<ItemType>* n) {
	next = n; // set next Node ptr
};

template<class ItemType>
ItemType Node<ItemType>::getNodeValue() const {
	return value; // get this node value
};

template<class ItemType>
void Node<ItemType>::setNodeVal(ItemType v) {
	value = v;		// set this node value
};


#endif