#include "Multime_Pereche.h"


Multime_Pereche::Multime_Pereche(int n, Pereche* v): n(n),v(v)
{
    if(n<0)
        throw NegNrOfElements();
    std::cout<<"Constructor Multime\n";
}
Multime_Pereche::Multime_Pereche(const Multime_Pereche& aux): n(aux.n), v(aux.v)
{
    std::cout<<"Constructor copiere Multime\n";
}
Multime_Pereche::~Multime_Pereche()
{
    delete [] v;
    std::cout<<"Destructor Multime\n";
}
int Multime_Pereche::getNrElemente() const
{
    return this->n;
}
void Multime_Pereche::setElement(int i, Pereche p)
{
    this->v[i]=p;
}
Multime_Pereche& Multime_Pereche:: operator = (const Multime_Pereche& aux)
{
    if (this != &aux) {
        this->n=aux.n;
        v=new Pereche [n+1];
        for (int i = 1; i <=n; i++)
            this->v[i]=aux.v[i];
    }
    return *this;
}
int Multime_Pereche::operator ==(Multime_Pereche& aux)
{
    if (aux.n!=this->n)
        return 0;
    for(int i=1; i<=aux.n; i++)
        if(!(aux[i]==this->v[i]))
            return 0;
    return 1;
}
Pereche Multime_Pereche::operator [] ( int n) const
{
    return this->v[n];
}

std::istream& operator >> (std::istream& in, Multime_Pereche& v)
{
    int m;
    in>>m;
    v.n=m;
    for (int i=1; i<=v.n; i++) {
        Pereche p;
        in>>p;
        v.setElement(i,p);
    }
    return in;
}
std::ostream& operator << (std::ostream& out, const Multime_Pereche& v)
{
    for(int i=1; i<=v.getNrElemente(); i++) {
        out<<'(';
        out<<v[i];
        out<<") ";
    }
    return out;
}
