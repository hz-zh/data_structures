#include <iostream>
#include "STLList.h"
using namespace std;

int main(){

    STLList<int> myList;

    myList.insert(myList.getLength(),10);
    myList.insert(myList.getLength(),20);
    myList.insert(myList.getLength(),30);
    myList.insert(myList.getLength(),40);
    myList.printList();
    cout << "Inserting 50 at 1: ";
    myList.insert(1,50);
    myList.printList();
    cout << "at 3: " << myList.getEntry(3) << endl;
    cout << "Inserting 100 at 3: ";
    myList.insert(3,100);
    myList.printList();
    cout << "Removing 40: ";
    myList.remove(5);
    myList.printList();
    cout << "replacing w/ 70 at 3: ";
    myList.replace(3,70);
    myList.printList();
    cout << "Inserting 80 at end.\n";
    myList.insert(myList.getLength(),80);
    cout << "Inserting 90 at end.\n";
    myList.insert(myList.getLength(),90);
    cout << "Inserting 110 at 1: ";
    myList.insert(1,110);
    myList.printList();
	system("pause");
    return 0;
}
