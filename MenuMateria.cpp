//
// Created by R on 14/03/2020.
//

#include "Materia.h"

int Menu();

void agregarMateria();

void menuMateria() {
    bool continuar = true;

    do {
        switch(Menu()) {
            case 1:
                agregarMateria();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                continuar = false;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                getchar();
        }
    }while(continuar);
}

void agregarMateria() {

}

int Menu() {
    int opc;

    cout << "**********Menu Materia**********" << endl;
    cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}
