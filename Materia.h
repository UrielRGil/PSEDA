//
// Created by R on 14/03/2020.
//

#ifndef PSEDA_MATERIA_H
#define PSEDA_MATERIA_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#define TAM_NOMBRE 40
#define TAM_NRC 6
#define TAM_SECCION 3
#define TAM_CLAVE 6

#define ARCHIVO_NUM_MAT "Num_materias.txt"
#define ARCHIVO_MATERIAS "Materias.txt"
#define INDICES_MATERIAS "IndicesMaterias.txt"
#define DATA_TEMP "DataTemp.txt"
#define INDICE_TEMP "TempIndice.txt"

using namespace std;

class Indice{
public:
    Indice(){
        pos = 0;
    }
    long int pos;
    char nrc[TAM_NRC+1] = {'\0'};
};


class Materia {
private:
    char nombre[TAM_NOMBRE+1] = {'\0'};
    char nrc[TAM_NRC+1] = {'\0'};
    char seccion[TAM_SECCION+1] = {'\0'};
    char clave[TAM_CLAVE+1] = {'\0'};
    int numMat;
public:
    Materia();
    Materia(const Materia &mat);
    void setNombre(char *nombre);
    void setNrc(char *nrc);
    void setSeccion(char *seccion);
    void setClave(char *clave);
    const char *getNombre();
    char *getNrc();
    const char *getSeccion();
    const char *getClave();
    void agregar(Materia &nuevo);
    bool mostrar();
    bool buscarIndice(char *key);
    bool modificar(Materia &m, char *nrc);
private:
    void imprimir(Materia &mat);
    void nuevoRegistro();
    int getNumRegs();
    void buscarReg(Indice indice);
    long int buscarNrc(char *indBuscado);
};

#endif //PSEDA_MATERIA_H
