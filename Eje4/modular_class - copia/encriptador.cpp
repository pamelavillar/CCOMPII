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


int Encriptador::obtener_clave_publica(int clave){
    int clave_publica = inverso.inverso_multi(clave,256);
    if (clave_publica == 0){
        return 0;
    } 
    else {
        return clave_publica;
    }
}

string Encriptador::cargarArchivo() { 
    ifstream archivo(ruta_archivo);
    string texto;

    if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                texto += linea;
                texto += '\n'; // mantener la estructura del texto
            }
            archivo.close();
    } 
    else{
            cout << "No se pudo abrir el archivo: " << ruta_archivo << endl;
    }
        return texto;

}

void Encriptador::encriptar(){
    string texto_original = cargarArchivo();
    string texto_encriptado = "";
    for (int i = 0; i < texto_original.length(); i++) {
        int n1 = static_cast<int>(texto_original[i]);
        char new_character = static_cast<char>(inverso.modu(n1*clave,256));
        texto_encriptado += new_character;
    }
    guardar_encriptado(texto_encriptado);
}


void Encriptador::guardar_encriptado(const string& texto_encriptado){//paso por referencia  
    ofstream archivo_encriptado("encriptado.txt");
    archivo_encriptado << texto_encriptado;
    archivo_encriptado.close();
}
