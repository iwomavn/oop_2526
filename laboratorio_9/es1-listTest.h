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
#include "es1-bst.h"

static int maxkey = 1000;

class Item {
private:
  int id;
  string info;
public:
    Item(int i = maxkey, string inf = "") {
        id = i;
        info = inf;
    }
  
  int key() const { 
      return id; }

  int null() { // metodo che vede se l'id è vuoto (se è inizializzato a maxkey come nel costruttore)
      return id == maxkey;
  }

  void set_info(string inf) {
      info = inf;
  }

  string get_info() const {
      return info;
  }

  void show(ostream& os) const {
      os << id << ", " << info << endl;
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

inline void insert_ordered(List<Item>& L, const Item& it) {
    if (L.length() == 0)
    {
        L.insert(it);
        return;
    }
    for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
        if (it.key() <= L.getValue().key())
        {
            L.insert(it);
            return;
        }
        else if (it.key() == L.getValue().key()) {
            Item removed = L.remove();
            removed.set_info(removed.get_info() + it.get_info());
            L.insert(removed);
            return;
        }
    }
    L.append(it);
}

#endif

