#include <iostream>

#include "util.h"

using namespace std;

// Inicio de la función principal
int main() {
    bool continuar = true;

    do{
        switch (menuPrincipal()){
            case 1:
                menu("Pagos");
                break;
            case 2:
                menu("Materias");
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

