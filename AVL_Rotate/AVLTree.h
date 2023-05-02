//AVL Tree

#include <iostream>
#include "BinaryNode.h"
using namespace std;

template <class V>
class AVLTree {
	BinaryNode<V> *root;
	int nodeCount;
public:
	AVLTree();
	//AVLTree(const V& newValue);
	bool isEmpty() const;
	int getHeight() const;
	int _getHeight(BinaryNode<V>*) const;
	int getNumberOfNodes() const;
	V getRootData() const;
	void setRootData(const V&);
	
	int balanceFactor(BinaryNode<V>*);			//new
	BinaryNode<V>* LLRotate(BinaryNode<V>*);	//new
	BinaryNode<V>* RRRotate(BinaryNode<V>*);	//new
	BinaryNode<V>* RLRotate(BinaryNode<V>*);	//new
	BinaryNode<V>* LRRotate(BinaryNode<V>*);	//new

	bool add(const V&);
	bool _add(const V&, BinaryNode<V>*);	//updated

	bool remove(const V&);
	BinaryNode<V>* _remove(const V&, BinaryNode<V>*);
	BinaryNode<V>* getInOrderSuccessor(BinaryNode<V>*);
	
	
	void clear();
	bool contains(const V&) const;
	bool _contains(BinaryNode<V>*, const V&) const;
	
	//print tree
	void printPreorder() const;
	void _printPreorder(BinaryNode<V> *curr) const;
	//void printInorder() const;
	//void printPostorder() const;
};

template<class V>
AVLTree<V>::AVLTree(){
	root = nullptr;
	nodeCount = 0;
}  
/*
template<class V>
AVLTree<V>::AVLTree(const V& newValue){
	root = new BinaryNode<V>(;
	objCount++;
}
*/
template<class V>
bool AVLTree<V>::isEmpty() const {
	return root == nullptr;
}

template<class V>
int AVLTree<V>::getHeight() const {
	return _getHeight(root);
}

template<class V>
int AVLTree<V>::_getHeight(BinaryNode<V>* curr) const{
	
	if (curr != nullptr) {
		int lHeight = _getHeight(curr->getLeftChildPtr());

		int rHeight = _getHeight(curr->getRightChildPtr());

		return ((lHeight > rHeight) ? lHeight + 1 : rHeight + 1);
	}
	else
		return 0;
}

template<class V>
int AVLTree<V>::getNumberOfNodes() const {
	return nodeCount;
}
	

template<class V>
V AVLTree<V>::getRootData() const {
	if (!isEmpty()) {
		return root->getValue();
	}
}

template<class V>
void AVLTree<V>::setRootData(const V& newValue) {
	root->setValue(newValue);
}


template<class V>
int AVLTree<V>::balanceFactor(BinaryNode<V>* curr) {
	if (curr->getLeftChildPtr() != nullptr && curr->getRightChildPtr() != nullptr) {
		return _getHeight(curr->getLeftChildPtr()) - _getHeight(curr->getRightChildPtr());
	}
	else if (curr->getLeftChildPtr() == nullptr && curr->getRightChildPtr() != nullptr) {
		return -(_getHeight(curr->getRightChildPtr()));
	}
	else if (curr->getLeftChildPtr() != nullptr && curr->getRightChildPtr() == nullptr) {
		return _getHeight(curr->getLeftChildPtr());
	}
}


template<class V>
BinaryNode<V>* AVLTree<V>::LLRotate(BinaryNode<V>* curr) {
	cout << "LLRotate..." << endl;
	BinaryNode<V> *temp1 = curr;
	BinaryNode<V> *temp2 = temp1->getLeftChildPtr();

	temp1->setLeftChildPtr(temp2->getRightChildPtr());
	temp2->setRightChildPtr(temp1);
	return temp2;
}

template<class V>
BinaryNode<V>* AVLTree<V>::RRRotate(BinaryNode<V>* curr) {
	cout << "RRRotate..." << endl;
	BinaryNode<V> *temp1 = curr;
	BinaryNode<V> *temp2 = temp1->getRightChildPtr();

	temp1->setRightChildPtr(temp2->getLeftChildPtr());
	temp2->setLeftChildPtr(temp1);
	return temp2;
}

