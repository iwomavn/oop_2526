#include <iostream>
#include <string>

using namespace std;

#include <list> // lista doppiamente concatenata

#include "link.h"
#include "llist.h"
#include "listTest.h"

void listprint(list<Item>& l) {
	if (l.empty()) {
		cout << "La lista è vuota";
	}
	else {
		for (list<Item>::iterator it = l.begin(); it != l.end(); it++) { // begin() iteratore riferito al primo elemento, end() iteratore riferito all'ultimo elemento dei container, it++ punta al prossimo elemento
			cout << (*it) << " "; // *it ritorna l'elemento puntato
		}
	}
}

int main(int argc, char* argv[]) {
	LList<list<Item>> lista_di_liste; // lista singolarmente concatenata di liste doppiamente concatenate di Item
	
	// devo inserirci dentro 4 liste STL con elementi Item
	list<Item> L1, L2, L3, L4;

	L1.push_back(Item(1));
	L1.push_back(Item(2));
	L1.push_back(Item(3));
	L1.push_back(Item(4));
	cout << endl << "Ecco la lista 1 (L1): "; 
	listprint(L1);

	L2.push_back(Item(10));
	L2.push_back(Item(20));
	L2.push_back(Item(30));
	L2.push_back(Item(40));
	cout << endl << "Ecco la lista 2 (L2): ";
	listprint(L2);
	
	L3.push_back(Item(100));
	L3.push_back(Item(200));
	L3.push_back(Item(300));
	L3.push_back(Item(400));
	cout <<  endl << "Ecco la lista 3 (L3): ";
	listprint(L3);

	L4.push_back(Item(9));
	L4.push_back(Item(12));
	cout << endl << "Ecco la lista 4 (L4): ";
	listprint(L4);

	lista_di_liste.append(L1);
	lista_di_liste.append(L2);
	lista_di_liste.append(L3);
	lista_di_liste.append(L4);

	// scrivere algoritmo per trovare il key massimo tra tutti gli Item di lista_di_liste
	lista_di_liste.moveToStart(); // torno all'inizio della LList

	int max = lista_di_liste.getValue().front().key(); // getValue() ritorna elemento corrente di llist (L1), front() restituisce primo elemento della list e  prende il suo valore con key()

	for (lista_di_liste.moveToStart(); lista_di_liste.currPos() < lista_di_liste.length(); lista_di_liste.next()) {
		list<Item> l_tmp = lista_di_liste.getValue(); // lista corrente
		for (list<Item>::iterator it = l_tmp.begin(); it != l_tmp.end(); it++) { // scorro la lista corrente
			if ((*it).key() > max) {
				max = (*it).key();
			}
		}
	}

	cout << endl << "Il numero massimo e' " << max;
	return 0;
}