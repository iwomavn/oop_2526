#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"
#include "lstack.h"

class Item {
private:
    int numero_biglietto;
    string nome;
    string cognome;
public:
  Item() {}
  Item(int nb, string n, string c ) {
      numero_biglietto = nb;
      nome = n;
      cognome = c;
  }
 
  int key() const { 
      return numero_biglietto; 
  }

  string get_nome() const {
      return nome;
  }

  string get_cognome() const {
      return cognome;
  }
};

class Premio {
private:
    string nome_premio;
    float valore;
public:
    Premio() {}
    Premio(string n, float v) {
        nome_premio = n;
        valore = v;
    }

    string get_nome() const {
        return nome_premio;
    }

    float get_valore() const {
        return valore;
    }
};

inline ostream& operator<<(ostream& s, const Item& i)
  { return s << i.key() << " " << i.get_cognome() << " " << i.get_nome() << endl; 
}

inline ostream& operator<<(ostream& s, const Premio& i)
{
    return s << i.get_nome() << " " << i.get_valore() << endl;
}
  
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

template <typename E>
void Lstackprint(LStack<E>& S) {
    LStack<E> Stemp;
    while (S.length() > 0)
    {
        E popped = S.pop();
        cout << popped << " ";
        Stemp.push(popped);
    }
    while (Stemp.length() > 0)
    {
        E popped = Stemp.pop();
        S.push(popped);
    }
}


#endif

