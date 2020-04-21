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
    Coada_Pereche C1, C2;
    C2.Push(p);
    for(int i=n; i>=1; i--){
        Pereche p1=this->v[i];
        C1.Push(&p1);
    }
    while(C1.getNrElemente()>0) {
        Pereche p2=C1.Pop();
        C2.Push(&p2);
    }

    Coada_Pereche aux=C1;
    C1=C2;
    C2=aux;

    this->n=n+1;
    for(int i=1; i<=C1.getNrElemente(); i++)
        this->v[i]=C1[getNrElemente()-i+1];

}
Pereche Stiva_Pereche::Pop()
{
    try {
        if(n<=0)
            throw (WithoutElements());
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    Coada_Pereche C;
    for(int i=getNrElemente();i>=1; i--){
        Pereche p=v[i];
        C.Push(&p);
    }
    if(C.getNrElemente()>0){
        this->n=n-1;
        Pereche top=C.Pop();
        for(int i=1;i<=C.getNrElemente();i++)
            this->v[getNrElemente()-i+1]=C.Pop();

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

    if (aux.n!=this->n)
        return 0;
    for(int i=1; i<=aux.n; i++)
        if(!(aux[i]==this->v[i]))
            return 0;
    return 1;
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
