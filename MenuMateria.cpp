#include "Materia.h"

void agregarMateria();

void mostrarMaterias();

void buscarMateria();

void modificarMateria();

void eliminarMateria();

int subMenuMat() {
    int opc;

    cout << "**********Materia**********" << endl;
    cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}


void menuMateria() {
    bool continuar = true;

    do {
        switch(subMenuMat()) {
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
                modificarMateria();
                break;
            case 5:
                eliminarMateria();
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

void eliminarMateria() {
    Materia m;
    char nrcElimnar[TAM_NRC+1];

    cout << "**********Eliminar Materia**********" << endl;
    cout << "Ingrese el nrc que desea eliminar: ";
    cin.getline(nrcElimnar,TAM_NRC+1);

    m.eliminar(nrcElimnar);
}

void modificarMateria() {
    char nrc[TAM_NRC+1], nrc2[TAM_NRC+1];
    char nombre[TAM_NOMBRE+1] = {'\0'};
    char seccion[TAM_SECCION+1] = {'\0'};
    char clave[TAM_CLAVE+1] = {'\0'};

    Materia mat;
    cout << "**********Modificarr***********" << endl;
    cout << "Ingresa el nrc de la materia que desea modificar: ";
    cin.getline(nrc,TAM_NRC+1);

    cout << "Ingresa los nuevos datos de la materia" << endl;
    cout << "Ingresa el nuevo nrc: ";
    cin.getline(nrc2,TAM_NRC+1);
    cout << "Ingresa el nuevo nombre de la materia: ";
    cin.getline(nombre,TAM_NOMBRE+1);
    cout << "Ingresa la nueva seccion de la materia: ";
    cin.getline(seccion,TAM_SECCION+1);
    cout << "Ingresa la nueva clave: ";
    cin.getline(clave,TAM_CLAVE+1);

    mat.setNrc(nrc2);
    mat.setNombre(nombre);
    mat.setSeccion(seccion);
    mat.setClave(clave);

    mat.modificar(mat,nrc);


}


void buscarMateria() {
    char nrc[TAM_NRC+1];
    Materia mat;
    cout << "**********Buscar**********" << endl;
    cout << "Ingresa el nrc a buscar: ";
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
