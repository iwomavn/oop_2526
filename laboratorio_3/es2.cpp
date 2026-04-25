#include <iostream>

using namespace std;

template <typename T> 
T most_common(T* A, int size) {
	int frequenza_max = 0, counter = 0;
	T comune = A[0];

	for (int i = 0; i < size; i++) {
		counter = 0;
		for (int j = 0; j < size; j++) {
			if (A[j] == A[i]) {
				counter++;
			}
		}
		if (counter > frequenza_max) {
			frequenza_max = counter;
			comune = A[i];
		}
	}
	return comune;
}

int main() {
	int vett[7] = {0, 3, 4, 3, 4, 7, 4};

	cout << "Il numero piu' comune dell'array: " << most_common(vett, 7) << endl;

	return 0;
}