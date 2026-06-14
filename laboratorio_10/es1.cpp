#include <iostream>
#include <string>
#include <list> // lista doppiamente concatenata

using namespace std;

int main(int argc, char *argv[]) {
	list<int> l1;

	l1.push_back(1); // metodo dei container sequenziali, inserisce infondo il valore
	l1.push_back(11);
	l1.push_back(21);
	l1.push_back(31);
	l1.push_back(41);
	l1.push_back(51);

	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++) { // begin() iteratore riferito al primo elemento, end() iteratore riferito all'ultimo elemento dei container, it++ punta al prossimo elemento
		cout << (*it) << " "; // *it ritorna l'elemento puntato
	}

	list<int>::iterator it = l1.begin(); // riporto l'iteratore all'inizio
	
	it++; // vado all'elemento successivo
	it = l1.insert(it, 91); // inserisce 91 prima della posizione di it

	it++; // vado all'elemento successivo
	it = l1.insert(it, 101); // inserisce 101 prima della posizione di it

	cout << endl;
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++) { // begin() iteratore riferito al primo elemento, end() iteratore riferito all'ultimo elemento dei container, it++ punta al prossimo elemento
		cout << (*it) << " "; // *it ritorna l'elemento puntato
	}

	return 0;
}