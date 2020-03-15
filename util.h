#ifndef PSEDA_UTIL_H
#define PSEDA_UTIL_H

#include <iostream>

using namespace std;

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

int menu(string msj) {
    int opc;

    cout << "**********" << msj << "**********" << endl;
        cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}

#endif //PSEDA_UTIL_H
