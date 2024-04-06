#include <iostream>
#include <string>
#include "modular.h"
using namespace std;

Modular::Modular(){
    modulo = 0;
    n1 = 0;
    n2 = 0;
}

int Modular::suma(int n1, int n2, int mod) {
    int n;
    n = n1 + n2;
    n = n % mod;
    if (n < 0)
        n = mod + n;
    return n;

}
int Modular::multiplicacion(int n1, int n2, int mod) {
    int n;
    n = n1 * n2;
    n = n % mod;
    if (n < 0)
        n = mod + n;
    return n;

}

int Modular::inverso_multi(int n2, int mod) {
    int u0 = 0;
    int u1 = 1;
    int r;
    int u2;
    int n1 = mod;
    while (true) {
        int q = n1 / n2;
        r = n1 % n2;
        u2 = u0 - q * u1;
        if (r == 1 || r == 0){
            if(r == 0){
                return 0;
            }
            break;
        }
        u0 = u1;
        u1 = u2;
        n1 = n2;
        n2 = r;
    }
    if (u2 < 0){
        u2 = mod + u2;
    }
    return u2;
   
}

