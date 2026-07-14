#include "Recurso.h"
#include <iostream>
using namespace std;

Recurso::Recurso(string id, string nombre) : id(id), nombre(nombre) {}

void Recurso::mostrarInfo() const {
    cout << "[ID: " << id << "] Nombre: " << nombre;
}

string Recurso::getId() const { return id; }
string Recurso::getNombre() const { return nombre; }

Recurso::~Recurso() {
    // Destructor virtual vacio, permite destruccion correcta en cadena
}
