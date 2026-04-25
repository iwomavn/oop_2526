#ifndef ARMADIO_H
#define ARMADIO_H

#include "mobile.h"

class Armadio : public Mobile {
private:
	int numeroAnte;
public:
	Armadio() {
		numeroAnte = 0;
	}

	void setNumeroAnte(int n) {
		numeroAnte = n;
	}

	int getNumeroAnte() {
		return numeroAnte;
	}
};

#endif 
 
