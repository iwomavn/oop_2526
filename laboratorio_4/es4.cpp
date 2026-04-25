using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "link.h"
#include "list.h"
#include "llist.h"

#include "ListTest.h"

void modify_lista(List<Item>& l) {
	Item it, it_prev;
	for (l.moveToPos(l.length()-1); l.currPos() > 0; l.prev()) {
		l.prev();
		it_prev = l.getValue();

		l.next();
		it = l.getValue();

		l.remove();
		Item prodotto(it.key() * it_prev.key());
		l.insert(prodotto);
	}

}

int main() {
	LList<Item> lista;
	/* srand(time(nullptr));
	for (int i = 0; i < 5; i++) {
		lista.append(Item(rand() % 100));
	 */

	lista.append(Item(4));
	lista.append(Item(6));
	lista.append(Item(2));
	lista.append(Item(3));
	lista.append(Item(9));

	cout << "Lista: ";
	lprint(lista);

	modify_lista(lista);
	cout << "Lista modificata: ";
	lprint(lista);

	return 0; 
}