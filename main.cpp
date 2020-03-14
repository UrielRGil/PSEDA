#include <iostream>
#include "Pagos.h"
#include "util.h"


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

