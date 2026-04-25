#include <iostream>
#include <string>
#include <ctime>
#define N 3

using namespace std;
int main() {
	int totale = 0, prezzo_medio;
	int libro_piu_costoso = 0, libro_piu_vecchio = 0;

	struct tipolibro {
		string titolo;
		string autore;
		int anno_edizione;
		int prezzo;
	};

	tipolibro libreria[N];

	cout << "Inserisci i dati dei libri: " << endl;
	for (int i = 0; i < N; i++) {
		cin >> libreria[i].titolo;
		cin >> libreria[i].autore;
		cin >> libreria[i].anno_edizione;
		libreria[i].prezzo = rand()%201;
		totale += libreria[i].prezzo;
	}

	prezzo_medio = totale / N;

	for (int i = 0; i < N; i++) {
		if (libreria[i].prezzo > libreria[libro_piu_costoso].prezzo) {
			libro_piu_costoso = i;
		}

		if (libreria[i].anno_edizione > libreria[libro_piu_vecchio].anno_edizione) {
			libro_piu_vecchio = i;
		}
	}
	cout << "Il prezzo medio dei libri e': " << prezzo_medio << endl;
	cout << "Il libro piu' costoso e': " << libreria[libro_piu_costoso].titolo << " di " << libreria[libro_piu_costoso].autore << " con prezzo " << libreria[libro_piu_costoso].prezzo << endl;
	cout << "Il libro piu' vecchio e': " << libreria[libro_piu_vecchio].titolo << " di " << libreria[libro_piu_vecchio].autore << " con anno di edizione " << libreria[libro_piu_vecchio].anno_edizione << endl;

	return 0;	
}