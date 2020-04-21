#pragma once

#include <iostream>
#include "Pereche.h"
#include "NegNrOfElements.h"

class Multime_Pereche
{
   protected:
       int n;
       Pereche* v;
   public:
       Multime_Pereche(int n=0, Pereche*v=new Pereche[10] );
       Multime_Pereche(const Multime_Pereche&);
       virtual ~Multime_Pereche();
       virtual void Push(Pereche*)=0;
       virtual Pereche Pop()=0;
       int getNrElemente() const;
       void setElement(int, Pereche);
       friend std::istream& operator >>(std::istream&, Multime_Pereche&);
       friend std::ostream& operator <<(std::ostream&,const  Multime_Pereche&);
       Multime_Pereche& operator = (const Multime_Pereche& );
       int operator == (Multime_Pereche&);
       Pereche operator [] ( int  ) const;
       };


