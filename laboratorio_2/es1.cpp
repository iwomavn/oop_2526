#include "libro.h"
#include <iostream>

int main() {
	Libro l;
	Libro l2("manuale cremonese", 900);
	l.setTitolo("manuale di programmazione");
	l.setPagine(1000);

	cout << l.getTitolo() << " " << l.getPagine() << endl;
	cout << l2.getTitolo() << " " << l2.getPagine() << endl;
	return 0;
} 