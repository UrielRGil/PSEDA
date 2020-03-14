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
    Materia mat;
    char nombre[TAM_NOMBRE+1];
    char nrc[TAM_NRC+1];
    char seccion[TAM_SECCION+1];
    char clave[TAM_CLAVE+1];

    cout << "Ingrese el nombre de la materia: ";
    cin.getline(nombre,TAM_NOMBRE+1);
    cout << "Ingrese el nrc: ";
    cin.getline(nrc,TAM_NRC+1);
    cout << "Ingrese la seccion: ";
    cin.getline(seccion,TAM_SECCION+1);
    cout << "Ingrese la clave de la materia: ";
    cin.getline(clave,TAM_CLAVE+1);

    mat.setNombre(nombre);
    mat.setNrc(nrc);
    mat.setClave(clave);
    mat.setSeccion(seccion);

    mat.agregar(mat);
}

int Menu() {
    int opc;

    cout << "**********Menu Materia**********" << endl;
    cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}
