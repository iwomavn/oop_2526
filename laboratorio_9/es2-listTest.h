#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  

using namespace std;

#include "list.h"

typedef string keyA; // QUESTI SONO ALIAS DI TIPO: non sono altro che dei nuovi nomi per i due tipi string e int (keyA pippo = string pippo)
typedef int keyB;

static int maxkey = 1000000;
static string maxkeystr = "1000";

class ItemA {
private:
    string ufficio;
    keyA nominativo;
public:
    ItemA(string u = "", keyA k = maxkeystr) {
        ufficio = u;
        nominativo = k;
    }
  
    keyA key() const { 
      return nominativo; 
    }

    int null() {
        return nominativo == maxkeystr;
    }

    void set_ufficio(string u) {
        ufficio = u;
    }

    string get_ufficio() {
        return ufficio;
    }

    void show(ostream& os = cout) {
        os << ufficio << " " << nominativo << endl;
    }
};

class ItemB {
private:
    string nominativo;
    keyB numero;
public:
    ItemB(string n = "", keyB k = maxkey) {
        nominativo = n;
        numero = k;
    }

    keyB key() const {
        return numero;
    }

    int null() {
        return numero == maxkey;
    }

    void set_nominativo(string n) {
        nominativo = n;
    }

    string get_nominativo() {
        return nominativo;
    }

    void show(ostream& os = cout) {
        os << nominativo << " " << numero << endl;
    }
};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const ItemA& i)
  { return s << i.key(); }

inline ostream& operator<<(ostream& s, const ItemB& i)
{
    return s << i.key();
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
    ////L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}



#endif

