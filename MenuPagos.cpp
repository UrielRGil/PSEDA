//
// Created by R on 14/03/2020.
//

#include "Pagos.h"

void menuPagos();

int menu();

void agregarPagos();

void mostrarPagos();

void buscarPago();

void ModificarPago();

void eliminarPago();

// Controla el sub menu del apartado ""Pagos""
void menuPagos(){
    bool continuar = true;
    do{
        switch (menu()){
            case 1:
                agregarPagos();
                break;
            case 2:
                mostrarPagos();
                break;
            case 3:
                buscarPago();
                break;
            case 4:
                ModificarPago();
                break;
            case 5:
                eliminarPago();
                break;
            case 6:
                continuar = false;
                break;
            default:
                cout << "Opcion invalida..." << endl;
                getchar();
                break;
        }
    }while (continuar);
}

void eliminarPago() {
    char id[TAM_ID+1];
    Pagos *p;
    cout << "**********Eliminar**********" << endl << endl;
    cout << "Ingresa el ID del alumno asociado al pago que desea eliminar: ";
    cin.getline(id,TAM_ID+1);

    p = new Pagos();

    if(p->eliminar(id)){

    }
}

void ModificarPago() {
    char update[TAM_ID+1]; // Almacena el id asociado con el pago a modificar
    Pagos *p;
    cout << "Ingresa el ID asociado al registro pago a modificar: ";
    cin.getline(update,TAM_ID+1);

    p = new Pagos();
    if(p->modificar(update)){
        cout << "Operacion exitosa..." << endl;
    } else{
        cout << "A ocurrido un error" << endl;
    }
    getchar();
}

void buscarPago() {
    char id[TAM_ID+1];
    Pagos *p;
    cout << "Ingrese el ID asociado al pago que desea buscar: ";
    cin.getline(id,TAM_ID+1);

    p = new Pagos();
    cout << "Resultado: " << endl << endl;
    if(p->buscar(id)) {
        cout << "Operacion exitosa..." << endl;
    } else{
        cout << "No se encontro ningun registro relacionado al ID ingresado..." << endl;
    }
    getchar();
}

//Funcion que llama el metodo para mostrar los registros
void mostrarPagos() {
    Pagos *p = new Pagos();

    cout << endl <<"**********Mostrando Todos los registros*********" << endl;
    p->mostrar();
    delete p;
    getchar();
}

// Funcion para agreagar un nuevo pago, no recibe ningun parametro, ni retorna
void agregarPagos() {
    char idAlumno[TAM_ID+1];
    char fecha[TAM_FECHA+1];
    char hora[TAM_HORA+1];
    char dia;
    float monto;
    Pagos *p;

    cout << "Ingresa el id del alumno: ";
    cin.getline(idAlumno,TAM_ID+1);
    cout << "Ingresa el dia de pago: ";
    cin >> dia;
    getchar();
    cout << "Ingresa la fecha de pago: ";
    cin.getline(fecha,TAM_FECHA+1);
    cout << "Ingresa la hora de pago: ";
    cin.getline(hora,TAM_HORA+1);
    cout << "Ingresa el monto: ";
    cin >> monto;
    getchar();

    p = new Pagos();
    if(p->agregar(idAlumno,monto,dia,fecha,hora)){
        cout << "Operacion exitosa..." << endl;
    } else{
        cout << "A ocurrido un error, intente mas tarde" << endl;
    }
    delete  p;
    getchar();
}

int menu() {
    int opc;

    cout << "**********Menu Pagos**********" << endl;
    cout << "1. Agregar\n2. Mostrar\n3. Buscar\n4. Modificar\n5. Eliminar\n6. Regresar\nOpcion: ";
    cin >> opc;
    getchar();
    return opc;
}
