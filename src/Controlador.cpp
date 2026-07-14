#include "Controlador.h"
#include "Ambulancia.h"
#include "Helicoptero.h"
#include "Medico.h"
#include "Rescatista.h"
#include <iostream>
using namespace std;

Controlador::Controlador() {
    capacidadRecursos = 10;
    cantidadRecursos = 0;
    listaRecursos = new Recurso*[capacidadRecursos];

    capacidadMisiones = 5;
    cantidadMisiones = 0;
    listaMisiones = new Mision*[capacidadMisiones];

    cargarDatosPrueba();
}

void Controlador::redimensionarRecursos() {
    int nuevaCap = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCap];
    for (int i = 0; i < cantidadRecursos; i++) nuevoArreglo[i] = listaRecursos[i];
    delete[] listaRecursos;
    listaRecursos = nuevoArreglo;
    capacidadRecursos = nuevaCap;
}

void Controlador::redimensionarMisiones() {
    int nuevaCap = capacidadMisiones * 2;
    Mision** nuevoArreglo = new Mision*[nuevaCap];
    for (int i = 0; i < cantidadMisiones; i++) nuevoArreglo[i] = listaMisiones[i];
    delete[] listaMisiones;
    listaMisiones = nuevoArreglo;
    capacidadMisiones = nuevaCap;
}

// ---------- HU05: Datos quemados ----------
void Controlador::cargarDatosPrueba() {
    listaRecursos[cantidadRecursos++] = new Ambulancia("AMB-01", "Ambulancia Roja", "WWW111", 2);
    listaRecursos[cantidadRecursos++] = new Ambulancia("AMB-02", "Ambulancia Azul", "WWW222", 2);
    listaRecursos[cantidadRecursos++] = new Helicoptero("HELI-01", "Halcon 1", "HK-500", 4);
    listaRecursos[cantidadRecursos++] = new Medico("MED-01", "Dra. Ana Torres", "Trauma");
    listaRecursos[cantidadRecursos++] = new Medico("MED-02", "Dr. Luis Rey", "Pediatria");
    listaRecursos[cantidadRecursos++] = new Rescatista("RES-01", "Carlos Mora", "Rescate en alturas");
    listaRecursos[cantidadRecursos++] = new Rescatista("RES-02", "Julia Pena", "Rescate acuatico");

    listaMisiones[cantidadMisiones++] = new Mision("MIS-01", "Deslizamiento Siloe");
    listaMisiones[cantidadMisiones++] = new Mision("MIS-02", "Inundacion Aguablanca");

    // Pre-asignamos algunos recursos para que HU03 se pueda probar de inmediato
    listaMisiones[0]->agregarRecurso(listaRecursos[0]); // Ambulancia AMB-01
    listaMisiones[0]->agregarRecurso(listaRecursos[3]); // Medico MED-01
    listaMisiones[1]->agregarRecurso(listaRecursos[2]); // Helicoptero HELI-01
    listaMisiones[1]->agregarRecurso(listaRecursos[5]); // Rescatista RES-01

    cout << "Datos cargados correctamente." << endl;
}

// ---------- Menu del sistema----------
void Controlador::mostrarMenu() {
    cout << "\n----------- Sistema de Gestion de Misiones de Rescate -----------" << endl;
    cout << "1. Ver recursos" << endl;
    cout << "2. Registrar recurso" << endl;
    cout << "3. Crear Mision" << endl;
    cout << "4. Asignar recurso a mision" << endl;
    cout << "5. Ejecutar mision" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void Controlador::iniciar() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: verRecursos(); break;
            case 2: registrarRecurso(); break;
            case 3: crearMision(); break;
            case 4: asignarRecursoAMision(); break;
            case 5: ejecutarMisionMenu(); break;
            case 6: cout << "Cerrando sistema..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);
}

void Controlador::verRecursos() {
    cout << "\n--- Recursos registrados (" << cantidadRecursos << ") ---" << endl;
    for (int i = 0; i < cantidadRecursos; i++) {
        cout << i << ". ";
        listaRecursos[i]->mostrarInfo();
    }
}

void Controlador::verMisiones() {
    cout << "\n--- Misiones registradas (" << cantidadMisiones << ") ---" << endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        cout << i << ". ";
        listaMisiones[i]->mostrarInfo();
    }
}

void Controlador::registrarRecurso() {
    if (cantidadRecursos == capacidadRecursos) redimensionarRecursos();

    int tipo;
    string id, nombre, extra;
    int capacidad;

    cout << "\nTipo de recurso:\n1. Ambulancia\n2. Helicoptero\n3. Medico\n4. Rescatista\nOpcion: ";
    cin >> tipo;
    cout << "ID: "; cin >> id;
    cout << "Nombre: "; cin >> nombre;

    Recurso* nuevo = nullptr;

    switch (tipo) {
        case 1:
            cout << "Placa: "; cin >> extra;
            cout << "Capacidad: "; cin >> capacidad;
            nuevo = new Ambulancia(id, nombre, extra, capacidad);
            break;
        case 2:
            cout << "Placa: "; cin >> extra;
            cout << "Capacidad: "; cin >> capacidad;
            nuevo = new Helicoptero(id, nombre, extra, capacidad);
            break;
        case 3:
            cout << "Especialidad: "; cin >> extra;
            nuevo = new Medico(id, nombre, extra);
            break;
        case 4:
            cout << "Especialidad: "; cin >> extra;
            nuevo = new Rescatista(id, nombre, extra);
            break;
        default:
            cout << "Tipo invalido." << endl;
            return;
    }

    listaRecursos[cantidadRecursos++] = nuevo;
    cout << "Recurso registrado con exito." << endl;
}

void Controlador::crearMision() {
    if (cantidadMisiones == capacidadMisiones) redimensionarMisiones();

    string id, nombre;
    cout << "ID de la mision: "; cin >> id;
    cout << "Nombre de la mision: "; cin >> nombre;

    listaMisiones[cantidadMisiones++] = new Mision(id, nombre);
    cout << "Mision creada con exito." << endl;
}

void Controlador::asignarRecursoAMision() {
    if (cantidadMisiones == 0) { cout << "No hay misiones creadas." << endl; return; }
    if (cantidadRecursos == 0) { cout << "No hay recursos registrados." << endl; return; }

    verMisiones();
    cout << "Seleccione el indice de la mision: ";
    int im; cin >> im;
    if (im < 0 || im >= cantidadMisiones) { cout << "Indice invalido." << endl; return; }

    verRecursos();
    cout << "Seleccione el indice del recurso: ";
    int ir; cin >> ir;
    if (ir < 0 || ir >= cantidadRecursos) { cout << "Indice invalido." << endl; return; }

    listaMisiones[im]->agregarRecurso(listaRecursos[ir]); // paso por puntero
    cout << "Recurso asignado correctamente." << endl;
}

void Controlador::ejecutarMisionMenu() {
    if (cantidadMisiones == 0) { cout << "No hay misiones creadas." << endl; return; }

    verMisiones();
    cout << "Seleccione el indice de la mision a ejecutar: ";
    int im; cin >> im;
    if (im < 0 || im >= cantidadMisiones) { cout << "Indice invalido." << endl; return; }

    listaMisiones[im]->ejecutarMision();
}

// ---------- HT02: Destruccion segura ----------
Controlador::~Controlador() {
    for (int i = 0; i < cantidadMisiones; i++) {
        delete listaMisiones[i];
    }
    delete[] listaMisiones;

    for (int i = 0; i < cantidadRecursos; i++) {
        delete listaRecursos[i];
    }
    delete[] listaRecursos;

    cout << "Memoria liberada correctamente." << endl;
}
