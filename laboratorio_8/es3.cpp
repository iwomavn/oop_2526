#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "es1-minHeap.h"

const int k = 3, n = 4;

int main(int argc, char** argv) {

	int array[k][n] = { {1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11} }; // array da ordinare (k array di n elementi)

	int sorted_array[k * n]; // nuovo array output dove salvare l'array ordinato

	MinHeapPQ<Item> minheap(k); // minheap di dimensione max k

	for (int i = 0; i < k; i++) { // devo inserire il primo elemento di ogni array dei k
		Item it(array[i][0], i, 1); // valore, indice array provenienza, indice elemento successivo sempre dell'array di provenienza
		minheap.insert(it);
	}

	int j = 0;
	for (int i = 0; i < k * n; i++) {
		Item it = minheap.getmin(); // prendo l'elemento più piccolo
		sorted_array[j] = it.key(); // lo inserisco nell'array (nella prima posizione disponibile)

		if (it.next_element < n) {
			Item to_insert(array[it.array_id][it.next_element], it.array_id, it.next_element + 1);
			minheap.insert(to_insert); // lo rimetto nel minheap
		}
		j++;
	}

	cout << "Ecco l'array ordinato: ";
	for (int i = 0; i < n * k; i++) {
		cout << sorted_array[i] << " ";
	}

	return 0;
} 