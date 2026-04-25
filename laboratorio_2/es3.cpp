#include "money.h"
#include "creditcard.h"

int main() {
	CreditCard card("Mario Rossi", "1234 5678 9012 3456");
	string item;
	int euros_charge, cents_charge;

	ifstream file("charges.txt");
	if (file.is_open()) {
		while (file >> item >> euros_charge >> cents_charge) {
			card.charge(item, euros_charge, cents_charge);
		}
		file.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}

		cout << "Total charges: " << card.get_totalcharges() << endl;	
	return 0;
} 
