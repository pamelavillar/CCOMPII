#include <iostream>
using namespace std;
#include <string>

int suma(int n1, int n2, int mod) {
    int n;
    n = n1 + n2;
    n = n % mod;
    if (n < 0)
        n = mod + n;
    return n;

}
int multiplicacion(int n1, int n2, int mod) {
    int n;
    n = n1 * n2;
    n = n % mod;
    if (n < 0)
        n = mod + n;
    return n;

}

int inverso_multi(int n2, int mod) {
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

int main()
{
    int ex=1;
    int modulo;
    int n1, n2;
    int op;
    int re;

    while(ex!=0){
        cout << "Que operacion desea realizar?: " << endl;
        cout << "1.Suma, 2.Resta, 3.Multiplicacion, 4.Inverso multiplicativo " << endl;
        cin >> op;

        cout << "Introduzca el modulo: " << endl;
        cin >> modulo;
    

        cout << "Introduzca el primer numero: " << endl;
        cin >> n1;

        if (op !=4){
            cout << "Introduzca el segundo numero: " << endl;
            cin >> n2;

        }

        switch (op) {
        case 1:
            cout<<"Operacion ingresada: "<<n1<<" + "<<n2<<"mod"<<modulo<<endl;
            re = suma(n1, n2, modulo);
            break;
        case 2:
            cout<<"Operacion ingresada: "<<n1<<" - "<<n2<<"mod "<<modulo<<endl;
            re = suma(n1, -n2, modulo);
            break;
        case 3:
            cout<<"Operacion ingresada: "<<n1<<" x "<<n2<<"mod "<<modulo<<endl;
            re = multiplicacion(n1, n2, modulo);
            break;
        case 4:
            cout<<"\nOperacion ingresada: "<<n1<<"^(-1) "<<"mod "<<modulo<<endl;
            re = inverso_multi(n1, modulo);
            break;
        default:
            cout << "Operacion no valida" << endl;
            break;
        }


        cout << "\nEl resultado es: " << re << " mod " << modulo << endl;

        cout<< "\n¿Desea realizar otra operacion? 0.No, 1. Si" << endl;
        cin >> ex;
        }
    
    
    return 0;
}