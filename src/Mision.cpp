#include "Mision.h"
#include <iostream>
using namespace std;

Mision::Mision(string id, string nombre, int capacidadInicial)
    : id(id), nombre(nombre), cantidadRecursos(0), capacidadMax(capacidadInicial) {
    recursosAsignados = new Recurso*[capacidadMax];
}

void Mision::redimensionar() {
    int nuevaCapacidad = capacidadMax * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }

    delete[] recursosAsignados; // solo liberamos el arreglo viejo, no los objetos
    recursosAsignados = nuevoArreglo;
    capacidadMax = nuevaCapacidad;
}

void Mision::agregarRecurso(Recurso* r) {
    if (r == nullptr) return;
    if (cantidadRecursos == capacidadMax) {
        redimensionar();
    }
    recursosAsignados[cantidadRecursos] = r;
    cantidadRecursos++;
}

void Mision::ejecutarMision() {
    cout << "\n===== Ejecutando Mision: " << nombre << " (" << id << ") =====" << endl;
    if (cantidadRecursos == 0) {
        cout << "No hay recursos asignados a esta mision." << endl;
        return;
    }
    for (int i = 0; i < cantidadRecursos; i++) {
        recursosAsignados[i]->ejecutarAccion(); // POLIMORFISMO en accion
    }
    cout << "===== Fin de la ejecucion =====" << endl;
}

void Mision::mostrarInfo() const {
    cout << "Mision [" << id << "] " << nombre
         << " - Recursos asignados: " << cantidadRecursos << endl;
    for (int i = 0; i < cantidadRecursos; i++) {
        cout << "   - ";
        recursosAsignados[i]->mostrarInfo();
    }
}

string Mision::getId() const { return id; }
string Mision::getNombre() const { return nombre; }
int Mision::getCantidadRecursos() const { return cantidadRecursos; }

Mision::~Mision() {
    delete[] recursosAsignados; // NO se hace delete de cada Recurso* (no es dueño)
}
