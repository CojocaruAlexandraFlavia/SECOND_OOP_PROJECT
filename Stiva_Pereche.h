#pragma once

#include "Multime_Pereche.h"
#include "WithoutElements.h"
#include "NegNrOfElements.h"
#include "Coada_Pereche.h"

class Stiva_Pereche: public Multime_Pereche
{
public:
    Stiva_Pereche(int n=0, Pereche*v=new Pereche[10]);
    Stiva_Pereche(const Stiva_Pereche&);
    virtual ~Stiva_Pereche();
    void Push(Pereche*);
    Pereche Pop();
    Stiva_Pereche& operator = (const Stiva_Pereche&);
    int operator == (Stiva_Pereche&);
    friend std::ostream& operator << (std::ostream&, const Stiva_Pereche&);
    friend std::istream& operator >> (std::istream&, Stiva_Pereche&);
};


