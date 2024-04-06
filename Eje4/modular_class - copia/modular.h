#ifndef MODULAR_H
#define MODULAR_H

#include <iostream>
#include <string>
using namespace std;

class Modular{
    public: 

        int modulo;
        int n1;
        int n2;
        Modular();
        int modu(int,int);
        int suma(int,int,int);
        int multiplicacion(int,int,int);
        int inverso_multi(int,int);
};
#endif // MODULAR_H