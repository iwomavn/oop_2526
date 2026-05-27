#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

#include "es4-binary_tree.h"

int main(int argc, char** argv) {

    cout << "Creazione albero..." << endl;

    BinaryTree<Item>* bt = new BinaryTree<Item>;

    Item a(50);
    bt->AddItem(a);

    Item b(30);
    bt->AddItem(b);

    Item c(70);
    bt->AddItem(c);

    Item d(20);
    bt->AddItem(d);

    Item e(40);
    bt->AddItem(e);

    Item f(60);
    bt->AddItem(f);

    Item g(80);
    bt->AddItem(g);

    cout << "Attraversamento albero:" << endl;
    bt->traverse();

    cout << endl;
    cout << "Adesso elimino l'albero..." << endl;

    delete bt; // qui viene chiamato il distruttore

    cout << "Distruttore eseguito correttamente!" << endl;

    return 0;
}