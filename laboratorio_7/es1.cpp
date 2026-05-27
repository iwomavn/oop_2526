#include <iostream>
#include <cstdlib>
#include <string>
#include<time.h>

using namespace std;

#include "binary_tree.h"

int main(int argc, char** argv) {
	BinaryTree<Item> bt; // creo albero
	Item i("iman");
	bt.AddItem(i);

	Item m("malak");
	bt.AddItem(m);

	Item g("gabriele");
	bt.AddItem(g); // creo + aggiungo elementi

	bt.traverse(); // stampa in modo preorderù
	cout << endl << "Il numero di elementi del mio albero e': " << bt.count();
	cout << endl << "L'altezza del mio albero e': " << bt.height();

	return 0;
}