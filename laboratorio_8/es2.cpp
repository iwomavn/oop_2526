#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "es1-minHeap.h"

const int L = 4;

int main(int argc, char** argv) {
	
	int len[L] = { 4, 3, 2, 6 }; // lista delle lunghezze
	
	MinHeapPQ<int> mh(20); // creo il minheap

	for (int i = 0; i < L; i++) {
		mh.insert(len[i]); // lo popolo con le lunghezze
	}

	int costo_tot = 0;

	for (int i = 0; i < L - 1; i++) {
		int min = mh.getmin(); // estraggo il minimo (lo elimina anche)
		int sec_min = mh.getmin(); // estraggo il nuovo minimo

		costo_tot += min + sec_min;
		mh.insert(min + sec_min);
	}

	cout << "Il costo totale minimo: " << costo_tot;

	return 0;
}