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

const char * Materia::getNombre() {
    return this->nombre;
}

const char * Materia::getNrc() {
    return this->nrc;
}

const char * Materia::getSeccion() {
    return this->seccion;
}

const char * Materia::getClave() {
    return this->clave;
}

void Materia::agregar(Materia &nuevo) {
    ofstream fileMat(ARCHIVO_MATERIAS,ios::app);
    ofstream fileIndices(INDICES_MATERIAS,ios::app);
    ofstream countFile(ARCHIVO_NUM_MAT,ios::out);
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
            nuevoRegistro();
            if (countFile.is_open()) {
                countFile << this->numMat;
            }
            countFile.close();
        }
    }
}

bool contiene(char *key) {
    return false;
}

bool Materia::mostrar() {
    ifstream data(ARCHIVO_MATERIAS,ios::in);
    Materia mat;
    if(data.is_open()) {
        for (int i = 0; i < getNumRegs() ; ++i) {
            data.read((char*)&mat,sizeof(Materia));
            imprimir(mat);
        }
        return true;
    }else {
        return false;
    }
}

void Materia::imprimir(Materia &mat) {
    cout << "Nombre: " << mat.getNombre() << endl;
    cout << "NRC: " << mat.getNrc() << endl;
    cout << "Seccion: " << mat.getSeccion() << endl;
    cout << "Clave: " << mat.getClave() << endl << endl;
}

void Materia::nuevoRegistro() {
    this->numMat++;
}

int Materia::getNumRegs() {
    return this->numMat;
}

bool Materia::buscarIndice(char *key) {
    ifstream fileIndice(INDICES_MATERIAS,ios::in);
    Indice indice;

    if(fileIndice.is_open()) {
        for (int i = 0; i < getNumRegs() ; ++i) {
            fileIndice >> indice.nrc >> indice.pos;
            if(strcmp(key,indice.nrc) == 0) {
                buscarReg(indice);
            }
            else {
                return false;
            }
        }
    }
}

void Materia::buscarReg(Indice indice) {
    Materia mat;
    ifstream data(ARCHIVO_MATERIAS,ios::in);
    long int pos;
    if(data.is_open()) {
        pos = indice.pos * sizeof(Materia);
        data.seekg(pos,ios::beg);
        data.read((char*)&mat,sizeof(Materia));
        imprimir(mat);
    }else{
        data.close();
        return;
    }
    data.close();
}