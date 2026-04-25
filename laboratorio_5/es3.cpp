using namespace std;

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> 

#include "link.h"
#include "lstack.h"
#include "LStackTest.h"

const int N = 10;
int main() {
	LStack<Item> SFattoriale;
	int fattoriale = 1;

	for (int i = N; i >= 1; i--) {
		SFattoriale.push(Item(i));
	}

	while (SFattoriale.length() > 0) {
		fattoriale = fattoriale * (SFattoriale.pop()).key();
	}

	cout << "Il fattoriale di " << N << " e': " << fattoriale << endl;

	return 0;
}