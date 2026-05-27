// la funzione equal_tree_structure la mettiamo direttamente nella classe binary_tree.h (nelle funzioni membro pubbliche). In questo caso usiamo la classe listTest classica, senza modificarla

#include <iostream>
#include <cstdlib>
#include <string>
#include<time.h>

using namespace std;

#include "es2-binary_tree.h"

int main(int argc, char** argv) {
	BinaryTree<Item>* bt1 = new BinaryTree<Item>;
	Item a(44);
	bt1->AddItem(a);

	Item b(89);
	bt1->AddItem(b);

	Item c(22);
	bt1->AddItem(c);

	Item d(39);
	bt1->AddItem(d);
	bt1->traverse();

	BinaryTree<Item>* bt2 = new BinaryTree<Item>;
	Item e(2);
	bt2->AddItem(e);

	Item f(3);
	bt2->AddItem(f);

	Item g(4);
	bt2->AddItem(g);

	Item h(5);
	bt2->AddItem(h);
	cout << endl;
	bt2->traverse();

	cout << endl;
	int result = bt1->equal_tree_structure(bt2->root);
	if (result) {
		cout << "Hanno la stessa struttura";
	}
	else {
		cout << "Non hanno la stessa struttura";
	}

	return 0;
}