#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "es2-listTest.h"
#include "es2-bst.h"

bool is_number(string s) {
	if (s.size() == 0) { // se è una stringa vuota non è un numero
		return false;
	}
	
	for (int i = 0; i < s.size(); i++) { // scorro tutti i caratteri della stringa
		if ((s[i] >= '0' && s[i] <= '9') == false) { // se il carattere non è un numero
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	BST<ItemA, keyA> uffici; 
	BST<ItemB, keyB> telefoni;
	string ufficio, nome, telefono_str;
	keyB telefono;

	// lettura dai file
	ifstream myfile("telefoni.txt");
	if (myfile.is_open()) {
		while (getline(myfile, ufficio, ',')) {
			getline(myfile, nome, ',');
			getline(myfile, telefono_str);

			istringstream token(telefono_str);
			token >> telefono;

			ItemA vA(ufficio, nome);
			uffici.insert(vA);

			ItemB vB(nome, telefono);
			telefoni.insert(vB);
		}
	}
	myfile.close();

	// bilanciamento e stamparli in-order
	uffici.balance();
	telefoni.balance();

	cout << "BST degli uffici: " << endl;
	uffici.show(cout);
	cout << endl;

	cout << "BST dei telefoni: " << endl;
	telefoni.show(cout);
	cout << endl;

	// stampa con algoritmo non efficiente (visitando secondo albero iterativamente con la funzione select)
	for (int i = 0; i < telefoni.tree_size(); i++) {
		ItemB itB = telefoni.select(i); // select() restituisce l'i-esimo elemento piu piccolo
		ItemA itA = uffici.search(itB.get_nominativo()); // search() cerca in base alla chiave passata
		cout << itA.get_ufficio() << " " << itA.key() << " " << itB.key() << endl;
	}
	
	string str;
	while (1) {
		cout << endl << "Inserisci una stringa: ";
		getline(cin, str);

		// se la stringa è un numero > cerco con numero e se lo trovo stampo tutte le informazioni
		if (is_number(str)) {
			istringstream tk(str); // casto in int/keyB
			tk >> telefono;

			ItemB itB = telefoni.search(telefono); // cerco qui perchè il telefono è la chiave
			ItemA itA = uffici.search(itB.get_nominativo()); // poi cerco lo stesso elemento con il nome che è la chiave

			if (itB.null()) {
				cout << "Errore! Elemento non trovato" << endl;
			}
			else {
				cout << itA.get_ufficio() << " " << itA.key() << " " << itB.key() << endl;
			}
		}
		else {
			ItemA itA = uffici.search(str); // cerco con il nome
			if (!itA.null()) {
				cout << "Ecco tutte le persone che lavorano nell'ufficio di " << str << ": ";
				for (int i = 0; i < uffici.tree_size(); i++) {
					ItemA tmpA = uffici.select(i);
					if (itA.get_ufficio() == tmpA.get_ufficio()) {
						cout << tmpA.key() << endl;
					}
				}
			}
			else {
				cout << "Errore! Elemento non trovato" << endl;
			}
		}
	}

	return 0;
}