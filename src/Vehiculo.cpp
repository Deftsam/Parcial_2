#include "Vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo(string id, string nombre, string placa, int capacidad)
    : Recurso(id, nombre), placa(placa), capacidad(capacidad) {}

void Vehiculo::mostrarInfo() const {
    Recurso::mostrarInfo();
    cout << " | Placa: " << placa << " | Capacidad: " << capacidad;
}

Vehiculo::~Vehiculo() {}
