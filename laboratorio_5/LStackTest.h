#ifndef LSTACKTEST_H
#define LSTACKTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  

using namespace std;

#include "lstack.h"

// Your basic int type as an object.
class Item {
private:
  int val;
public:
  Item(int input=0) { val = input; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return val; }
  void setVal(int v) { val = v; }
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
  { return s << i.key(); }



// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}


// Print out the stack
template <typename E>
void Lstackprint(LStack<E>& S) {
	LStack<E> Stemp;
	while (S.length()>0)
	{
		E popped = S.pop();
		cout << popped << " ";
		Stemp.push(popped);
	}
	while (Stemp.length()>0)
	{
		E popped = Stemp.pop();
		S.push(popped);
	}
}

// sposta stack1 in stack2
template <typename E>
void LstackTransfer(LStack<E>& S1, LStack<E>& S2) {
	LStack<E> Stemp; // stack temporaneo
	while (S1.length()>0) // finchè c'è ancora qualcosa nello stack
	{
		E popped = S1.pop(); // elimina il primo elemento della lista e lo ritorna (pop)
		Stemp.push(popped); // mette l'elemento appena poppato come primo dello stack temporaneo (push)
	}
	// abbiamo preso gli elementi di S1 partendo dal primo fino all'ultimo e gli abbiamo salvati in uno stack temporaneo ma al contrario

	while (Stemp.length()>0) // finchè c'è ancora qualcosa nello stack temporaneo
	{
		E popped = Stemp.pop(); // prendo primo elementp
		S1.push(popped); // li risalvo negli stack
		S2.push(popped);
	}
}

#endif

