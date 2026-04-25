#include <iostream>
#include <cstdlib>

using namespace std;

// DA RIVEDERE

int main() {
	float xi, xi1;
	float a[3] = {35.0, 84.0, 100.0 };

	for (int i = 0; i < 3; i++)
	{
		xi1 = 1.0;
		do {
			xi = xi1;
			xi1 = 0.5 * (xi + a[i] / xi);
		} while (abs(sqrt(a[i]) - xi1) > 0.001);
		cout << "Valore finale di radice di " << a[i] << " :" << xi1 << endl;
	}
	return 0;
}