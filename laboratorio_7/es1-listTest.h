// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string> // includo string perchè serve adesso
#include <time.h>  
using namespace std;

#include "list.h"

// crea classe Item (usiamo sempre listTest.h per la classe Item solitamente, basta modificarla come serve)
class Item {
private:
    string nome;
public:
  Item(string n = "") { // cambio costruttore ovviamente
      nome = n; 
  } 

  string key() const { 
      return nome; 
  }

  // devo fare anche operatore <, non fa altro che confrontare l'elemento con quello che passi, se il nome è minore (guarda ordine alfabetico) true, sennò false
  bool operator<(const Item& other) const {
      if (nome < other.key()) {
          return true;
      }
      else {
          return false;
      }
  }
};


// questo è un altro operatore, serve solo per fare print
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

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
  int currpos = L.currPos();

  L.moveToStart();

  cout << "< ";
  int i;
  for (i=0; i<currpos; i++) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << "| ";
  while (L.currPos()<L.length()) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}



#endif

