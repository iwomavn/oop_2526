#ifndef MATRIX2X2_H
#define MATRIX2X2_H

template<class T>
class Matrix2x2 {
private:
	T* prima_riga = new int[2]();
	T* seconda_riga = new int[2]();

public:
	Matrix2x2(T* p, T* s) {
		prima_riga = p;
		seconda_riga = s;
	}

	~Matrix2x2() {
		delete[] prima_riga;
		delete[] seconda_riga;
	}

	T* get_prima_riga() { 
		return prima_riga; 
	}
	T* get_seconda_riga() { 
		return seconda_riga; 
	}

	void add(Matrix2x2& m) {
		T* prima_m = m.get_prima_riga();
		T* seconda_m = m.get_seconda_riga();

		for (int i = 0; i < 2; i++) {
			prima_riga[i] += prima_m[i];
			seconda_riga[i] += seconda_m[i];
		}
	}

};

#endif
