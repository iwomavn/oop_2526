using namespace std;

#include <string> // ricorda di mettere using std prima di questo
#include <cstdlib>
#include <iostream>

#include "list.h"
#include "link.h"
#include "llist.h"

#include "es2-ListTest.h"

// FUNZIONE FIND DI ALISTMAIN.CPP
// ritorna true se trova K (ritorna la posizione attuale di questo) sennò ritorna -1 (falso) se non c'è
int find (List<Item>& L, const Item& K) {
	Item it;
	for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
		it = L.getValue();
		if (K.key() == it.key()) { 
			return L.currPos(); } // trovo K e ritorna la sua posizione
	}
	return -1; // non trovo k
}

int find_abbreviazione(List<Item>& lista, Item it_abbreviazione) {
	int posizione_abbreviazione = find(lista, it_abbreviazione);

	if (posizione_abbreviazione == -1) { // non trovato
		lista.append(it_abbreviazione);
		return 1;
	}
	else {
		lista.moveToPos(posizione_abbreviazione); // sposto cursore alla posizione dell'Item dell'abbreviazione
		Item it = lista.getValue(); // prendo valore in quella posizione
		
		if (it.getParola() != it_abbreviazione.getParola()) // se la parola è diversa
		{
			lista.remove();
			it.setParola(it_abbreviazione.getParola()); // cambio parola
			lista.insert(it); // metto nuovo oggetto con parola cambiata
			return 2;
		}
		else {
			return 0;
		}
	}
}

int main(int argc, char** argv) {
	LList<Item> lista;
	lista.append(Item("TO", "Torino"));
	lista.append(Item("MI", "Milano"));
	lista.append(Item("PR", "Parma"));
	cout << "Ecco la lista iniziale: "; lprint(lista);

	Item temp("TO", "Torino");
	cout << find_abbreviazione(lista, temp) << endl;
	cout << "Ecco la lista dopo aver cercato Torino: "; lprint(lista);

	Item temp2("GE", "Genova");
	cout << find_abbreviazione(lista, temp2) << endl;
	cout << "Ecco la lista dopo aver cercato Genova: "; lprint(lista);

	Item temp3("PR", "Parma");
	cout << find_abbreviazione(lista, temp3) << endl;
	cout << "Ecco la lista dopo aver cercato Parma: "; lprint(lista);

	return 0;
}