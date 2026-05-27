#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std; // ricorda che va sempre prima di tutto questo usando le librerie del prof
// nell'esercizio 1 non devo modificare nulla qui, solo nel listTest.h!!! (includo solo listTest qui)
// #include "es1-listTest.h" // copialo in nuovo binarytree.h e lascia questo per es2

// nell'esercizio 2 non ho modificato listTest ma binary tree si quindi includo listTest normale
#include "listTest.h"

#include <iostream>

#include "lstack.h" // devi includere pure questi nel progetto sennò non va -> e i file inclusi dentro questi
#include "lqueue.h"

// class Node
template <typename E> class Node {
public:
    E data;      // Value for this node
    Node* lChildptr;
    Node* rChildptr;
    // Constructors
    Node(E dataNew)
    {
        data = dataNew;
        lChildptr = NULL;
        rChildptr = NULL;
    }
};

template<class T>
class BinaryTree
{
private:
    // Node<T>* root; 
    // ROOT LO SPOSTIAMO IN PUBLIC !!!

    // inserimento di un elemento nell'albero binario
    void Insert(T newData, Node<T>*& theRoot)
    {
        if (theRoot == NULL)
        {
            theRoot = new Node<T>(newData);
            return;
        }

        if (newData < theRoot->data)
            Insert(newData, theRoot->lChildptr);
        else
            Insert(newData, theRoot->rChildptr);
    }

    // attraversamento con stampa dell'albero 
    // permutando le righe si ottengono attraversamenti pre-order, post-order, in-order
    void traverse(Node<T>* theRoot)
    {
        if (theRoot != NULL)
        {
            traverse(theRoot->lChildptr);
            traverse(theRoot->rChildptr);
            cout << theRoot->data << " ";
        }
    }

    // attraversamento pre-order non ricorsivo
    void traverse_preorder_NR(Node<T>* theRoot)
    {
        LStack<Node<T>*> s;
        s.push(theRoot);
        while (s.length() != 0)
        {
            theRoot = s.pop();
            cout << theRoot->data << " ";
            if (theRoot->rChildptr != NULL) s.push(theRoot->rChildptr);
            if (theRoot->lChildptr != NULL) s.push(theRoot->lChildptr);
        }
    }

    // attraversamento level-order (chiamato anche in ampiezza)
    void traverse_levelorder_NR(Node<T>* theRoot)
    {
        LQueue<Node<T>*> q;
        q.enqueue(theRoot);
        while (q.length() != 0)
        {
            theRoot = q.dequeue();
            cout << theRoot->data << " ";
            if (theRoot->lChildptr != NULL) q.enqueue(theRoot->lChildptr);
            if (theRoot->rChildptr != NULL) q.enqueue(theRoot->rChildptr);
        }
    }

    // conta il numero di elementi nell'albero binario
    int count_elements(Node<T>* h)
    {
        if (h == NULL) return 0;
        return count_elements(h->lChildptr) + count_elements(h->rChildptr) + 1;
    }

    // restituisce l'altezza dell'albero
    int tree_height(Node<T>* h)
    {
        if (h == NULL) return -1;
        int u = tree_height(h->lChildptr), v = tree_height(h->rChildptr);
        if (u > v) return u + 1; else return v + 1;
    }

    Node<T>* max(T a[], int l, int r)
    {
        int m = (l + r) / 2;
        Node<T>* x = new Node<T>(a[m]);
        if (l == r) return x;
        x->lChildptr = max(a, l, m);
        x->rChildptr = max(a, m + 1, r);
        int u = x->lChildptr->data.key(), v = x->rChildptr->data.key();
        if (u > v)
            x->data = u; else x->data = v;
        return x;
    }

    int equal_structure(Node<T>* theRootA, Node<T>* theRootB) { // riceve le radici di due alberi da confrontare
        // due alberi hanno la stessa struttura se sono entrambi vuoti, o se sono entrambi non vuoti e i sottoalberi destro e sinistro hanno la stessa struttura

        if (theRootA == NULL) { // se il primo è vuoto
            if (theRootB != NULL) { // ma il secondo no
                return 0; // allora non hanno la stessa struttura
            }
        }
        else { // quindi A non è vuoto
            if (theRootB == NULL) { // ma B sì
                return 0;
            }

            int result;
            // ricorsione
            result = equal_structure(theRootA->lChildptr,
                theRootB->lChildptr);
            if (result == 0) {
                return 0;
            }

            result = equal_structure(theRootA->rChildptr,
                theRootB->rChildptr);
            if (result == 0) {
                return 0;
            }
        }

        return 1;
    }

    int equal(Node<T>* theRootA, Node<T>* theRootB) { // confronto, due alberi sono uguali se hanno la stessa struttura e tutte le coppie di nodi corrispondenti di A e B hanno lo stesso valore
        if (theRootA == NULL) { // se il primo è vuoto
            if (theRootB != NULL) { // ma il secondo no
                return 0; // allora non hanno la stessa struttura
            }
        }
        else { // quindi A non è vuoto
            if (theRootB == NULL) { // ma B sì
                return 0;
            }

            int result;
            
            if (theRootA->data.key() != theRootB->data.key()) {
                return 0;
            }
            
            result = equal(theRootA->lChildptr, theRootA->lChildptr);
            if (result == 0) {
                return 0;
            }

            result = equal(theRootA->rChildptr, theRootA->rChildptr);
            if (result == 0) {
                return 0;
            }
        }

        return 1;
    }

public:
    Node<T>* root; // root adesso è public
    BinaryTree()
    {
        root = NULL;
    }

    void AddItem(T newData)
    {
        Insert(newData, root);
    }

    void traverse()
    {
        traverse(root);
        //traverse_preorder_NR(root);
        //traverse_levelorder_NR(root);
    }

    int count()
    {
        return count_elements(root);
    }


    int height()
    {
        return tree_height(root);
    }


    void createTournament(T a[], int l, int r)
    {
        root = max(a, l, r);
    }

    Node<T>* get_root(){
        return root;
    }

    // la nuova funzione, devo rendere root pubblico (qua solo la versione pubblica che chiamerà la funzione privata ricorsiva)
    int equal_tree_structure(Node<T>* theRootB) {
        return equal_structure(root, theRootB); // chiama la funzione privata sopra
    }

    int equal_tree(BinaryTree<T>* treeB) {
        Node<T>* theRootB = treeB->get_root();
        return equal(root, theRootB);
    }

};

#endif