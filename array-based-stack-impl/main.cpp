#include <iostream>
#include "ArrayStack.h"

int main(){
    ArrayStack<int> sta;
    sta.push(1);
    sta.push(2);
    sta.push(3);
    sta.push(4);
    sta.push(5);
    sta.push(6);
    //sta.pop();

	//if stack is not empty, peek
    if (!sta.isEmpty())
		std::cout << "Peeked value: " << sta.peek() << "\n";


    //if stack is not empty, pop
	if (!sta.isEmpty()) {
		sta.pop();
		std::cout << "Popped value. \n";
	}
	else
		std::cout << "Stack empty\n";
    
	//print stack -- stack will be empty after printing
	sta.printStack();


	//sta.push(1);
	//sta.push(2);
	//sta.push(3);
	//print stack -- stack will be empty after printing
	//sta.printStack();

    system("pause");
return 0;
}
