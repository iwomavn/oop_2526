#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

float area(float radius);

int main() {
	float raggio, area_cerchio;
	cout << "Inserisci il raggio del cerchio: ";
	cin >> raggio;

	area_cerchio = area(raggio);
	cout << "L'area del cerchio e': " << area_cerchio << endl;

	return 0;
}

float area(float radius) {
	return PI * pow(radius, 2);
}