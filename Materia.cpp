//
// Created by R on 14/03/2020.
//

#include "Materia.h"

bool contiene(char *key);

Materia::Materia(){
    ifstream numRegs(ARCHIVO_NUM_MAT,ios::in);

    if(numRegs.is_open()) {
        numRegs >> this->numMat;
    } else{
        this->numMat = 0;
    }
    numRegs.close();
}

Materia::Materia(const Materia &mat) {
    strcpy(this->nrc,mat.nrc);
    strcpy(this->nombre,mat.nombre);
    strcpy(this->clave,mat.clave);
    strcpy(this->seccion,mat.seccion);
}

void Materia::setNombre(char *nombre) {
    strcpy(this->nombre,nombre);
}

void Materia::setNrc(char *nrc) {
    strcpy(this->nrc,nrc);
}

void Materia::setClave(char *clave) {
    strcpy(this->clave,clave);
}

void Materia::setSeccion(char *seccion) {
    strcpy(this->seccion,seccion);
}

void Materia::agregar(Materia &nuevo) {
    ofstream fileMat(ARCHIVO_MATERIAS,ios::app);
    ofstream fileIndices(INDICES_MATERIAS,ios::app);
    Indice indice;

    if(fileMat.is_open() && fileIndices.is_open()) {
        if(contiene(nuevo.nrc)){
            return;
        } else{
            fileMat.seekp(0,ios::end);
            fileMat.write((char*)&nuevo, sizeof(Materia));
            indice.pos = fileMat.tellp();
            indice.pos -= sizeof(Materia);
            fileMat.close();
            strcpy(indice.nrc,nuevo.nrc);

            fileIndices << indice.nrc << " " << indice.pos << " ";
            fileIndices.close();
        }
    }
}

bool contiene(char *key) {
    return false;
}