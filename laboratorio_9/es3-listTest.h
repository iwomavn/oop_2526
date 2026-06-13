// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"

static int maxkey = 10000000;
typedef int Key;

class Item {
private:
    Key matricola;
    string nominativo;
    int voto;
    string email;
public:
  Item(Key m = maxkey, string n = "", int v = 0, string e = " ") { 
      matricola = m;
      nominativo = n;
      voto = v;
      email = e;
  }
 
  Key key() const { 
      return matricola; 
  }

  int null() {
      return matricola == maxkey;
  }

  string get_nome() {
      return nominativo;
  }

  void set_nome(string n) {
      nominativo = n;
  }
  
  int get_voto() {
      return voto;
  }

  void set_voto(int v) {
      voto = v;
  }

  void show(ostream& os = cout) {
      os << matricola << endl;
  }
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

