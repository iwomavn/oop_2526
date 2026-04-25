#include <iostream>
#include <cstdlib>
#include <string>

using namespace std; 

#include "list.h"
#include "link.h"
#include "llist.h"
#include "ListTest.h"

// FUNZIONE DI LISTMAIN.CPP
void insert_ordered(List<Item>& L, const Item& it) { // passo lista di Item ed elemento Item e inserisco l'elemento rispettando l'ordine e il cursore viene messo prima
	if (L.length() == 0) // se la lista è vuota
	{
		L.insert(it); // inserisco elemento a destra del cursore (se è vuota all'inizio)
		return;
	}

	for (L.moveToStart(); L.currPos() < L.length(); L.next()) { // metto cursore all'inizio, cursore minore lunghezza, cursore spostato di uno a destra
		if (it.key() <= L.getValue().key()) // .key() returna il val di Item, .getValue() ritorna l'elemento corrente della lista (quello a destra del  cursore)
		// se l'Item è minore del attuale Item vicino al cursore
		{
			L.insert(it); // lo inserisco a destra del cursore
			return;
		}
	}
	L.append(it); // se Item è il più grande di tutti lo mettom alla fine
}

void fondiliste(List<Item>& L1, List<Item>& L2, List<Item>& L3) {
	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next()) { // scorro lista L1
		insert_ordered(L3, L1.getValue());
	}
	for (L2.moveToStart(); L2.currPos() < L2.length(); L2.next()) {
		insert_ordered(L3, L2.getValue());
	}
	L3.reverse(); // deve essere decrescente
	L3.moveToStart(); // rimetto cursore a inizio
}

int main(int argc, char** argv) {
	LList<Item> L1,	L2, L3;

	L1.append(Item(5));
	L1.append(Item(1));
	L1.append(Item(3));
	cout << "L1: "; lprint(L1); // lprint(List) stampa interamente la lista, con tanto di cursore e <> 

	L2.append(Item(10));
	L2.append(Item(12));
	L2.append(Item(7));
	L2.append(Item(2));
	cout << "L2: "; lprint(L2);

	fondiliste(L1, L2, L3);
	cout << "L3: "; lprint(L3);

	return 0;
}