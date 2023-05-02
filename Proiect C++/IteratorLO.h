#pragma once

#include "LO.h"
typedef int TComparabil;
typedef TComparabil TElement;

class LO;

class IteratorLO {
    friend class LO;

private:
    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    explicit IteratorLO(const LO &lo);

    //contine o referinta catre containerul pe care il itereaza
    const LO &lo;

    /* aici e reprezentarea specifica a iteratorului */
    int pozitie; // pozitia pe care se afla elementul in tablou

public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElement element() const;
};


