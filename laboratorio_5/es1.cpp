using namespace std;

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> 

#include "link.h"
#include "lstack.h"
#include "es1-LStackTest.h"

template<typename E> 
void Reverse(LStack<E>& S) {
	LStack<E> tmp;
	E popped;

	while (S.length() > 0) {
		popped = S.pop();
		tmp.push(popped);
	}

	LstackTransfer(tmp, S);
};

int main() {
	LStack<Item> myStack;
	myStack.push(Item(1));
	myStack.push(Item(2));
	myStack.push(Item(3));
	myStack.push(Item(4));
	cout << "Ecco lo stack originale: ";
	Lstackprint(myStack);

	Reverse(myStack);
	cout << "Ecco lo stack reversed: ";
	Lstackprint(myStack);

	return 0;
}