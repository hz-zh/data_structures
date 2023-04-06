#ifndef PQ_LL_IMP
#define PQ_LL_IMP

#include <iostream>

template <class T>
PQ_LL<T>::PQ_LL()
{
    itemCount = 0;
    root = nullptr;
    bud = nullptr;
}

template <class T>
bool PQ_LL<T>::isEmpty() const
{
    return root == nullptr;
}

template <class T>
bool PQ_LL<T>::enqueue(const T& newEntry)
{
    if(isEmpty())
    {
        root = new Node<T>(newEntry);
        bud = root;
        itemCount++;
        return true;
    }

    if(newEntry < root->getNodeValue())
    {
        root = new Node<T>(newEntry, root);
        itemCount++;
        return true;
    }

    for(Node<T>* curr = root; curr->getNextNode() != nullptr; curr = curr->getNextNode())
    {
        if(curr->getNodeValue() <= newEntry && curr->getNextNode()->getNodeValue() >= newEntry)
        {
            Node<T>* temp = new Node<T>(newEntry, curr->getNextNode());
            curr->setNextNode(temp);
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

    root = root->getNextNode();
    itemCount--;
    return true;
}

template <class T>
T PQ_LL<T>::peek() const
{
    if(!isEmpty())
    {
        return root->getNodeValue();
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