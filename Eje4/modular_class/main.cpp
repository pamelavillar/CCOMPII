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
    cout<<"Holaaa!! Que deseas hacer? 1. Encriptar, 2. Desencriptar";
    cin>>re;

    if (re==1){
        Encriptador encriptador;

        cout<<"\nIngrese el documento a encriptar: ";
        cin>>ruta_archivo;
        encriptador.ruta_archivo=ruta_archivo;

        cout<<"\n\nIngrese su clave privada: ";
        cin>>clave_privada;
        encriptador.clave=clave_privada;

        string texto_original = encriptador.cargarArchivo();

        if (!texto_original.empty()) {
            string texto_encriptado = encriptador.encriptar(texto_original, clave_privada);
            encriptador.guardar_encriptado(texto_encriptado);
        }
    }
    return 0;
}