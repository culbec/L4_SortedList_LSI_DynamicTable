#pragma once

#include "IteratorLO.h"

class IteratorLO;

typedef int TComparabil;
typedef TComparabil TElement;

typedef bool (*Relatie)(TElement, TElement);

#define NULL_TELEMENT (-1)

class LO {
private:
    friend class IteratorLO;

private:
    /*
     * Reprezentare: Vector Dinamic + LSI
     * - fiecare element din vector se va identifica printr-un iterator si un element de tip Node
     */

    /*
     * Nodul -> elementul propriu-zis din
     */
    class Node {
    public:
        TElement elem; // informatia relevanta
        int next; // pozitia urmatorului element

        Node() : elem(-1), next(-1) {}

        Node(TElement, int);
    };

    Relatie relatie; // relatia intre elemente

    int capacitate; // capacitatea vectorului dinamic
    int lungime; // lungimea vectorului dinamic
    Node *elems; // lista propriu zisa de elemente

    int first; // referinta catre primul element din lista
    int primLiber; // pozitia primului element liber din lista

    /*
     * Functie de alocare a unui nod
     * Returneaza un iterator peste elementul unde ar trebui sa adaugam urmatorul nod
     *
     * Complexitate: Theta(1)
     */
    IteratorLO alocaNod();

    /*
     * Functie de dealocare a unui nod
     * Reface legaturile intre noduri si sterge nodul de sters
     *
     * Complexitate: Theta(pozitie_nod)
     */
    void dealocaNod(IteratorLO &poz);

    /*
     * Functie de redimensionare a vectorului dinamic
     * Mareste capacitatea vectorului
     *
     * Complexitate: Theta(n)
     */
    void redim();

public:
    // constructor
    explicit LO(Relatie r);

    // returnare dimensiune
    int dim() const;

    // verifica daca LO e vida
    bool vida() const;

    // prima pozitie din LO
    IteratorLO prim() const;

    // returnare element de pe pozitia curenta
    //arunca exceptie daca poz nu e valid
    TElement element(IteratorLO &poz) const;

    // adaugare element in LO a.i. sa se pastreze ordinea intre elemente
    void adauga(TElement e);

    // sterge element de pe o pozitie poz si returneaza elementul sters
    //dupa stergere poz e pozitionat pe elementul de dupa cel sters
    //arunca exceptie daca poz nu e valid
    TElement sterge(IteratorLO &poz);

    // cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
    IteratorLO cauta(TElement e) const;

    //destructor
    ~LO();

};
