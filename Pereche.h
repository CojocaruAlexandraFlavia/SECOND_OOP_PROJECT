#pragma once
#include<iostream>

class Pereche
{
    int x, y;
public:
    Pereche(int x=0, int y=0);
    Pereche(const Pereche&);
    virtual ~Pereche();
    friend std::istream& operator >>(std::istream&, Pereche&);
    friend std::ostream& operator <<(std::ostream&, const Pereche&);
    Pereche& operator =(const Pereche&);
    int operator ==(Pereche&);
};


