#include "Node2D.h"
#include <iostream>

using namespace std;


void printArray(int row, int col, Node<int>* array);

int main() {
	Node<int>* array1 = new Node<int>();


   return 0;
};

void printArray(int row, int col, Node<int>* array) {
   for( int i = 0; i <= row; i++ ) {
      for( int j = 0; j <= col; j++ ) {
         cout << array->getValAtIndex(i, j) << endl;
      }
   }
};
