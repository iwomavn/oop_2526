#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <time.h> 

using namespace std;

#include "link.h"
#include "llist.h"
#include "ListTest.h"

void insertionsort(List<Item>& L) {
	Item tmp, current;
	
	for (int i = 1; i < L.length(); i++) {
		L.moveToPos(i); // sposto alla posizione attuale
		tmp = L.getValue(); // prendo il valore attuale
		
		for (int j = 0; j < i; j++) { // for interno per scorrere il secondo
			L.moveToPos(j);
			current = L.getValue();
			if (tmp.key() >= current.key()) { // decrescente  n
				L.moveToPos(i);  
				L.remove();
				
				L.moveToPos(j);
				L.insert(tmp); 
				break;
			}
		}
	}
}

// Main routine 
int main(int argc, char** argv) { 
	LList<Item> lista;
	
	srand(time(nullptr));

	for (int i = 0; i < 10; i++) {
		lista.insert(Item(rand() % 100));
	}

	cout << "Ecco la lista: "; 
	lprint(lista);
	insertionsort(lista);
	cout << "Ecco la lista ordinata: "; 
	lprint(lista);

	return 0;
}