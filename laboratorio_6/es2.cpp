#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "link.h"
#include "alist.h"
#include "es2-ListTest.h" // serve per lprint


int data_minore(Item el1, Item el2)
{
	if ((el1.getanno() < el2.getanno()) || 
		(el1.getanno() == el2.getanno() && el1.getmese() < el2.getmese()) || 
		(el1.getanno() == el2.getanno() && el1.getmese() == el2.getmese() && el1.getgiorno() < el2.getgiorno()))
		return 1;
	else
		return 0;
}

void selectionsort(List<Item>& L) {
	int pos_min;
	Item min;

	// se lunghezza <2 non fai nulla
	for (int i = 0; i < (L.length() - 1); i++) {
		L.moveToPos(i);
		min = L.getValue();
		pos_min = i;
		for (int j = i + 1; j < L.length(); j++) {
			L.moveToPos(j);
			Item tmp = L.getValue();
			// se il cognome è minore dell'altro
			// oppure il cognome è uguale ma il nome e minore
			// oppure se cognome e nome sono uguali, guarda la data minore
			if ((tmp.getcognome() < min.getcognome()) ||
				((tmp.getcognome() == min.getcognome()) && (tmp.getnome() < min.getnome())) ||
				((tmp.getcognome() == min.getcognome()) && (tmp.getnome() == min.getnome()) && (data_minore(tmp, min))))
			{
				pos_min = L.currPos();
				min = tmp;
			}
		}
		L.moveToPos(pos_min);
		Item tmp2 = L.remove();
		L.moveToPos(i);
		L.insert(tmp2);
	}
}

int main() {
	AList<Item> agenda(100);
	string nome, cognome;
	int giorno, mese, anno;
	string s, s_tmp;

	ifstream myfile("agenda.txt");
	if (myfile.is_open()) { // se è aperto
		while (myfile >> nome >> cognome >> s) { // salvo le tre parole nelle tre variabili
			s_tmp = s.substr(0, 2); // prendo i primi due caratteri della stringa ovvero il giorno
			istringstream convert(s_tmp); // crea uno stream che contiene questi due numeri
			convert >> giorno; // li converto in int e li salvo nella variabie

			s_tmp = s.substr(3, 2); //SUBSTR PRENDE (POS_INIZIALE, LUNGHEZZA)
			istringstream convert2(s_tmp);
			convert2 >> mese;

			s_tmp = s.substr(6, 4);
			istringstream convert3(s_tmp);
			convert3 >> anno;

			Item tmp(nome, cognome, giorno, mese, anno); // creo oggetto Item con questi dati
			agenda.insert(tmp);
		}
		myfile.close();
	}

	cout << "Ecco l'agenda inizialmente: " << endl; 
	lprint(agenda);
	selectionsort(agenda);
	cout << endl << "Ecco l'agenda ordinata: " << endl; 
	lprint(agenda);

	return 0;
}