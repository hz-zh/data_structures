#ifndef _Node_Class
#define _Node_Class

template<class ItemType>
class Node {
private:
   ItemType value;
	int row; 
   int col;
public:
   //constructors
   Node() : row(0), col(0), value(0) {};
   Node(int row) : row(row), col(0), value(0) {};
   Node(int row, int col) : row(row), col(col), value(0) {};
   Node(int row, int col, ItemType val) : row(row), col(col), value(val) {}; 

// class methods
   int getRow() const;
   int getCol() const;
   void setRow(int);
   void setCol(int);
	ItemType getIndexValue() const;
	void setIndexVal(ItemType);
};

template<class ItemType>
int Node<ItemType>::getRow() const {
	return row;
};

template<class ItemType>
int Node<ItemType>::getCol() const {
	return col;
};

template<class ItemType>
void Node<ItemType>::setRow(int index) {
	row = index;
};

template<class ItemType>
void Node<ItemType>::setCol(int index) {
	col = index;
};

template<class ItemType>
ItemType Node<ItemType>::getIndexValue() const {
	return value; // get this node value
};

template<class ItemType>
void Node<ItemType>::setIndexVal(ItemType v) {
	value = v;		// set this node value
};

#endif