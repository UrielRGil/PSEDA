#include "Materia.h"
#include "util.h"

void agregarMateria();

void mostrarMaterias();

void buscarMateria();

void menuMateria() {
    bool continuar = true;


    do {
        switch(menu("Menu Materia")) {
            case 1:
                agregarMateria();
                break;
            case 2:
                mostrarMaterias();
                break;
            case 3:
                buscarMateria();
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

void buscarMateria() {
    char nrc[TAM_NRC+1];
    Materia mat;
    cout << "**********Buscar**********" << endl;
    cin.getline(nrc,TAM_NRC+1);
    if(!mat.buscarIndice(nrc)){
        cout << "Registro no encontrado..." << endl;
    }
    getchar();
}

void mostrarMaterias() {
    Materia *m;
    cout << "**********Listado de materias**********" << endl;
    m = new Materia();
    if(!m->mostrar()) {
        cout << "No hay registros que mostrar" << endl;
    }
    getchar();
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
