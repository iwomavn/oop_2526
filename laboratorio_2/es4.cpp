#include "persona.h"

int main() {
	Persona p1("Mario", "Rossi", 30);
	// Persona p2("Luigi", "Verdi", 25);
	Persona p2("Mario", "Rossi", 30);

	ofstream file("output.txt");
	
	if (file.is_open()) {
		if (p1 != p2) {
			file << "DIVERSI";
		}
		else {
			file << "UGUALI";
		}
	}
	else {
		cout << "Impossibile aprire il file." << endl;
	}
	return 0;
}