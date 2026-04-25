#include <iostream>
#include "matrix2x2.h"

using namespace std;

int main() {
	Matrix2x2<int> mat(new int[2] { 20, 10 }, new int[2] { 30, 12 });
	Matrix2x2<int> mat2(new int[2] { 20, 10 }, new int[2] { 30, 12 });

	mat.add(mat2);

	cout << mat.get_prima_riga()[0] << "| " << mat.get_prima_riga()[1] << "\n" << mat.get_seconda_riga()[0] << "| " << mat.get_seconda_riga()[1];

	return 0;
}
