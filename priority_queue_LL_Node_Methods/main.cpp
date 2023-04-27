#include <iostream>
#include "LL_PriorityQueue.h"
using namespace std;

int main(){
	LL_PriorityQueue<int> pq;
	pq.enqueue(1);
	pq.enqueue(4);
	pq.enqueue(3);
	pq.enqueue(0);
	pq.enqueue(5);
	//print queue
	pq.printQueue();
	//peek a value
    cout << "Highest Priority Value: " << pq.peek() << endl;
	//dequeue a value
	pq.dequeue();
	cout << "Highest Priority Value: " << pq.peek() << endl;
	pq.dequeue();
	cout << "Highest Priority Value: " << pq.peek() << endl;
	pq.printQueue(1);
   // system("pause");
    return 0;
}
