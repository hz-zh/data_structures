#ifndef BINARY_NODE
#define BINARY_NODE

template<class ItemType>
class Binary_Node {
private:
	ItemType value;
	Binary_Node* leftChildPtr;
	Binary_Node* rightChildPtr;
public:
	// constructors using initializers
	Binary_Node() : value(0), leftChildPtr(nullptr), rightChildPtr(nullptr) {};				// new Binary_Node with nullptr on both children
	Binary_Node(ItemType val) : value(val), leftChildPtr(nullptr), rightChildPtr(nullptr) {};		// new Binary_Node with value and no children
	Binary_Node(ItemType val, Binary_Node* l, Binary_Node* r ) : value(val), leftChildPtr(l), rightChildPtr(r) {};		// 

	// class methods
	Binary_Node<ItemType>* getLeftNode() const;
	Binary_Node<ItemType>* getRightNode() const;
	void setLeftNode(Binary_Node<ItemType>*);
	void setRightNode(Binary_Node<ItemType>*);
	ItemType getNodeValue() const;
	void setNodeValue(ItemType);
	bool isLeaf() const;
};

template<class ItemType>
bool Binary_Node<ItemType>::isLeaf() const {
	return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
};


template<class ItemType>
Binary_Node<ItemType>* Binary_Node<ItemType>::getLeftNode() const {
	return leftChildPtr;
};

template<class ItemType>
Binary_Node<ItemType>* Binary_Node<ItemType>::getRightNode() const {
	return rightChildPtr;
};

template<class ItemType>
void Binary_Node<ItemType>::setLeftNode(Binary_Node<ItemType>* n) {
	leftChildPtr = n; // set next Node ptr
};

template<class ItemType>
void Binary_Node<ItemType>::setRightNode(Binary_Node<ItemType>* n) {
	rightChildPtr = n; // set next Node ptr
};

template<class ItemType>
ItemType Binary_Node<ItemType>::getNodeValue() const {
	return value; // get this node value
};

template<class ItemType>
void Binary_Node<ItemType>::setNodeValue(ItemType v) {
	value = v;		// set this node value
};


#endif