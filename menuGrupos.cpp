
#include "Grupos.h"

int menu();

void menuGrupos() {
    bool continuar = true;

    do {
        switch(menu()) {
            case 1:
                agregarGrupo();
                break;
            case 2:
                mostrarGrupo();
                break;
            case 3:
                buscarGrupo();
                break;
            case 4:
                modificarGrupo();
                break;
            case 5:
                eliminarGrupo();
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

int menu() {
    int opc;
    cout << "**********Grupos**********" << endl;
    cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}

