#include <iostream>
#include "Pagos.h"



void menuPagos();
void menuMateria();
int menuPrincipal();

using namespace std;

// Inicio de la función principal
int main() {
    bool continuar = true;

    do{
        switch (menuPrincipal()){
            case 1:
                menuPagos();
                break;
            case 2:
                menuMateria();
                break;
            case 3:
                continuar = false;
                break;
            default:
                cout << "Opcion invalida...." << endl;
                getchar();
        }
    }while(continuar);
    return 0;
}
// Fin de la funcion principal


/* Muestra el menu principal del programa
 * No recibe parametros
 * Regresa un entero que indica cual opcion realizar
 * */
int menuPrincipal() {
    int opc;

    cout << "**********Menu Principal**********" << endl;
    cout << "1. Pagos\n2. Materia\n3. Salir\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}
