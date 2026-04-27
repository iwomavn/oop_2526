#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> 
using namespace std;

#include "list.h"

// devo fare la classe prodotto
class Prodotto {
private:
  string codice;
  string nome_prodotto;
  int quantita;
public:
  Prodotto() {}
  
  Prodotto(string c, string n, int q) {
      codice = c;
      nome_prodotto = n;
      quantita = q;
  }
  
  string key() const { 
      return codice; 
  }

  string get_nome_prodotto() const {
      return nome_prodotto;
  }

  int get_quantita() const {
      return quantita;
  }

  void set_quantita(int q) {
      quantita = q;
  }
};

struct ricetta {
    int numero_piatto;
    string descrizione;
    string primo_ingrediente;
    int quantita_primo;
    string secondo_ingrediente;
    int quantita_secondo;
};

class Item {
private:
    ricetta recipe;
public:
    Item() {}
    Item(ricetta r) {
        recipe = r;
    }
    ricetta key() const {
        return recipe;
    }
};


inline ostream& operator<<(ostream& s, const Prodotto& i){ 
    return s << "(" << i.key() << " " << i.get_nome_prodotto() << " " << i.get_quantita() << ")";
}

inline ostream& operator<<(ostream& s, const Item& i) {
    return s << "(" << i.key().numero_piatto << " " << i.key().descrizione << " " 
        << i.key().primo_ingrediente << " " << i.key().quantita_primo << " "
        << i.key().secondo_ingrediente << " " << i.key().quantita_secondo << " " << ")";
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
    cout << L.getValue() << endl;
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