template<class V>
BinaryNode<V>* AVLTree<V>::RLRotate(BinaryNode<V>* curr) {
	cout << "RLRotate..." << endl;
	BinaryNode<V> *temp1 = curr;
	BinaryNode<V> *temp2 = temp1->getRightChildPtr();
	BinaryNode<V> *temp3 = temp1->getRightChildPtr()->getLeftChildPtr();

	temp1->setRightChildPtr(temp3->getLeftChildPtr());
	temp2->setLeftChildPtr(temp3->getRightChildPtr());
	temp3->setLeftChildPtr(temp1);
	temp3->setRightChildPtr(temp2);
	
	return temp3;
}

template<class V>
BinaryNode<V>* AVLTree<V>::LRRotate(BinaryNode<V>* curr) {
	cout << "LRRotate..." << endl;
	BinaryNode<V> *temp1 = curr;
	BinaryNode<V> *temp2 = temp1->getLeftChildPtr();
	BinaryNode<V> *temp3 = temp1->getLeftChildPtr()->getRightChildPtr();

	temp1->setLeftChildPtr(temp3->getRightChildPtr());
	temp2->setRightChildPtr(temp3->getLeftChildPtr());
	temp3->setRightChildPtr(temp1);
	temp3->setLeftChildPtr(temp2);

	return temp3;
}

template<class V>
bool AVLTree<V>::add(const V& newValue) { // Adds a node
	cout << endl << "adding node: " << newValue << endl;
	BinaryNode<V> *curr = root;
	//cout << "Depth factor at node" << curr->getValue() << ": " << balanceFactor(curr) << endl;
	if (!isEmpty()) {
		return _add(newValue, curr);
	}
	else {
		BinaryNode<V> *temp = new BinaryNode<V>(newValue);
		root = temp;
		nodeCount++;
		return true;
	}
}


template<class V>
bool AVLTree<V>::_add(const V& newValue, BinaryNode<V> *curr){
    if(newValue > curr->getValue()){
      if (curr->getRightChildPtr() == nullptr) {
        //add node here
        BinaryNode<V> *temp = new BinaryNode<V>(newValue);
        curr->setRightChildPtr(temp);
        nodeCount++;
        return true;
      }
      else{
        _add(newValue, curr->getRightChildPtr());
      }
    }
    else if(newValue < curr->getValue()){
      if (curr->getLeftChildPtr() == nullptr) {
        //add node here
        BinaryNode<V> *temp = new BinaryNode<V>(newValue);
        curr->setLeftChildPtr(temp);
        nodeCount++;
        return true;
      }
      else{
        _add(newValue, curr->getLeftChildPtr());
      }
    }

	//cout << "Node added. Balancing tree.." << endl;
	//curr->setHeight(calculateHeight(curr));

	cout << "Node added." << endl;

	//allowed balance factor values are -1, 0 and 1

	if (balanceFactor(root) == 2 && balanceFactor(root->getLeftChildPtr()) == 1) {
		std::cout << "BF 2 at rt. Left Heavy. BF 1 at rt->left. LLRotate.\n";
		root = LLRotate(root);
	}
	else if (balanceFactor(root) == -2 && balanceFactor(root->getRightChildPtr()) == -1) {
		std::cout << "BF -2 at rt. Right Heavy. BF -1 at rt->right. RRRotate.\n";
		root = RRRotate(root);
	}
	else if (balanceFactor(root) == -2 && balanceFactor(root->getRightChildPtr()) == 1) {
		std::cout << "BF -2 at rt. Right Heavy. BF 1 at rt->right. RLRotate.\n";
		root = RLRotate(root);
	}
	else if (balanceFactor(root) == 2 && balanceFactor(root->getLeftChildPtr()) == -1) {
		std::cout << "BF 2 at rt. Left Heavy. BF -1 at rt->left. LRRotate.\n";
		root = LRRotate(root);
	}

    return false;
}

