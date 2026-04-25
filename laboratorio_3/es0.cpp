#include "mobile.h"
#include "armadio.h"

int main() {
	Armadio a;
	Mobile m;

	a.setAltezza(200);
	a.setLarghezza(100);
	a.setNumeroAnte(4);
	cout << "Armadio: altezza = " << a.getAltezza() << ", larghezza = " << a.getLarghezza() << ", numero ante = " << a.getNumeroAnte() << endl;

	m.setAltezza(150);
	m.setLarghezza(80);
	cout << "Mobile: altezza = " << m.getAltezza() << ", larghezza = " << m.getLarghezza() << endl;

	return 0;
}