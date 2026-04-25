#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int collega1[31], collega2[31];
	int giorno;

	//inizializza i due vettori a 0
	for (int i = 0; i < 31; i++) {
		collega1[i] = 0;
		collega2[i] = 0;
	}

	cout << "Collega 1, inserisci i giorni in cui sei libero: " << endl;
	do {
		cout << "Inserisci il giorno libero (1-31) o zero per terminare: " << endl;
		cin >> giorno;
		
		if (giorno > 0 && giorno <= 31)
			collega1[giorno - 1] = 1;

	} while (giorno != 0);


	cout << "Collega 2, inserisci i giorni in cui sei libero: " << endl;
	do
	{
		cout << "Inserisci il giorno libero (1-31) o zero per terminare: " << endl;
		cin >> giorno;
		
		if (giorno > 0 && giorno <= 31)
			collega2[giorno - 1] = 1;

	} while (giorno != 0);

	for (int i = 0; i < 31; i++) {
		if ((collega1[i] == 1) && (collega2[i] == 1))
			cout << endl << "Il giorno " << i + 1 << " e' libero per entrambi" << endl;
	}
	return 0;
}