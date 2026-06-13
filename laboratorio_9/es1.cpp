#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include <fstream>

using namespace std;

#include "es1-listTest.h"
#include "es1-bst.h"


int main(int argc, char *argv[]) {
	BST<Item, int> bst; // bst x memorizzare le info lette dal file (usando id come key)
	BST<Item, int> bst2; // bst x memorizzare nuovi id e stringa da tastiera però (termina lettura quando viene inserito id negativo!)

	string str; // la stringa che utilizziamo x memorizzare temporeamente le info prima di metterli nel bst
	int k; // dove memorizziamo temporeamente gli id

	ifstream myfile("info.dat"); // leggiamo dal file
	if (myfile.is_open()) { // controllo se è aperto
		while (myfile >> k >> str) { // salvo in k e str i dati
			Item tmp(k, str); // creo oggetto Item con questi dati
			bst.insert(tmp); // lo inserisco nel bst
		}
	}
	myfile.close();

	cout << "Ecco il BST con i dati salvati dal file: " << endl;
	bst.show(cout); // stampa della classe bst.h (devi passare cout come parametro!). PER FARLO FUNZIONARE DEVI AGGUUNGERE UN METODO SHOW NELLA CLASSE ITEM!
	cout << endl;

	bst.balance(); // lo bilancio (trovo l'elemento centrale, lo mette alla radice e poi bilancia i sottoalberi)
	cout << "Ecco il BST con i dati salvati dal file bilanciato: " << endl;
	bst.show(cout); // stampa della classe bst.h (devi passare cout come parametro!)
	cout << endl;
	
	cout << "Inserisci coppie (id, stringa) - id negativo per terminare: " << endl;
	do {
		cin >> k >> str;
		Item tmp(k, str); // creo oggetto Item con questi dati
		if (tmp.key() >= 0) {
			bst2.insert(tmp); // lo inserisco nel bst2
		}
	} while (k >= 0);

	cout << "Ecco il BST con i dati salvati da tastiera: " << endl;
	bst2.show(cout);
	cout << endl;

	bst2.balance(); // lo bilancio (trovo l'elemento centrale, lo mette alla radice e poi bilancia i sottoalberi)
	cout << "Ecco il BST con i dati salvati da tastiera bilanciato: " << endl;
	bst2.show(cout); // stampa della classe bst.h (devi passare cout come parametro!)
	cout << endl;

	LList<Item> L;
	bst.merge(bst2, L);
	cout << "Ecco la lista: ";
	lprint(L);

	return 0;
}