template<class V>
bool AVLTree<V>::remove(const V& removeValue) {
	cout << endl << "inside remove(), removing -->" <<removeValue << endl;

	if (!isEmpty()) {
		cout << "contains" << contains(removeValue) << endl;
		if (contains(removeValue)) {
			BinaryNode<V> *curr = root;
			_remove(removeValue, curr);
			return true;
		}
		else {
			cout << endl << "Node not found in tree" << endl;
			return false;
		}
	}
	else {
		cout << endl << "Tree is empty." << endl;
		return false;
	}

	return true;
}


template<class V>
BinaryNode<V>* AVLTree<V>::_remove(const V& removeValue, BinaryNode<V> *curr){
	cout << endl << "inside _remove() -->" << curr->getValue() << endl;
    //Reach the node to be deleted
    //if removeValue is less than curr node go to left tree

    if (removeValue < curr->getValue()){
        cout << endl << "less " << endl;
        curr->setLeftChildPtr(_remove(removeValue, curr->getLeftChildPtr()));
    }
    //if removeValue is greater than curr node go to right tree
    else if (removeValue > curr->getValue()){
        cout << endl <<"greater " << endl;
        curr->setRightChildPtr(_remove(removeValue, curr->getRightChildPtr()));
    }
    
    // if removeValue matches curr node
    else{
      //if curr has right child only or no child
      if (curr->getLeftChildPtr() == nullptr){
        //hold the pointer to the right child
        cout << endl << " x <--" << curr->getValue() <<"--> ?" << endl;
        BinaryNode<V> *temp = curr->getRightChildPtr();
        delete(curr);
        return temp;
      }
      //if curr has left child only or no child
      else if (curr->getRightChildPtr() == nullptr){
		//hold the pointer to the left child
		  cout << endl << " ? <--" << curr->getValue() << "--> x" << endl;
		BinaryNode<V> *temp = curr->getLeftChildPtr();
		delete(curr);
		return temp;
      }

      //if curr has both left and right child
      //find the next inorder successor,
      //swap its value and
      //remove inorder successor
	  cout << endl << " v <--" << curr->getValue() << "--> v" << endl;
      BinaryNode<V> *temp2 = getInOrderSuccessor(curr->getRightChildPtr());
      curr->setValue(temp2->getValue());
	  curr->setRightChildPtr(_remove(temp2->getValue(), curr->getRightChildPtr()));
    }
	return curr;
    
}


template<class V>
BinaryNode<V>* AVLTree<V>::getInOrderSuccessor(BinaryNode<V> *curr) {
	cout << endl << "inside getInOrderSuccessor() starting-->" << curr->getValue() << endl;
	//reach the smallest node on the left
	while (curr->getLeftChildPtr() != nullptr) {
			cout << curr->getValue() << " ";
			curr = curr->getLeftChildPtr();
	}
	cout << endl << "successor: " << curr->getValue() << endl;
	return curr;
}



template<class V>
void AVLTree<V>::clear(){
    root = nullptr;
    nodeCount = 0;
 }

template<class V>
bool AVLTree<V>::contains(const V& value) const {
	BinaryNode<V> *curr = root;
	if (!isEmpty())
		return _contains(curr, value);
	else 
		cout << endl << "Tree is empty." << endl;
	
	return false;
}

template<class V>
bool AVLTree<V>::_contains(BinaryNode<V> *curr, const V& value) const {
	if (curr != nullptr) {
		
		if (value == curr->getValue()) {
			cout << curr->getValue() << endl;
			return true;
		}
		else if (value < curr->getValue()) {
			return _contains(curr->getLeftChildPtr(), value);
		}
		else if (value > curr->getValue()) {
			return _contains(curr->getRightChildPtr(), value);
		}
	}
	return false;
}


 //print tree
template<class V>
void AVLTree<V>::printPreorder() const{
    BinaryNode<V> *curr = root;
    if(!isEmpty())
		    _printPreorder(curr);
    else
		    cout << endl << "Tree is empty." << endl;
 }

template<class V>
void AVLTree<V>::_printPreorder(BinaryNode<V> *curr) const{
    if (curr != nullptr){
		cout << curr->getValue() << "(" << _getHeight(curr) << ") ";
		//cout << "L: ";
		_printPreorder(curr->getLeftChildPtr());
		//cout << "R: ";
		_printPreorder(curr->getRightChildPtr());
    }
}