//
// Created by R on 21/03/2020.
//

#ifndef PSEDA_MAESTRO_H
#define PSEDA_MAESTRO_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#define TAM_NOMBRE 40
#define TAM_EDAD 2
#define TAM_CLAVE 10
#define TAM_TELEFONO 10
#define CONTENEDOR 4
#define MAX_REGS 1000

using namespace std;

class Maestro {
    char nombre[TAM_NOMBRE+1] = {'\0'};
    char edad[TAM_EDAD+1] = {'\0'};
    char clave[TAM_CLAVE+1] = {'\0'};
    char materia[TAM_NOMBRE+1] = {'\0'};
    char telefono[TAM_TELEFONO+1] = {'\0'};
public:
    Maestro();
    Maestro(const Maestro &m);
    void setNombre(char *nombre);
    void setEdad(char *edad);
    void setClave(char *clave);
    void setMateria(char *materia);
    void setTelefono(char *tel);
    char *getNombre();
    char* getClave();
    char *getEdad();
    char *getMateria();
    char *getTelefono();
    void genera();
    int dispersion(char *clave);
    bool agregar(Maestro &nuevoMaestro);
    void mostrar();
    bool buscar(char *clave, Maestro &m);
    void imprimir(Maestro m);
    bool modificar(char *claveModificar, Maestro &maestro);
    bool eliminar(char *claveEliminar, Maestro &mastEliminar);
private:
    long int buscarId(char *clave);
};


#endif //PSEDA_MAESTRO_H
