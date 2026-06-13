#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
using namespace std;

class Item {
private: 
	int val;
public:
	int array_id;
	int next_element;

	Item(int v = 0, int ai = 0, int ne = 0) { // costruttore
		val = v;
		array_id = ai;
		next_element = ne;
	}

	int key() const {
		return val;
	}

	bool operator> (const Item& other) const { // ricorda che se metti const a un metodo, i metodi che chiami dentro devono essere anche loro const (tipo key in questo caso). nel dubbio mettili tutti const i getter !
		if (val > other.key()) {
			return true;
		}
		else {
			return false;
		}
	}
};

template <class Item>
void exch(Item& A, Item& B) {
	Item tmp = A;
	A = B;
	B = tmp;
}

// copiata da heap.h del prof, basta scambiare il segno minore con il segno maggiore
// questa serve dopo aver inserito un nuovo elemento
template <class Item>
void MinHeapfixUp(Item a[], int k) { // passo array e posizione k dell'elemento appena inserito. 
	while (k > 1 && a[k / 2] > a[k]) { // controlla fino ad arrivare in cima: se nodo padre è maggiore dell'elemento appena inserito allora li scambio
		exch(a[k], a[k / 2]);
		k = k / 2; // salgo su
	}
}

// questa serve dopo la rimozione del minimo
template <class Item>
void MinHeapfixDown(Item a[], int k, int N) {
	while (2 * k <= N) {
		int j = 2 * k;
		if (j < N && a[j] > a[j + 1]) {
			j++;
		}
		if (!(a[k] > a[j])) {
			break;
		}
		exch(a[k], a[j]);
		k = j;
	}
}


template <class Item>
class MinHeapPQ { // classe che rappresenta struttura min-heap -> albero binario completo fatto con un array, ogni nodo figlio è maggiore o uguale al nodo padre
	private:
		Item* pq;
		int N; // indice
	public:
		MinHeapPQ(int maxN) { // costruttore. Crea un nuovo array di Item che sarà il nostro MinHeap e mette la dimensione quella passata come parametro
			pq = new Item[maxN + 1]; // parte da 1 l'indice no 0!
			N = 0;
		}

		~MinHeapPQ() { // distruttore
			delete[] pq; 
		}

		int empty() const { // vede se è vuoto
			return N == 0;
		}
		
		void insert(Item item) {
			pq[++N] = item;
			MinHeapfixUp(pq, N); // sistemo il heap (up -> salendo ? )
		}

		Item getmin() { // cerca il minimo nell'array, lo scambia con l'ultimo elemento e lo rimuove
			exch(pq[1], pq[N]); // scambio primo e ultimo nodo
			MinHeapfixDown(pq, 1, N - 1);
			return pq[N--];
		}

		void print() {
			for (int i = 1; i <= N; i++) {
				cout << pq[i].key() << " padre: " << pq[i / 2].key() << endl;
			}
		}
};

#endif 

