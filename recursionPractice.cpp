#include <iostream>
#include <vector>

void printCount(int start_at, int stop_at);

int main() {

	int start = 10;
	int stop = 10;
	for (int i = start; i < stop; i++) {
		std::cout << i << endl;
	}

	printCount(start, stop);
	std::cout << endl;

	std::vector<int> li = { 1,2,3,4,5,7,8,9,10 };
	printList(li);

	return 0;
}

void printCount(int start_at, int stop_at) {
	if (start_at != stop_at) {
		std::cout << start_at << ' ';
		printCount(start_at + 1, stop_at);
	}
}

template <class T>
void printList(vector<T> L) {
	for (int i = 0; i < 9; i++) {
		std::cout << L[i] << ' '; 
	}
}

template <class T>
void printListRec(args) {

}