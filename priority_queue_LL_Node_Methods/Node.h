#ifndef NODE_CLASS_
#define NODE_CLASS_

#include<iostream>

template<class ItemType>
class Node {
    ItemType value;
    Node<ItemType> *next;
    Node<ItemType> *prev;
public:
    Node():value(ItemType(0)), next(nullptr), prev(nullptr){};
    Node(ItemType val):value(val), next(nullptr), prev(nullptr){};
    // Node(ItemType val, Node<ItemType> *nextNode):value(val), next(nextNode), prev(nullptr){};
    // Node(ItemType val, Node<ItemType> *prevNode):value(val), prev(prevNode), next(nullptr){};
    Node(ItemType val, Node<ItemType> *nextNode, Node<ItemType> *prevNode):value(val), next(nextNode), prev(prevNode){};
    
    Node<ItemType>* getNextNode() const;
    void setNextNode(Node<ItemType>*);
    Node<ItemType>* getPrevNode() const;
    void setPrevNode(Node<ItemType>*);
    ItemType getNodeValue() const;
    void setNodeValue(ItemType);
    
};


template<class ItemType>
Node<ItemType>* Node<ItemType>::getNextNode() const{
    return next;
}

template<class ItemType>
void Node<ItemType>::setNextNode(Node<ItemType>* nextNode){
    next = nextNode;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrevNode() const{
    return prev;
}

template<class ItemType>
void Node<ItemType>::setPrevNode(Node<ItemType>* prevNode){
    prev = prevNode;
}

template<class ItemType>
ItemType Node<ItemType>::getNodeValue() const{
    return value;
}

template<class ItemType>
void Node<ItemType>::setNodeValue(ItemType val){
    value = val;
}

#endif
