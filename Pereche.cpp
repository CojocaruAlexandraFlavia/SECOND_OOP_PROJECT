#include "Pereche.h"

Pereche::Pereche(int a, int b)
{
    this->x=a;
    this->y=b;
    std::cout<<"Constructor Pereche\n";
}
Pereche::Pereche(const Pereche& aux)
{
    this->x=aux.x;
    this->y=aux.y;
    std::cout<<"Constructor copiere Pereche\n";
}
Pereche::~Pereche()
{
    x=y=0;
    std::cout<<"Destructor Pereche\n";
}
Pereche& Pereche:: operator = (const Pereche& p)
{
    if (this != &p) {
        this->x=p.x;
        this->y=p.y;
    }
        return *this;
}
int Pereche::operator ==(Pereche& aux)
{
    if (aux.x!=this->x || aux.y!=this->y)
        return 0;
    return 1;
}
std::istream& operator >> (std::istream& in, Pereche& aux)
{
    in>>aux.x>>aux.y;
    return in;
}
std::ostream& operator <<(std::ostream& out, const Pereche& aux)
{
    out<<'('<<aux.x;
    out<<" ";
    out<<aux.y<<')';
    return out;
}
