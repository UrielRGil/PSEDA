#include <iostream>

using namespace std;

void menuMateria();
void menuPagos();
void menuMaestros();

int principalMenu() {
    int opc;
    cout << "**********Menu Principal**********" << endl;
    cout << "1. Pagos\n2. Materia\n3.Maestros\n4. Salir\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}
// Inicio de la función principal
int main() {
    bool continuar = true;

    do{
        switch(principalMenu()){
            case 1:
                menuPagos();
                break;
            case 2:
                menuMateria();
                break;
            case 3:
                menuMaestros();
                break;
            case 4:
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

