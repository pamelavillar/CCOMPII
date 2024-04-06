#include <iostream>
#include <string>
#include "modular.h"
using namespace std;

int main()
{
    int ex=1;
    int modulo;
    int n1, n2;
    int op;
    int re;

    while(ex!=0){
        Modular mo1;

        cout << "Que operacion desea realizar?: " << endl;
        cout << "1.Suma, 2.Resta, 3.Multiplicacion, 4.Inverso multiplicativo " << endl;
        cin >> op;

        cout << "Introduzca el modulo: " << endl;
        cin >> modulo;
        mo1.modulo = modulo;

        cout << "Introduzca el primer numero: " << endl;
        cin >> n1;
        mo1.n1 = n1;

        if (op !=4){
            cout << "Introduzca el segundo numero: " << endl;
            cin >> n2;
            mo1.n2 = n2;

        }

        switch (op) {
        case 1:
            cout<<"Operacion ingresada: "<<n1<<" + "<<n2<<"mod"<<modulo<<endl;
            re = mo1.suma(n1, n2, modulo);
            break;
        case 2:
            cout<<"Operacion ingresada: "<<n1<<" - "<<n2<<"mod "<<modulo<<endl;
            re = mo1.suma(n1, -n2, modulo);
            break;
        case 3:
            cout<<"Operacion ingresada: "<<n1<<" x "<<n2<<"mod "<<modulo<<endl;
            re = mo1.multiplicacion(n1, n2, modulo);
            break;
        case 4:
            cout<<"\nOperacion ingresada: "<<n1<<"^(-1) "<<"mod "<<modulo<<endl;
            re = mo1.inverso_multi(n1, modulo);
            if (re == 0){
                cout<<"El numero no tiene inverso"<<endl;
            }
            break;
        default:
            cout << "Operacion no valida" << endl;
            break;
        }


        cout << "\nEl resultado es: " << re << " mod " << mo1.modulo << endl;

        cout<< "\nDesea realizar otra operacion? 0.No, 1. Si" << endl;
        cin >> ex;
        }
    
    
    return 0;
}