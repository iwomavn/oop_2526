#include "money.h"

class CreditCard {
	private:
		string nome_proprietario;
		string numero_carta;
		Money totale_pagamenti;
	public:
		CreditCard(string nome, string numero) {
			nome_proprietario = nome;
			numero_carta = numero;
			totale_pagamenti = Money(0, 0);
		}

		Money get_totalcharges() {
			return totale_pagamenti;
		}

		void print();
		void charge(string item, int e, int c);
		
};  