#ifndef MOBILE_H
#define MOBILE_H

#include <iostream>
using namespace std;

class Mobile {
private:
	int altezza;
	int larghezza;
public:
	Mobile(int a = 0, int l = 0) {
		altezza = a;
		larghezza = l;
	}

	void setAltezza(int a) {
		altezza = a;
	}

	void setLarghezza(int l) {
		larghezza = l;
	}

	int getAltezza() {
		return altezza;
	}
	
	int getLarghezza() {
		return larghezza;
	}   
};

#endif

