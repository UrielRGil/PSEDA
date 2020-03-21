//
// Created by R on 21/03/2020.
//

#include "Maestro.h"

Maestro::Maestro() {
    ifstream numRegs(CUENTA_MAESTROS,ios::in);

    if(numRegs.is_open()) {
        numRegs >> this->numMaestros;
    } else{
        this->numMaestros = 0;
    }
    numRegs.close();
}

Maestro::Maestro(const Maestro &m) {
    strcpy(this->nombre,m.nombre);
    strcpy(this->clave,m.clave);
    strcpy(this->edad,m.edad);
    strcpy(this->materia,m.materia);
}

bool Maestro::agregar(const Maestro &m) {
    
}

void Maestro::setNombre(char *nombre) {
    strcpy(this->nombre,nombre);
}

void Maestro::setClave(char *clave) {
    strcpy(this->clave,clave);
}

void Maestro::setEdad(char *edad) {
    strcpy(this->edad,edad);
}

void Maestro::setTelefono(char *tel) {
    strcpy(this->telefono,telefono);
}

void Maestro::setMateria(char *materia) {
    strcpy(this->materia,materia);
}