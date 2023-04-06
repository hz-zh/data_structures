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

   myQu.printQueue();

 return 0;
}

