#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {
  AVLTree<int> myTree;
  cout << "isEmpty(): " << myTree.isEmpty() << endl;
  myTree.add(10);
  myTree.printPreorder();
  myTree.add(15);
  myTree.printPreorder();
  myTree.add(14);
  myTree.printPreorder();
  myTree.add(11);
  myTree.printPreorder();
  myTree.add(9);
  myTree.printPreorder();
  myTree.add(8);
  myTree.printPreorder();
  //myTree.add(1);
  //myTree.printPreorder();
  
  system("pause");
  return 0;
}