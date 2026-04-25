#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

#include "lqueue.h"
#include "es6-LQueueTest.h"

const int N = 9;
int main() {
	LQueue<Item> myQueue;
	float tmp, risultato;
	Item primo, secondo;
	int n_iterazione = 0, lunghezza;

	for(int i = 0; i < N; i++) {
		cout << "Inserisci il " << i+1 << " numero: ";
		cin >> tmp;
		myQueue.enqueue(Item(tmp));
	}

	while (myQueue.length() > 1) {
		lunghezza = myQueue.length(); // devo salvarla perche dentro al ciclo cambia!

		for (int i = 1; i <= lunghezza / 2; i++) {
			primo = myQueue.dequeue();
			secondo = myQueue.dequeue();

			switch (n_iterazione%4) {
			case(0): 
				risultato = primo.key() + secondo.key();
				break;
			case(1):
				risultato = primo.key() - secondo.key();
				break;
			case(2):
				risultato = primo.key() * secondo.key();
				break;
			case(3):
				risultato = primo.key() / secondo.key();
				break;
			}
			myQueue.enqueue(Item(risultato));
		}
		if (lunghezza % 2 == 1) {
			primo = myQueue.dequeue();
			myQueue.enqueue(primo);
		}

		cout << "Ecco la lista : ";
		Lqueueprint(myQueue);
		cout << endl;

		n_iterazione++;
	}
	return 0;
}