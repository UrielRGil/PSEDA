//
// Created by R on 14/03/2020.
//

#include "Pagos.h"

#include <fstream>
#include "Pagos.h"

#define FILE "Pagos.txt"
#define TEMP "Temp.txt"
#define FILE_N "regsCant.txt"


// Constructor
Pagos::Pagos(){
    ifstream regsCant(FILE_N,ios::in);

    this->regsCant = 0;

    if(regsCant.is_open()){
        regsCant >> this->regsCant;
    }
    regsCant.close();
}
// Fin del constructor

// Setter para los atributos de la clase Pagos
void Pagos::setDia(char dia) {
    this->dia = dia;
}

void Pagos::setMonto(float monto) {
    this->monto = monto;
}

void Pagos::setId(char *id) {
    strcpy(this->idAlumno,id);
}

void Pagos::setFecha(char *fecha) {
    strcpy(this->fecha,fecha);
}

void Pagos::setHora(char *hora) {
    strcpy(this->hora,hora);
}
// Fin de los setters

// Metodo agregar, recibe los atributos de la clase para guardarlos en un archivo
// Retorna true si se guarda con exito
bool Pagos::agregar(char *id, float monto, char dia, char *fecha, char *hora) {
    ofstream file(FILE,ios::app);
    ofstream regsCant(FILE_N,ios::out);

    if(file.is_open()){
        file << id << monto << dia << fecha << hora;
        if(regsCant.is_open()){
            this->regsCant++;
            regsCant << this->regsCant;
        }
        regsCant.close();
    }
    else {
        return false;
    }
    file.close();
    return true;
}

// Método mostrar
// Muestra en consola todos los registros en disco
// No recibe ni retorna nada
void Pagos::mostrar() {
    ifstream file(FILE,ios::in);

    if(file.is_open()){
        for (int i = 0; i < this->regsCant ; ++i) {
            file.read((char*)&this->idAlumno,TAM_ID);
            file >> this->monto;
            file >> this->dia;
            file.read((char*)&this->fecha,TAM_FECHA);
            file.read((char*)&this->hora,TAM_HORA);

            imprimir();
        }
    }
    file.close();
}

// Imprime en consola un registro
void Pagos::imprimir() {
    cout << "Id Alumno: \t\t\t" << this->idAlumno << endl;
    cout << "Dia de pago: \t\t" << this->dia << endl;
    cout << "Fecha de pago: \t\t" << this->fecha << endl;
    cout << "Hora de pago: \t\t" << this->hora << endl;
    cout << "Monto: \t\t\t\t" << this->monto << endl << endl;
}

bool Pagos::buscar(char *id) {
    ifstream file(FILE,ios::in);
    bool encontrado = false;
    if(file.is_open()){
        for (int i = 0; i < this->regsCant ; ++i) {
            file.read((char*)&this->idAlumno,TAM_ID);
            file >> this->monto;
            file >> this->dia;
            file.read((char*)&this->fecha,TAM_FECHA);
            file.read((char*)&this->hora,TAM_HORA);
            if(strcmp(this->idAlumno,id) == 0) {
                imprimir();
                encontrado = true;
            }
        }
    }
    file.close();
    return encontrado;
}

