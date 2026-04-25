#include <iostream>

using namespace std;
int main() {
	float prezzo, aumento;

	cout << "Inserisci il prezzo: ";
	cin >> prezzo;

	if (prezzo > 100) {
		prezzo = prezzo * 0.65;
		aumento = prezzo * 0.22;
		prezzo += aumento;
	}

	cout << "Il prezzo finale e': " << prezzo << endl;

	return 0;
}