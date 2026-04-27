#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

#include "link.h"
#include "llist.h"
#include "ListTest.h"

#include "lstack.h"

void bubblesort(List<Item>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key() < it_j.key())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
	L.moveToStart();
}

int main() {
	LList<Item> biglietti_venduti;
	int n_biglietto, K, i = 0, vincitore_i;
	string nome, cognome;
	float valore, tot_premi = 0;

	ifstream myfile("biglietti.txt");
	if (myfile.is_open()) {
		while (myfile >> n_biglietto >> nome >> cognome) {
			Item tmp(n_biglietto, nome, cognome);
			biglietti_venduti.append(tmp);
		}
		myfile.close();
	}
	
	cout << "Ecco la lista: " << endl;
	lprint(biglietti_venduti);
	bubblesort(biglietti_venduti);

	cout << "Ecco la lista ordinata in modo decrescente: " << endl;
	lprint(biglietti_venduti);

	cout << "Inserire un numero (minore o uguale a 7): ";
	cin >> K;
	if (K >= 7) {
		cout << "Programma terminato";
		return 0;
	}

	Premio* array = new Premio[K];

	ifstream myfile2("premi.txt");
	if (myfile2.is_open()) {
		while (i<K) {
			myfile2 >> nome >> valore;
			valore = valore / 100;
			Premio tmp(nome, valore);
			array[i] = tmp;
			i++;
		}
		myfile.close();
	}

	cout << "Ecco l'array di premi: " << endl;
	for (i = 0; i < K; i++) {
		cout << array[i];
	}
	cout << endl;

	Premio t = array[0];
	array[0] = array[K - 1];
	array[K - 1] = t;
	cout << "Ecco l'array di premi con il primo e ultimo elemento scambiati: " << endl;
	for (i = 0; i < K; i++) {
		cout << array[i];
	}
	cout << endl;

	LStack<Premio> premi;
	for (i = 0; i < K; i++) {
		tot_premi = tot_premi + array[i].get_valore();
		premi.push(array[i]);
	}

	cout << "Ecco lo stack di premi: " << endl;
	Lstackprint(premi);
	cout << "Valore totale premi: " << tot_premi;

	while (premi.length() > 0) {
		Premio p = premi.pop();
		vincitore_i = rand() % biglietti_venduti.length();
		biglietti_venduti.moveToPos(vincitore_i);

		Item vincitore = biglietti_venduti.getValue();
	}

	return 0;
}