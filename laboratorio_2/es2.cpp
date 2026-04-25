#include "persona.h"

int main() {
	Persona people[3];

	Persona mario("Mario", "Rossi", 30);
	Persona luigi("Luigi", "Verdi", 28);
	Persona peach("Peach", "Rosa", 25);

	cout << mario.getInformation() << endl;
	cout << luigi.getInformation() << endl;
	cout << peach.getInformation() << endl << endl;

	people[0] = mario;
	people[1] = luigi;
	people[2] = peach;

	for (int i = 0; i < 3; i++) {
		people[i].setCognome("Bianchi");
		cout << people[i].getInformation() << endl;
	}

	return 0;
} 