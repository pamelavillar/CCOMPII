#include <iostream>
#include <string>
#include "encriptador.h"
#include <fstream>
#include <cstdlib>
using namespace std;

Encriptador::Encriptador(){
    clave = 0;
    ruta_archivo = "";
    inverso = Modular();
}

string Encriptador::cargarArchivo() { 
    ifstream archivo(ruta_archivo);
    string texto;

    if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                texto += linea;
                texto += '\n'; // Agregar salto de línea para mantener la estructura del texto
            }
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo: " << ruta_archivo << std::endl;
        }
        return texto;

}

string Encriptador::encriptar(const string& texto, int clave){
    
    string texto_encriptado = "";
    for (int i = 0; i < texto.length(); i++) {
        int n1 = static_cast<int>(texto[i]);
        char new_character = static_cast<char>(inverso.modu(n1*clave,256));
        texto_encriptado += new_character;
    }
    return texto_encriptado;
}


void Encriptador::guardar_encriptado(const string& texto_encriptado){
    ofstream archivo_encriptado("encriptado.txt");
    archivo_encriptado << texto_encriptado;
    archivo_encriptado.close();
}
