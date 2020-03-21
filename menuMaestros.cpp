#include "Maestro.h"

int menu();

void agregarProfesor();

void menuMaestros() {
    bool continuar = true;

    do{
        switch (menu()) {
            case 1:
                agregarProfesor();
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
                cout << "Opción incorrecta...." << endl;
        }
    }while(continuar);
}

void agregarProfesor() {

}

int menu() {
    int opc;

    cout << "**********Maestro**********" << endl;
    cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}
