//
// Created by R on 21/03/2020.
//

#include "Maestro.h"

#define DIPERSION_2 "dispersion2.txt"

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

void Maestro::genera() {
    Maestro m;
    int contador=0;
    ofstream file(DIPERSION_2,ios::out);
    if(file.is_open()){
        for (int i = 0; i < MAX_REGS ; i++) {
            file.write((char*)&contador, sizeof(int));
            for (int j = 0; j < CONTENEDOR ; j++) {
                file.write((char*)&m, sizeof(Maestro));
            }
        }
    }
    file.close();
}

int Maestro::dispersion(char *clave) {
    char copiaLlave[TAM_CLAVE+1];
    long int suma = 0;

    strcpy(copiaLlave,clave);

    if(strlen(copiaLlave) < TAM_CLAVE + 1) {
        for (int i = strlen(copiaLlave); i < TAM_CLAVE + 1 ; ++i) {
            copiaLlave[i] = ' ';
        }
        copiaLlave[TAM_CLAVE+1] = '\0';
    }
    for (int j = 0; j < TAM_CLAVE + 1 ; j += 2) {
        suma  = (suma + 100 * copiaLlave[j] + copiaLlave[j+1]) % 20000;
    }
    return (suma % 99);
}

bool Maestro::agregar(Maestro &nuevoMaestro) {
    Maestro maestro;
    string cadena;
    int posId;
    long int posByte;
    int contador;
    char id[TAM_CLAVE + 1];
    fstream file(DIPERSION_2, ios::in | ios::out);

    posId = dispersion(nuevoMaestro.getClave());
    posByte = posId * (sizeof(maestro) * CONTENEDOR + sizeof(int));
    file.seekp(posByte, ios::beg);
    file.read((char *) &contador, sizeof(int));
    if (contador < CONTENEDOR) {
        contador++;
        file.seekg(posByte, ios::beg);
        file.write((char *) &contador, sizeof(int));

        for (int i = 0; i < CONTENEDOR; ++i) {
            file.read((char *) &maestro, sizeof(maestro));
            strcpy(id, maestro.getClave());
            if (id[0] == '\0') {
                file.seekg((long) file.tellp() - sizeof(maestro), ios::beg);
                file.write((char *) &nuevoMaestro, sizeof(maestro));
                file.close();
                return true;
            }
        }
    } else {
        cout << "\nNo hay espacio para el registro" << endl;
        file.close();
        return false;
    }
}

void Maestro::mostrar() {
    Maestro m;
    int contador;
    long int posByte;
    char key[TAM_CLAVE+1];
    ifstream file(DIPERSION_2,ios::in);

    if(file.is_open()) {
        cout << endl;
        for (int i = 0; i < 1 ; i++) {
            file.read((char*)&contador,sizeof(int));
            if(contador < 0) {
                for (int j = 0; j < CONTENEDOR ; j++) {
                    file.read((char*)&m,sizeof(Maestro));
                    strcpy(key,m.getClave());
                    if(key[0] != '\0') {
                        imprimir(m);
                    }
                }
            }
            else {
                file.seekg(sizeof(Maestro)*CONTENEDOR,ios::cur);
            }
        }
    }
}

void Maestro::imprimir(Maestro m) {
    cout << "Id: " << m.getClave() << endl;
    cout << "Nombre: " << m.getNombre() << endl;
    cout << "Edad: " << m.getEdad() << endl;
    cout << "Materia: " << m.getMateria() << endl;
    cout << "Telefono: " << m.getTelefono() << endl;
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

char * Maestro::getClave() {
    return this->clave;
}

char * Maestro::getNombre() {
    return this->nombre;
}

char * Maestro::getEdad() {
    return this->edad;
}

char * Maestro::getMateria() {
    return this->materia;
}

char* Maestro::getTelefono() {
    return this->telefono;
}   