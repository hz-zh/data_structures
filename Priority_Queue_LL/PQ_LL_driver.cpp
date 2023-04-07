#include "PriorityQueueInterface.h"
#include "PQ_LL.h"
#include <iostream>

using namespace std;

int main() {
   PQ_LL<int> myQu;
   myQu.enqueue(1);
   myQu.enqueue(2);
   myQu.enqueue(3);
   myQu.enqueue(4);
   myQu.enqueue(5);
   myQu.printQueue();

   myQu.dequeue();
   myQu.printQueue();

   myQu.enqueue(6);
   myQu.enqueue(7);
   myQu.enqueue(8);
   myQu.enqueue(9);
   myQu.enqueue(10);
   myQu.printQueue();

   cout << myQu.peek() << endl;   
   myQu.dequeue();
   cout << myQu.peek() << endl;   
   myQu.dequeue();
   cout << myQu.peek() << endl;

   myQu.printQueue();

 return 0;
}

