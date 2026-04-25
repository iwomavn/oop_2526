#ifndef LIBRO_H
#define LIBRO_H

#include <string>

using namespace std;

class Libro {
	private:
		string titolo;
		int pagine;
	public:
		Libro(string t = "", int p = 0) {
			titolo = t;
			pagine = p;
		}

		string getTitolo() const {
			return titolo;
		}

		int getPagine() const {
			return pagine;
		}

		void setTitolo(string t) {
			titolo = t;
		}

		void setPagine(int p) {
			pagine = p;
		}
};

#endif