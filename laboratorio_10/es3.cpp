#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include <list>
#include <queue>

int main(int argc, char* argv[]) {
	list<queue<int>> lista_di_code; // lista di code di int
	queue<int> Q1, Q2, Q3, Q4;

	Q1.push(30);
	Q1.push(12);
	Q1.push(1);
	Q1.push(203);
	Q1.push(10);

	Q2.push(7);

	Q3.push(14);
	Q3.push(29);
	Q3.push(45);
	Q3.push(100);

	Q4.push(2);
	Q4.push(13);
	Q4.push(8);

	lista_di_code.push_back(Q1);
	lista_di_code.push_back(Q2);
	lista_di_code.push_back(Q3);
	lista_di_code.push_back(Q4);

	list<queue<int>>::iterator last = lista_di_code.end(); // iteratore che punta all'ultima coda
	list<queue<int>>::iterator penultimo = --last; // iteratore che punta alla penultima

	for (list<queue<int>>::iterator it = lista_di_code.begin(); it != penultimo; it++) { // il ciclo si ferma prima di arrivare all'ultimo elemento
		if ((*it).size() > 0) { // size() ritorna gli elementi nella coda
			int value = (*it).front(); // front() restituisce il primo elemento della coda senza eliminarlo
			(*it).pop(); // rimuove il primo elemento
			
			list<queue<int>>::iterator successivo = it; // crea iteratore che punta dove punta it
			++successivo; // sposta l'iteratore alla coda successiva
			(*successivo).push(value); // mette il valore estratto alla fine della coda dopo
		}
	}

	for (list<queue<int>>::iterator it = lista_di_code.begin(); it != lista_di_code.end(); it++) {
		while (!(*it).empty()) {
			cout << (*it).front() << " ";
			(*it).pop();
		}
		cout << endl;
	}

	return 0;
}
