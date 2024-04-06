#include <iostream>
#include <string>
#include "modular.h"
#include "encriptador.h"
using namespace std;

int main()
{   
    int re=0;
    int clave_privada=0;
    int clave_publica=0;
    string ruta_archivo="";
    cout<<"Holaaa!! Que deseas hacer? 1. Encriptar, 2. Desencriptar: ";
    cin>>re;

    Encriptador encriptador;

    if (re==1){
    
        cout<<"\nIngrese el documento a encriptar: ";
        cin>>ruta_archivo;
        encriptador.ruta_archivo=ruta_archivo;

        while(true){
            cout<<"\n\nIngrese su clave privada: ";
            cin>>clave_privada;
            encriptador.clave=clave_privada;

            if (encriptador.obtener_clave_publica(clave_privada)!=0){
            cout<<"\n\nSu clave publica: ";
            cout<<encriptador.obtener_clave_publica(clave_privada);
            break;

            }
            else{
                cout<<"\n\nError al obtener la clave publica, ingrese otra clave privada."<<endl;
            }

        }
 
        encriptador.encriptar();
        cout<<"\n\nArchivo encriptado con exito"<<endl;

    }
    else if (re==2){
        
        cout<<"\nIngrese el documento a desencriptar: ";
        cin>>ruta_archivo;
        encriptador.ruta_archivo=ruta_archivo;

        cout<<"\nIngrese su clave publica: ";
        cin>>clave_publica;
        encriptador.clave=clave_publica;

        encriptador.encriptar();
        cout<<"\n\nArchivo desencriptado con exito"<<endl;

    }
    return 0;
}