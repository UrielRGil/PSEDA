//
// Created by R on 21/03/2020.
//

#include "Maestro.h"

#define DISPERSION_2 "dispersion2.txt"

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
    ofstream file(DISPERSION_2, ios::out);
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
    int j = 0;
    strcpy(copiaLlave,clave);

    if(strlen(copiaLlave) < TAM_CLAVE + 1) {
        for (int i = strlen(copiaLlave); i < TAM_CLAVE + 1 ; i++) {
            copiaLlave[i] = ' ';
        }
        copiaLlave[TAM_CLAVE+1] = '\0';
    }
    while (j < TAM_CLAVE){
        suma  = (suma + 100 * copiaLlave[j] + copiaLlave[j+1]) % 20000;
        j+=2;
    }
    int sumaAux = suma % 99;
    return sumaAux;
}

bool Maestro::agregar(Maestro &nuevoMaestro) {
    Maestro maestro;
    string cadena;
    int posId;
    long int posByte;
    int contador;
    char aux[2];
    char id[TAM_CLAVE + 1];
    fstream file(DISPERSION_2, ios::in | ios::out);

    posId = dispersion(nuevoMaestro.getClave());
    posByte = posId * ((sizeof(maestro) * CONTENEDOR) + sizeof(int));
    file.seekp(posByte, ios::beg);
    file.read((char *) &aux, 2);
    contador = atoi(aux);
    if (contador < CONTENEDOR) {
        contador++;
        file.seekg(posByte, ios::beg);
        file << contador << "   ";
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
    }else {
        cout << "\nNo hay espacio para el registro" << endl;
        file.close();
        return false;
    }
}
void Maestro::mostrar() {
    Maestro m;
    char aux[2];
    int contador;
    long int posByte;
    char key[TAM_CLAVE+1];
    ifstream file(DISPERSION_2, ios::in);

    if(file.is_open()) {
        cout << endl;
        for (int i = 0; i < MAX_REGS ; i++) {
            file.read(aux, 4);
            contador = atoi(aux);
            if(contador > 0) {
                for (int j = 0; j < CONTENEDOR; j++) {
                    file.read((char *) &m, sizeof(Maestro));
                    strcpy(key, m.getClave());
                    if (key[0] != '\0') {
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

bool Maestro::buscar(char *clave, Maestro &m) {
    long int posByte;
    ifstream dispersionFile(DISPERSION_2, ios::in);

    if(dispersionFile.is_open()) {
        posByte = buscarId(clave);
        dispersionFile.seekg(posByte, ios::beg);
        dispersionFile.read((char *) &m, sizeof(Maestro));
        dispersionFile.close();
        return true;
    }
    return false;
}

bool Maestro::eliminar(char *claveEliminar, Maestro &mastEliminar) {
    Maestro m;
    int posIndice,posByte,contador;
    fstream dispersionFile(DISPERSION_2,ios::in | ios::out);

    if(dispersionFile.is_open()) {
        posIndice = dispersion(claveEliminar);
        posByte = buscarId(claveEliminar);

        dispersionFile.seekg(posByte,ios::beg);
        dispersionFile.read((char*)&mastEliminar,sizeof(Maestro));
        dispersionFile.seekg(posByte,ios::beg);
        dispersionFile.write((char*)&m, sizeof(Maestro));

        posByte = posIndice * (sizeof(Maestro) * CONTENEDOR + sizeof(int));
        dispersionFile.seekg(posByte,ios::beg);
        dispersionFile.read((char*)&contador, sizeof(int));
        contador--;
        dispersionFile.seekg(posByte,ios::beg);
        dispersionFile << contador << "   ";
        dispersionFile.close();
        return true;
    }
    return false;
}

long int Maestro::buscarId(char *clave) {
    Maestro m;
    int contador = 0,posIndice;
    long int posByte;
    ifstream dispersionFile(DISPERSION_2, ios::in);

    if(dispersionFile.is_open()) {
        posIndice = dispersion(clave);
        posByte =posIndice*((sizeof(Maestro)*CONTENEDOR)+ sizeof(int));
        dispersionFile.seekg(posByte,ios::beg);
        dispersionFile.read((char*)&contador, sizeof(int));
        if(contador > 0) {
            for (int i =0; i < CONTENEDOR;i++) {
                dispersionFile.read((char*)&m,sizeof(Maestro));
                if(strcmp(clave,m.getClave()) == 0) {
                    posByte = (long)dispersionFile.tellg() - sizeof(Maestro);
                    dispersionFile.close();
                    return posByte;
                }
            }
        }
    }
    else {
        dispersionFile.close();
    }
    return -1;
}

void Maestro::imprimir(Maestro m) {
    cout << "Id: " << m.getClave() << endl;
    cout << "Nombre: " << m.getNombre() << endl;
    cout << "Edad: " << m.getEdad() << endl;
    cout << "Materia: " << m.getMateria() << endl;
    //cout << "Telefono: " << m.getTelefono() << endl;
    cout << endl;
}

bool Maestro::modificar(char *claveModificar, Maestro &maestro) {
    Maestro registroLimpio,m;
    int posIndiceAntiguo,posIndiceNuevo, contador;
    long int posByteAntiguo, posByteNuevo;
    fstream dispersionFile(DISPERSION_2,ios::in | ios::out);
    char auxID[TAM_CLAVE+1];

    if(dispersionFile.is_open()) {
        posIndiceAntiguo = dispersion(claveModificar);
        posIndiceNuevo = dispersion(maestro.getClave());
        posByteAntiguo =buscarId(claveModificar);
        posByteNuevo = posIndiceNuevo * ((sizeof(Maestro) * CONTENEDOR) + sizeof(int));

        if(posByteAntiguo == posByteNuevo) {
            dispersionFile.seekg(posByteAntiguo,ios::beg);
            dispersionFile.write((char*)&maestro, sizeof(Maestro));
        } else {
            dispersionFile.seekg(posByteAntiguo,ios::beg);
            dispersionFile.write((char*)&registroLimpio, sizeof(Maestro));
            posByteAntiguo = posIndiceAntiguo * (sizeof(Maestro) * CONTENEDOR) + sizeof(int);
            dispersionFile.readsome((char*)&contador, sizeof(int));
            contador--;
            dispersionFile.seekg(posByteAntiguo,ios::beg);
            dispersionFile << contador << "   ";
            dispersionFile.seekg(posByteNuevo,ios::beg);
            dispersionFile.read((char*)&contador, sizeof(int));
            if(contador < CONTENEDOR) {
                contador++;
                dispersionFile.seekg(posByteNuevo,ios::beg);
                dispersionFile << contador << "   ";
                for (int i = 0; i < CONTENEDOR ; ++i) {
                    dispersionFile.read((char*)&m, sizeof(Maestro));
                    strcpy(auxID,m.getClave());
                    if(auxID[0] != '\0'){
                        dispersionFile.seekg((long)dispersionFile.tellg()- sizeof(Maestro),ios::beg);
                        dispersionFile.write((char*)&maestro,sizeof(Maestro));
                        dispersionFile.close();
                        return true;
                    }
                }
            } else {
                return false;
            }
        }
    }
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
    strcpy(this->telefono,tel);
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

char * Maestro::getTelefono() {
    return this->telefono;
}   