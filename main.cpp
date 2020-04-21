#include <iostream>
#include "Pereche.h"
#include "Multime_Pereche.h"
#include "Stiva_Pereche.h"
#include "Coada_Pereche.h"


int main()
{
    Pereche* V;
    try {
        Stiva_Pereche s(-1,V);
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    Pereche P1(1,2), P2(6,7);
    int n;
    std::cin>>n;
    for(int i=0; i<n; i++ ) {
        Stiva_Pereche S;
        std::cin>>S;
        std::cout<<"Stiva este:"<<S<<"\n";
    }
    for(int i=0; i<n; i++){
        Coada_Pereche C;
        std::cin>>C;
        std::cout<<"Coada este:"<<C<<"\n";
    }
    std::cout<<"\n";
    Stiva_Pereche S;
    S.Push(&P1);
    std::cout<<"Stiva dupa push I este: "<<S<<"\n";
    S.Push(&P2);
    std::cout<<"Stiva dupa push II este: "<<S<<"\n";
    S.Pop();
    std::cout<<"Stiva dupa pop I este: "<<S<<"\n";
    S.Pop();
    std::cout<<"Stiva dupa pop II este: "<<S<<"\n";
    S.Pop();
    std::cout<<"Stiva dupa pop III este: "<<S<<"\n";
    Coada_Pereche C;
    C.Push(&P1);
    std::cout<<"Coada dupa push I este: "<<C<<"\n";
    C.Push(&P2);
    std::cout<<"Coada dupa push II este: "<<C<<"\n";
    C.Pop();
    std::cout<<"Coada dupa pop I este: "<<C<<"\n";
    C.Pop();
    std::cout<<"Coada dupa pop II este: "<<C<<"\n";
    C.Pop();
    return 0;
}
