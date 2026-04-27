#include <iostream>
#include <cstdlib>

#include <ctime>
#include <time.h>

#include <string>

#include <fstream>
#include <sstream>

using namespace std;

#include "link.h"
#include "llist.h"
#include "es1-ListTest.h"

int find(List<Prodotto>& L, string K) {
	Prodotto it;
	for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
		it = L.getValue();
		if (K == it.key()) return L.currPos();  
	}
	return -1;        
}

void bubblesort(List<Item>& L) { // passo la lista da ordinare
	for (int i = 0; i < (L.length() - 1); i++) { // scorro la lista
		for (int j = (L.length() - 1); j > i; j--) { // al contrario
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key().numero_piatto > it_j.key().numero_piatto)
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

int main() {
	LList<Prodotto> lista_dispensa;
	LList<Item> lista_ricette;
	string codice, nome, s_quantita, s_ricetta;
	int quantita;

	ifstream myfile("dispensa.txt");
	if (myfile.is_open()) {
		while (getline(myfile, codice, ';')) { // devo per forza usare gli apici singoli!!!
			getline(myfile, nome, ';');
			getline(myfile, s_quantita);

			istringstream token(s_quantita);
			token >> quantita; // converto la stringa in int e lo metto nella variabile

			Prodotto tmp(codice, nome, quantita); // creo oggetto temporaneo

			// vediamo se il prodotto è già nella lista
			int risultato = find(lista_dispensa, tmp.key());
			if (risultato == -1) {// funzione di Alistmain.cpp che serve a trovare un elemenmto dentro a una lista
				lista_dispensa.insert(tmp);
			}
			else {
				// se esiste gia' lo metto una sola volta ma sommando le quantita'
				Prodotto tmp_da_eliminare; // nuovo oggetto
				lista_dispensa.moveToPos(risultato);
				tmp_da_eliminare = lista_dispensa.getValue(); // prendo questo oggetto già esistente
				lista_dispensa.remove(); // lo elimina e ritorna

				tmp_da_eliminare.set_quantita(tmp_da_eliminare.get_quantita() + tmp.get_quantita()); // sommo le quantita
				lista_dispensa.insert(tmp_da_eliminare);
			}
		}
		myfile.close();
	}

	cout << "Ecco la dispensa: ";
	lprint(lista_dispensa);

	myfile.open("ricette.txt");
	if (myfile.is_open()) {
		while (getline(myfile, s_ricetta, ';')) {
			ricetta r;
			istringstream s_numero(s_ricetta);
			s_numero >> r.numero_piatto;

			getline(myfile, r.descrizione, ';');
			
			getline(myfile, r.primo_ingrediente, ';');
			getline(myfile, s_ricetta, ';');
			istringstream s_qprimo(s_ricetta);
			s_qprimo >> r.quantita_primo;

			getline(myfile, r.secondo_ingrediente, ';');
			getline(myfile, s_ricetta); // ultimo
			istringstream s_qsecondo(s_ricetta);
			s_qsecondo >> r.quantita_secondo;

			Item tmp(r);
			lista_ricette.insert(tmp);
		}
		myfile.close();
	}

	cout << "Ecco la lista delle ricette: ";
	lprint(lista_ricette);
	bubblesort(lista_ricette);
	cout << "Ecco la lista delle ricette ordinata: ";
	lprint(lista_ricette);
	
	while (1) {
		int piatto;
		cout << "Inserire il numero di un piatto: ";
		cin >> piatto;
	}

	return 0;
}