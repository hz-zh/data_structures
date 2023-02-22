#ifndef _Node_Class
#define _Node_Class
#include <vector>

template<class ItemType>
class Node {
private:
   ItemType value;
   Node* up, down, left, right;
public:
   //constructors
  Node() : value(0), up(0), down(0), left(0), right(0) {};
  Node(ItemType val, Node* left, Node* right) : value(val), left(left), right(right), down(0), up(0) {};
  Node(ItemType val, Node* up, Node* down, Node* left, Node* right) : value(val), left(left), down(down), right(right), up(up) {};

   // class methods - SETTERS
   void setVal(ItemType val);
   void setUp(Node* up);
   void setDown(Node* down);
   void setLeft(Node* left);
   void setRight(Node* right);

   // class methods - GETTERS
   ItemType getVal();
   Node* getUp() const;
   Node* getDown() const;
   Node* getLeft() const;
   Node* getRight() const;
};

//////////////////  SETTERS  /////////////////////////
template<class ItemType>
void Node<ItemType>::setVal(ItemType val) {
   value = val;
};

template<class ItemType>
void Node<ItemType>::setUp(Node* up) {
	up = up;
};

template<class ItemType>
void Node<ItemType>::setDown(Node* down) {
	down = down;
};

template<class ItemType>
void Node<ItemType>::setLeft(Node* left) {
	left = left;
};

template<class ItemType>
void Node<ItemType>::setRight(Node* right) {
	right = right;
};
////////////////  END SETTERS  /////////////////////


//////////////////  GETTERS  /////////////////////////
template<class ItemType>
ItemType Node<ItemType>::getVal() {
   return value;
};

template<class ItemType>
Node<ItemType>* Node<ItemType>::getUp() const {
   return up;
};

template<class ItemType>
Node<ItemType>* Node<ItemType>::getDown() const {
   return down;
};

template<class ItemType>
Node<ItemType>* Node<ItemType>::getLeft() const {
   return left;
};

template<class ItemType>
Node<ItemType>* Node<ItemType>::getRight() const {
   return right;
};
//////////////////  END GETTERS  ////////////////////

#endif