using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "link.h"
#include "list.h"
#include "llist.h"

#include "ListTest.h"

// #define N 3
const int N = 3;

int main() {
	LList<Item> liste[N];

	srand(time(nullptr));
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < 4; j++) {
			liste[i].append(Item(rand()%100));
		}
		cout << "Ecco la lista " << i << ": ";
		lprint(liste[i]);
	}

	int max = 0, max_index = 0;
	for (int i = 0; i < N; i++) {
		for (liste[i].moveToStart(); liste[i].currPos() < liste[i].length(); liste[i].next()) {
			if ((liste[i].getValue()).key() > max) {
				max = (liste[i].getValue()).key();
				max_index = i;
			}
		}
	}
	cout << "Indice massimo: " << max_index << " Numero massimo: " << max << endl;
	return 0;
}

