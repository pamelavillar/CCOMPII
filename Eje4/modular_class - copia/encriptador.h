#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H


#include <iostream>
#include <string>
#include "modular.h"
using namespace std;

class Encriptador{
    public:
        Modular inverso;
        int clave;
        string ruta_archivo;
        Encriptador();
        int obtener_clave_publica(int);
        string cargarArchivo();
        void encriptar();
        void guardar_encriptado(const string& texto_encriptado);
};

#endif 