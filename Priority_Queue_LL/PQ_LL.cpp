#ifndef PQ_LL_IMP
#define PQ_LL_IMP

#include <iostream>
#include <cstddef>

template <class T>
PQ_LL<T>::PQ_LL()
{
    dummy = NULL;
    root = &dummy;
    bud = &dummy;
}

template <class T>
bool PQ_LL<T>::isEmpty() const
{
    return root == &dummy;
}

template <class T>
bool PQ_LL<T>::enqueue(const T& newEntry)
{
    if(isEmpty())
    {
        root = new Node<T>(newEntry);
        dummy.setNextNode(root);
		  bud = root;
        itemCount++;
        return true;
    }

    if(newEntry < root->getNodeValue())
    {
        root = new Node<T>(newEntry, root);
		  dummy.setNextNode(root);
        itemCount++;
        return true;
    }

    for(Node<T>* curr = root; curr->getNextNode() != nullptr; curr = curr->getNextNode())
    {
        if(curr->getNodeValue() <= newEntry && curr->getNextNode()->getNodeValue() >= newEntry)
        {
            curr->setNextNode(new Node<T>(newEntry, curr->getNextNode()));
            itemCount++; 
            return true;  
        }
    }
    bud->setNextNode(new Node<T>(newEntry));
    bud = bud->getNextNode();
    itemCount++;
    return true;
}

template <class T>
bool PQ_LL<T>::dequeue()
{
    if(isEmpty())
    {
        std::cout << "Cannot dequeue, the queue is empty." << std::endl;
        return false;
    }
	Node<T>* cur = root;
	while (cur->getNextNode()->getNextNode() != nullptr) {
		//std::cout << cur->getNodeValue() << " ";
		cur = cur->getNextNode();
	}
	bud = cur;
	bud->setNextNode(nullptr);
   itemCount--;
   return true;
}

template <class T>
T PQ_LL<T>::peek() const
{
    if(!isEmpty())
    {
        return bud->getNodeValue();
    }
    return 0;
}

template <class T>
void PQ_LL<T>::printQueue() const
{
    for(Node<T>* temp = root; temp != nullptr; temp = temp->getNextNode())
    {
        std::cout << temp->getNodeValue() << " ";
    }
    std::cout << std::endl;
}

#endif