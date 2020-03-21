//
// Created by R on 21/03/2020.
//

#ifndef PSEDA_MAESTRO_H
#define PSEDA_MAESTRO_H

#include <iostream>
#include <fstream>
#include <cstring>

#define TAM_NOMBRE 40
#define TAM_EDAD 2
#define TAM_CLAVE 10
#define TAM_TELEFONO 10
#define CUENTA_MAESTROS "cuentaMaestros.txt"

using namespace std;

class Maestro {
    char nombre[TAM_NOMBRE+1] = {'\0'};
    char edad[TAM_EDAD+1] = {'\0'};
    char clave[TAM_CLAVE+1] = {'\0'};
    char materia[TAM_NOMBRE+1] = {'\0'};
    char telefono[TAM_TELEFONO] = {'\0'};
    int numMaestros;
public:
    Maestro();
    Maestro(const Maestro &m);
    void setNombre(char *nombre);
    void setEdad(char *edad);
    void setClave(char *clave);
    void setMateria(char *materia);
    void setTelefono(char *tel);
    bool agregar(const Maestro &m);

};


#endif //PSEDA_MAESTRO_H
