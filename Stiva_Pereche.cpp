#include "Stiva_Pereche.h"


Stiva_Pereche::Stiva_Pereche(int n, Pereche*v): Multime_Pereche(n,v)
{
    std::cout<<"Constructor Stiva\n";
}
Stiva_Pereche::Stiva_Pereche(const Stiva_Pereche& aux): Multime_Pereche(aux)
{
    std::cout<<"Constructor de copiere Stiva\n";
}
Stiva_Pereche::~Stiva_Pereche()
{
    std::cout<<"Destructor Stiva\n";
}
void Stiva_Pereche::Push(Pereche* p)
{
    Coada_Pereche C;
    for(int i=1;i<=n;i++)
        C.Push(&v[i]);
    C.Push(p);
    this->n=n+1;
    for(int i=1;i<=n;i++)
        this->v[i]=C.Pop();

}
Pereche Stiva_Pereche::Pop()
{
    try {
        if(n<=0)
            throw (WithoutElements());
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    Coada_Pereche C1(this->n, this->v), C2;
    if(C1.getNrElemente()>0) {
        while(C1.getNrElemente()>1) {
            Pereche p=C1.Pop();
            C2.Push(&p);
        }
        Pereche top=C1.Pop();

        Coada_Pereche aux=C1;
        C1=C2;
        C2=C1;

        this->n=n-1;
        for(int i=1; i<=n; i++)
            this->v[i]=C1.Pop();
        return top;
    }
}
Stiva_Pereche& Stiva_Pereche::operator = (const Stiva_Pereche& w)
{
    if (this != &w)
        this->Multime_Pereche::operator = (w);
    return *this;
}
int Stiva_Pereche::operator == (Stiva_Pereche& aux)
{

    this->Multime_Pereche::operator == (aux);
}
std::istream& operator >> (std::istream& in, Stiva_Pereche& s)
{
    int m;
    in>>m;
    try {
        if(m<=0) {
            throw NegNrOfElements();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    s.n=m;
    if(m>0)
            s.v=new Pereche[m+1];
    for (int i=1; i<=m; i++) {
        Pereche p;
        in>>p;
        s.setElement(i,p);
    }
    return in;
}
std::ostream& operator << (std::ostream& out, const Stiva_Pereche& v)
{
    for(int i=1; i<=v.getNrElemente(); i++) {
        out<<v[i];
        out<<" ";
    }
    return out;
}
