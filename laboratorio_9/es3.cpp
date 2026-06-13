#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "es3-bst.h"
#include "es3-listTest.h"

int main(int argc, char* argv[]) {
	BST<Item, Key> bstA, bstB;

	string str, nome, email, str_voto;
	int voto, matricola;

	ifstream myfile("parteA.txt");
	if (myfile.is_open()) {
		while (getline(myfile, str, ',')) {
			istringstream token(str);
			token >> matricola;

			getline(myfile, nome, ',');

			getline(myfile, str_voto, ',');
			if (str_voto == "INSUFFICIENTE") {
				voto = 0;
			}
			else {
				istringstream token2(str_voto);
				token2 >> voto;
			}
			myfile >> email;

			Item tmp(matricola, nome, voto, email);
			bstA.insert(tmp);
		}
	}
	myfile.close();
	
	myfile.open("parteB.txt");
	if (myfile.is_open()) {
		while (getline(myfile, str, ',')) {
			istringstream token(str);
			token >> matricola;

			getline(myfile, nome, ',');

			getline(myfile, str_voto, ',');
			if (str_voto == "INSUFFICIENTE") {
				voto = 0;
			}
			else {
				istringstream token2(str_voto);
				token2 >> voto;
			}
			myfile >> email;

			Item tmp(matricola, nome, voto, email);
			bstB.insert(tmp);
		}
	}
	myfile.close();
	
	bstA.balance();
	bstB.balance();

	cout << "BST parte A:" << endl;
	bstA.show(cout);
	cout << endl;

	cout << "BST parte B:" << endl;
	bstB.show(cout);
	cout << endl;

	// aggiungiamo in bst.h la nuova funzione di attraversamento
	bstA.stampa_risultati(bstB);

	return 0;
}