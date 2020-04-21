#pragma once

#include "Multime_Pereche.h"
#include "WithoutElements.h"
#include "NegNrOfElements.h"

class Coada_Pereche:public  Multime_Pereche
{
public:
    Coada_Pereche(int n=0, Pereche*v=new Pereche[10]);
    Coada_Pereche(const Coada_Pereche&);
    virtual ~Coada_Pereche();
    void Push(Pereche*);
    Pereche Pop();
    Coada_Pereche& operator =(const Coada_Pereche&);
    int operator == (Coada_Pereche&);
    friend std::istream& operator >> (std::istream&, Coada_Pereche&);
    friend std::ostream& operator <<(std::ostream&, const Coada_Pereche&);

};


