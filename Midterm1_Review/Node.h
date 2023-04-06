#ifndef NODE_CLASS_
#define NODE_CLASS_

#include<iostream>

class Node {
private:
	int value;
    Node *next;
public:
	//when a Node is created without any input
    Node():value(NULL), next(NULL){};
	//when a Node is created and a value is passed
    Node(int val):value(val), next(NULL){};
	//when a Node is created and a value and next pointer is passed
    Node(int val, Node *nextNode):value(val), next(nextNode){};
    
    Node* getNextNode() const;
    void setNextNode(Node*);
    int getNodeValue() const;
    void setNodeValue(int);
};

Node* Node::getNextNode() const{
    return next;
}

void Node::setNextNode(Node* nextNode){
    next = nextNode;
}


int Node::getNodeValue() const{
    return value;
}

void Node::setNodeValue(int val){
    value = val;
}

#endif
