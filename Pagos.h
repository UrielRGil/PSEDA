//
// Created by R on 14/03/2020.
//

#ifndef PSEDA_PAGOS_H
#define PSEDA_PAGOS_H


#include <iostream>
#include "cstring"
#define TAM_ID 10
#define TAM_FECHA 10
#define TAM_HORA 5

using namespace std;

// Clase pagos
class Pagos {
private:
    char idAlumno[TAM_ID+1];
    char fecha[TAM_FECHA+1];
    char hora[TAM_HORA+1];
    char dia;
    float monto;
    int regsCant;
public:
    Pagos();
    void setDia(char dia);
    void setMonto(float monto);
    void setId(char* id);
    void setFecha(char *fecha);
    void setHora(char* hora);
    bool agregar(char *string, float monto, char dia, char *fecha, char *hora);
    void mostrar();
    bool buscar(char *id);
    bool modificar(char *id);

    bool eliminar(char *id);

private:
    void imprimir();
    static int menuModificarPago();
};


#endif //PSEDA_PAGOS_H
