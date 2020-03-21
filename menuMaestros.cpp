#include "Maestro.h"

void agregarProfesor();

void mostrarProfesor();

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

    m.genera();
    do{
        switch (subMenuMaestros()){
            case 1:
                agregarProfesor();
                break;
            case 2:
                mostrarProfesor();
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

void mostrarProfesor() {
    Maestro m;
    m.mostrar();
    getchar();
}

void agregarProfesor() {
    Maestro m;
    char nombre[TAM_NOMBRE+1];
    char edad[TAM_EDAD+1];
    char clave[TAM_CLAVE+1];
    char materia[TAM_NOMBRE+1];
    char telefono[TAM_TELEFONO];

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

    }
}


