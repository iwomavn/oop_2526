#include <iostream>

using namespace std;

template <class T> 
T max2(T primo, T secondo) {
		if (primo > secondo) {
			return primo;
		} else {
			return secondo;
		}
	}

template <class T>
T max3(T primo, T secondo, T terzo) {
	T maggiore1 = max2(primo, secondo);
	return max2(maggiore1, terzo);
}

int main() {
	cout << "Il massimo tra " << 5 << ", " << 10 << " e " << 4 << " e': " << max3(5, 10, 4) << endl;
	cout << "Il massimo tra " << 2.5 << ", " << 3.7 << " e " << 1.2 << " e': " << max3(2.5, 3.7, 1.2) << endl;
	return 0;
}