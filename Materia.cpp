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

char * Materia::getNrc() {
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
                return true;
            }
        }
    }
    return false;
}

void Materia::buscarReg(Indice indice) {
    Materia mat;
    ifstream data(ARCHIVO_MATERIAS,ios::in);
    long int pos;
    if(data.is_open()) {
        data.seekg(indice.pos,ios::beg);
        data.read((char*)&mat,sizeof(Materia));
        imprimir(mat);
    }else{
        data.close();
        return;
    }
    data.close();
}

bool Materia::modificar(Materia &m, char *key) {
    ofstream archivoDatos(ARCHIVO_MATERIAS,ios::out | ios::in);
    ofstream archivoIndice(INDICES_MATERIAS,ios::out | ios::in);
    int posByteIndice;
    long int posByteData;
    Indice indice;

    if(archivoDatos.is_open() && archivoIndice.is_open()) {
        posByteData = buscarNrc(key);
        posByteIndice = (posByteData/sizeof(Materia)) * sizeof(Indice);

        archivoDatos.seekp(posByteData,ios::beg);
        archivoDatos.write((char*)&m, sizeof(Materia));
        archivoIndice.seekp(posByteIndice,ios::beg);
        indice.pos = posByteData;
        strcpy(indice.nrc,m.getNrc());
        archivoIndice << indice.nrc  << " " << indice.pos;

    }
    archivoDatos.close();
    archivoIndice.close();
    return true;
}

long int Materia::buscarNrc(char *indBuscado) {
    ifstream indice(INDICES_MATERIAS,ios::in);
    Indice ind;
    if (indice.is_open()) {
        for (int i = 0; i < getNumRegs() ; ++i) {
            indice >> ind.nrc >> ind.pos;
            if(strcmp(ind.nrc,indBuscado) == 0) {
                return ind.pos;
                indice.close();
            }
        }
    }
    indice.close();
    return -1;
}

void Materia::eliminar(char *nrcEliminar) {
    ifstream data(ARCHIVO_MATERIAS,ios::in);
    ifstream indice(INDICES_MATERIAS,ios::in);
    ofstream dataTemp(DATA_TEMP,ios::app);
    ofstream indiceTemp(INDICE_TEMP,ios::app);
    ofstream numRegs(ARCHIVO_NUM_MAT,ios::out);
    Materia materiaTemp;
    long int posByte;
    Indice ind;

    if(data.is_open() && indice.is_open()) {
        posByte = buscarNrc(nrcEliminar);
        for (int i = 0; i < getNumRegs() ; ++i) {
            indice >> ind.nrc >> ind.pos;
            data.read((char*)&materiaTemp,sizeof(Materia));

            if(strcmp(materiaTemp.getNrc(),nrcEliminar) != 0) {
                if (ind.pos > posByte) {
                    ind.pos -= sizeof(Materia);
                }
                dataTemp.write((char*)&materiaTemp, sizeof(Materia));
                indiceTemp << ind.nrc << " " << ind.pos << " ";
            }
        }
    }
    dataTemp.close();
    indiceTemp.close();
    data.close();
    indice.close();

    if(numRegs.is_open()) {
        this->numMat--;
        numRegs << this->numMat;
    }

    numRegs.close();

    remove(INDICES_MATERIAS);
    rename(INDICE_TEMP,INDICES_MATERIAS);

    remove(ARCHIVO_MATERIAS);
    rename(DATA_TEMP,ARCHIVO_MATERIAS);
}

