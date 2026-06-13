#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "es1-minHeap.h"

int main(int argc, char** argv) {
	MinHeapPQ<Item> minheap(20);

	minheap.insert(5);
	minheap.insert(34);
	minheap.insert(55);
	minheap.insert(90);
	minheap.insert(11);

	minheap.insert(4);
	minheap.insert(67);
	minheap.insert(99);
	minheap.insert(23);
	minheap.insert(13);

	minheap.print();

	for (int i = 0; i < 10; i++) {
		cout << "L'elemento minimo del heap e': " << minheap.getmin().key() << endl;
	}

	return 0;
}