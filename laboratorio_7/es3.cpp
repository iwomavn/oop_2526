#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

#include "es3-binary_tree.h"

int main(int argc, char** argv) {

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

    cout << "Albero 1:" << endl;
    bt->traverse();
    cout << endl;

    BinaryTree<Item>* bt2 = new BinaryTree<Item>;

    Item h(51);
    bt2->AddItem(h);

    Item i(90);
    bt2->AddItem(i);

    Item j(88);
    bt2->AddItem(j);

    Item k(26);
    bt2->AddItem(k);

    Item m(49);
    bt2->AddItem(m);

    Item n(60);
    bt2->AddItem(n);

    //Item o(89);
    //bt2->AddItem(o);

    cout << "Albero 2:" << endl;
    bt2->traverse();
    cout << endl;

    int result = bt->equal_tree(bt2);
    if (result) {
        cout << "Gli alberi sono uguali";
    }
    else {
        cout << "Gli alberi sono diversi";
    }

    return 0;
}