bool Pagos::modificar(char *id) {
    ifstream file(FILE,ios::in);
    ofstream temp(TEMP,ios::app);
    char update[TAM_ID+1];
    char hora[TAM_HORA+1];
    float newM;
    char newD;
    bool exito = false;

    if(this->buscar(id)){
        switch (menuModificarPago()) {
            case 1:
                cout << "Ingresa el nuevo ID que deseas asociar al pago: ";
                cin.getline(update,TAM_ID+1);
                if(file.is_open()){
                    if(temp.is_open()){
                        for (int i = 0; i < this->regsCant ; ++i) {
                            file.read((char*)&this->idAlumno,TAM_ID);
                            file >> this->monto;
                            file >> this->dia;
                            file.read((char*)&this->fecha,TAM_FECHA);
                            file.read((char*)&this->hora,TAM_HORA);
                            if(strcmp(this->idAlumno,id) == 0) {
                                temp << update << this->monto << this->dia << this->fecha << this->hora;

                            } else{
                                temp << this->idAlumno << this->monto << this->dia << this->fecha << this->hora;
                            }
                        }
                    }
                }
                file.close();
                temp.close();
                remove(FILE);
                rename(TEMP,FILE);
                buscar(update);
                exito = true;
                break;
            case 2:
                cout << "Ingresa el nuevo dia de pago: ";
                cin >> newD;
                getchar();
                if(file.is_open()){
                    if(temp.is_open()){
                        for (int i = 0; i < this->regsCant ; ++i) {
                            file.read((char*)&this->idAlumno,TAM_ID);
                            file >> this->monto;
                            file >> this->dia;
                            file.read((char*)&this->fecha,TAM_FECHA);
                            file.read((char*)&this->hora,TAM_HORA);
                            if(strcmp(this->idAlumno,id) == 0) {
                                temp << this->idAlumno << this->monto << newD << this->fecha << this->hora;

                            } else{
                                temp << this->idAlumno << this->monto << this->dia << this->fecha << this->hora;
                            }
                        }
                    }
                }
                file.close();
                temp.close();
                remove(FILE);
                rename(TEMP,FILE);
                buscar(id);
                exito = true;
                break;
            case 3:
                cout << "Ingresa la nueva fecha: ";
                cin.getline(update,TAM_FECHA+1);
                if(file.is_open()){
                    if(temp.is_open()){
                        for (int i = 0; i < this->regsCant ; ++i) {
                            file.read((char*)&this->idAlumno,TAM_ID);
                            file >> this->monto;
                            file >> this->dia;
                            file.read((char*)&this->fecha,TAM_FECHA);
                            file.read((char*)&this->hora,TAM_HORA);
                            if(strcmp(this->idAlumno,id) == 0) {
                                temp << this->idAlumno << this->monto << this->dia << update << this->hora;

                            } else{
                                temp << this->idAlumno << this->monto << this->dia << this->fecha << this->hora;
                            }
                        }
                    }
                }
                file.close();
                temp.close();
                remove(FILE);
                rename(TEMP,FILE);
                buscar(id);
                exito = true;
                break;
            case 4:
                cout << "Ingresa la nueva hora de pago: ";
                cin.getline(hora,TAM_HORA+1);
                if(file.is_open()){
                    if(temp.is_open()){
                        for (int i = 0; i < this->regsCant ; ++i) {
                            file.read((char*)&this->idAlumno,TAM_ID);
                            file >> this->monto;
                            file >> this->dia;
                            file.read((char*)&this->fecha,TAM_FECHA);
                            file.read((char*)&this->hora,TAM_HORA);
                            if(strcmp(this->idAlumno,id) == 0) {
                                temp << this->idAlumno << this->monto << this->dia << this->fecha << hora;

                            } else{
                                temp << this->idAlumno << this->monto << this->dia << this->fecha << this->hora;
                            }
                        }
                    }
                }
                file.close();
                temp.close();
                remove(FILE);
                rename(TEMP,FILE);
                buscar(id);
                exito = true;
                break;
            case 5:
                cout << "Ingresa nuevo monto: ";
                cin >> newM;
                getchar();
                if(file.is_open()){
                    if(temp.is_open()){
                        for (int i = 0; i < this->regsCant ; ++i) {
                            file.read((char*)&this->idAlumno,TAM_ID);
                            file >> this->monto;
                            file >> this->dia;
                            file.read((char*)&this->fecha,TAM_FECHA);
                            file.read((char*)&this->hora,TAM_HORA);
                            if(strcmp(this->idAlumno,id) == 0) {
                                temp << this->idAlumno << newM << this->dia << this->fecha << this->hora;

                            } else{
                                temp << this->idAlumno << this->monto << this->dia << this->fecha << this->hora;
                            }
                        }
                    }
                }
                file.close();
                temp.close();
                remove(FILE);
                rename(TEMP,FILE);
                buscar(id);
                exito = true;
                break;
            default:
                cout << "Opcion invalida..." << endl;
                break;
        }
    }
    return exito;
}

int Pagos::menuModificarPago() {
    int opc;
    cout << "Selecciona el campo que desea modificar: " << endl;
    cout << "1. Id\n2. Dia de pago\n3. Fecha de pago\n4. Hora de pago\n5. Monto\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}

bool Pagos::eliminar(char *id) {
    ifstream file(FILE,ios::in);
    ofstream temp(TEMP,ios::app), regsCant(FILE_N,ios::out);
    bool exito = false;

    if (file.is_open()){
        if(temp.is_open()){
            for (int i = 0; i < this->regsCant ; ++i) {
                file.read((char*)&this->idAlumno,TAM_ID);
                file >> this->monto;
                file >> this->dia;
                file.read((char*)&this->fecha,TAM_FECHA);
                file.read((char*)&this->hora,TAM_HORA);
                if(strcmp(this->idAlumno,id) != 0){
                    temp << this->idAlumno << this->monto << this->dia << this->fecha << this->hora;
                }else{
                    this->regsCant--;
                    exito = true;
                }
            }
        }
    }
    file.close();
    temp.close();
    remove(FILE);
    rename(TEMP,FILE);
    if(regsCant.is_open()){
        regsCant << this->regsCant;
    }
    regsCant.close();

    return exito;
}

