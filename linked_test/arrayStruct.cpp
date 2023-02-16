#include "Node2D.h"
#include <iostream>

using namespace std;


void printArray(int row, int col);

int main() {
   Node<int>* root = new Node<int>(0, 0, 0);
   Node<int>* second = new Node<int>(0, 1, 1);
   Node<int>* third = new Node<int>(0, 2, 2);
	


   return 0;
};
/*
void printArray(int row, int col) {
   Node<int>* root = new Node<int>(0, 0, 0);

   for( int i = 0; i <= row; i++ ) {
      for( int j = 0; j <= col; j++ ) {
         cout << 
      }
   }
};
*/