#include <iostream>

using namespace std;

int main() {
	const int N = 5;
	int a[N] = { 1, 2, 4, 8, 16 }, b[N] = { 0, -3, 6, -9, 12 }, c[N], d[N];

	// il vettore c è la somma incrociata di a e b
	for (int i = 0; i < N; i++) {
			c[i] = a[i] + b[N - i - 1]; 
	}

	// il vettore d è 1 se a[i] > b[i], altrimenti è 0
	for (int i = 0; i < N; i++) {
		if (a[i] > b[i]) {
			d[i] = 1; 
		}
		else {
			d[i] = 0; 
		}
	}

	// stampo i vettori a, b, c e d
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i < N; i++) {
		cout << c[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	
	return 0;
}