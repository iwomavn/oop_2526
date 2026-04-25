#include "money.h"
#include "creditcard.h"

Money operator+(Money m1, Money m2) {
	int total_cents = m1.get_cents() + m2.get_cents();
	int total_euros = m1.get_euros() + m2.get_euros() + (total_cents / 100); // tanto total_cents/100 prende solo l'intero
	total_cents = total_cents % 100; // lascio solo i centesimi che non formano un euro
	return Money(total_euros, total_cents);
}

ostream& operator<<(ostream& os, Money m) {
	cout << m.get_euros() << ", " << m.get_cents() << " euros";
	return os;
};

void CreditCard::charge(string item, int e, int c) {
	Money spesa(e, c);
	cout << "Operation: " << item << "for " << e << ", " << c << endl;
	totale_pagamenti = totale_pagamenti + spesa;
}

void CreditCard::print() {
	cout << nome_proprietario << ", " << numero_carta << endl;
}