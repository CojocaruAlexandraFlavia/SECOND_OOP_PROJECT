#include "Coada_Pereche.h"


Coada_Pereche::Coada_Pereche(int n, Pereche*v): Multime_Pereche(n,v)
{
    std::cout<<"Constructor Coada\n";
}
Coada_Pereche::Coada_Pereche(const Coada_Pereche& aux):Multime_Pereche(aux)
{
    std::cout<<"Constructor de copiere Coada\n";
}
Coada_Pereche::~Coada_Pereche()
{
    std::cout<<"Destructor Coada\n";
}
void Coada_Pereche::Push(Pereche* p)
{
    this->n=n+1;
    this->v[n]=*p;
}
Pereche Coada_Pereche::Pop()
{
    try {
        if(n<=0)
            throw WithoutElements();
    } catch(std::exception&e) {
        std::cout << e.what() << "\n";
    }
    if(n>0) {
        Pereche inc=v[1];
        for(int i=1; i<n; i++)
            v[i]=v[i+1];
        this->n=n-1;
        return inc;
    }
}
Coada_Pereche& Coada_Pereche:: operator =(const Coada_Pereche& aux)
{
    if (this != &aux)
        this->Multime_Pereche::operator = (aux);
    return *this;
}
int Coada_Pereche:: operator == (Coada_Pereche& aux)
{
    if (aux.n!=this->n)
        return 0;
    for(int i=1; i<=aux.n; i++)
        if(!(aux[i]==this->v[i]))
            return 0;
    return 1;
}
std::istream& operator >> (std::istream& in, Coada_Pereche& v)
{
    int m;
    in>>m;
    try {
        if(m<=0)
            throw NegNrOfElements();
    } catch(std::exception &e) {
        std:: cout<<e.what()<<"\n";
    }
    v.n=m;
    if(m>0)
        v.v=new Pereche[m+1];
    for (int i=1; i<=v.n; i++) {
        Pereche p;
        in>>p;
        v.setElement(i,p);
    }
    return in;
}
std::ostream& operator << (std::ostream& out, const Coada_Pereche& v)
{
    for(int i=1; i<=v.getNrElemente(); i++) {
        out<<v[i];
        out<<" ";
    }
    return out;
}

