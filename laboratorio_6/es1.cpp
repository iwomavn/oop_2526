#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "link.h"
#include "llist.h"
#include "ListTest.h" // serve per lprint

void selectionsort(List<Item>& L) {
	int pos_min;
	Item min;
	
	// se lenght <2, non fai nulla
	for (int i = 0; i < L.length() - 1; i++) {
		L.moveToPos(i); // sposto a posizione corrente
		min = L.getValue(); // lo metto come minimo
		pos_min = i; // e metto la sua posizione nel pos_min
		
		for (int j = i + 1; j < L.length(); j++) { // qua controllo il prossimo
			L.moveToPos(j);
			Item tmp = L.getValue(); // lo salvo

			if (tmp.key() < min.key()) // se questo è il piu' piccolo
			{
				pos_min = L.currPos(); // la posizione del minimo adesso è questa
				min = tmp; // il minimodiventa questo
			}
		}

		L.moveToPos(pos_min); // sposto il cursore al minimo
		Item tmp2 = L.remove(); // salvo questo minimo
		L.moveToPos(i); 
		L.insert(tmp2); // lo rimetto al posto ordinato
	}
	L.moveToStart();
}

const int N = 5, MINVAL = 0, MAXVAL = 100;
int main() {
    LList<Item> L1, L2;

    srand(time(nullptr));
    for (int i = 0; i < N; i++) {
        L1.append(Item(MINVAL + rand()%(MAXVAL - MINVAL + 1)));
        L2.append(Item(MINVAL + rand() % (MAXVAL - MINVAL + 1)));
    }

    cout << "Ecco la prima lista: ";
    lprint(L1);

    cout << "Ecco la seconda lista: ";
    lprint(L2);

	selectionsort(L1);
	cout << "Ecco la prima lista ordinata: ";
	lprint(L1);

    return 0;
}
