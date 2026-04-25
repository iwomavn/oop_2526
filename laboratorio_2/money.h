#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <ostream>
#include <string>
#include <fstream>

using namespace std;

class Money {
	private:
		int euros;
		int cents;
	public:
		Money(int e = 0, int c = 0) {
			euros = e;
			cents = c;
		}

		int get_euros() {
			return euros;
		}

		void set_euros(int e) {
			euros = e;
		}

		int get_cents() {
			return cents;
		}

		void set_cents(int c) {
			cents = c;
		}
};

Money operator+(Money m1, Money m2);
ostream& operator<<(ostream& os, Money m);

#endif 