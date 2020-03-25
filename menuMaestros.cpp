#include "Maestro.h"

void agregarProfesor();

void mostrarProfesor();

void modificarProfesor();

void buscarMaestro();

void agregarProfesor(Maestro &m);

void eliminarProfesor();

int subMenuMaestros() {
    int opc;

    cout << "**********Maestro**********" << endl;
    cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}

void menuMaestros() {
    bool continuar = true;
    Maestro m;

    //m.genera();
    do{
        switch (subMenuMaestros()){
            case 1:
                agregarProfesor();
                break;
            case 2:
                mostrarProfesor();
                break;
            case 3:
                buscarMaestro();
                break;
            case 4:
                modificarProfesor();
                break;
            case 5:
                eliminarProfesor();
                break;
            case 6:
                continuar = false;
                break;
            default:
                cout << "Opción incorrecta...." << endl;
        }
    }while(continuar);
}

void eliminarProfesor() {
    char claveEliminar[TAM_CLAVE+1];
    Maestro m;
    char opc;
    cout << "***********Eliminar***********" << endl;
    cout << "Ingrese la clave del maestro que desee eliminar: ";
    cin.getline(claveEliminar,TAM_CLAVE+1);

    if(m.buscar(claveEliminar,m)){
        cout << "Seguro que desea eliminar (s/n)?: ";
        cin >> opc;
        if (opc == 'S' || opc == 's') {
            if(m.eliminar(claveEliminar,m)) {
                cout << "Registro eliminado correctamente..." << endl;
            }
            else {
                cout << "Error Error Error" << endl;
            }
        } else {
            cout << "Operacion anulada" << endl;
        }
    }
    getchar();
}

void buscarMaestro() {
    char buscar[TAM_CLAVE+1];
    Maestro m;

    cout << "***********Buscar**********" << endl;
    cout << "Ingrese la clave a buscar: ";
    cin.getline(buscar,TAM_CLAVE+1);

    if(m.buscar(buscar,m)) {
        m.imprimir(m);
    } else {
        cout << "No se tiene registro de este maestro...." << endl;
    }
    getchar();
}


void modificarProfesor() {
    char idModificar[TAM_CLAVE+1];
    Maestro m;
    char opc;
    cout << "**********Modificar**********" << endl;
    cout << "Ingresa la clave a modificar: ";
    cin.getline(idModificar,TAM_CLAVE+1);

    if(m.buscar(idModificar,m)) {
        cout << "Seguro que desea eliminar (s/n)? ";
        cin >> opc;
        if( opc = 's' || opc == 'S') {
            agregarProfesor(m);
            m.modificar(idModificar,m);
        } else{
            cout << "Operacion anulada" << endl;
        }
    }
    getchar();
}

void mostrarProfesor() {
    Maestro m;
    m.mostrar();
    getchar();
}

void agregarProfesor(Maestro &m) {
    char nombre[TAM_NOMBRE+1];
    char edad[TAM_EDAD+1];
    char clave[TAM_CLAVE+1];
    char materia[TAM_NOMBRE+1];
    char telefono[TAM_TELEFONO+1];

    cout << "**********Agregar Profesor**********" << endl;
    cout << "Ingrese el nombre del profesor: ";
    cin.getline(nombre,TAM_NOMBRE+1);
    cout << "Ingrese la clave del profesor: ";
    cin.getline(clave,TAM_CLAVE+1);
    cout << "Ingrese la materia que imparte: ";
    cin.getline(materia,TAM_NOMBRE+1);
    cout << "Ingrese la edad: ";
    cin.getline(edad,TAM_EDAD+1);
    cout << "Ingrese el telefono: ";
    cin.getline(telefono,TAM_TELEFONO+1);

    m.setNombre(nombre);
    m.setClave(clave);
    m.setMateria(materia);
    m.setTelefono(telefono);
    m.setEdad(edad);
}

void agregarProfesor() {
    Maestro m;
    char nombre[TAM_NOMBRE+1];
    char edad[TAM_EDAD+1];
    char clave[TAM_CLAVE+1];
    char materia[TAM_NOMBRE+1];
    char telefono[TAM_TELEFONO+1];

    cout << "**********Agregar Profesor**********" << endl;
    cout << "Ingrese el nombre del profesor: ";
    cin.getline(nombre,TAM_NOMBRE+1);
    cout << "Ingrese la clave del profesor: ";
    cin.getline(clave,TAM_CLAVE+1);
    cout << "Ingrese la materia que imparte: ";
    cin.getline(materia,TAM_NOMBRE+1);
    cout << "Ingrese la edad: ";
    cin.getline(edad,TAM_EDAD+1);
    cout << "Ingrese el telefono: ";
    cin.getline(telefono,TAM_TELEFONO+1);

    m.setNombre(nombre);
    m.setClave(clave);
    m.setMateria(materia);
    m.setTelefono(telefono);
    m.setEdad(edad);

    if (m.agregar(m)) {
        cout << "Registro agregado con exito" << endl;
    } else {
        cout << "A ocurrido un error..." << endl;
    }
    getchar();
}


