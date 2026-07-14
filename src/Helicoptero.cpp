#include "Helicoptero.h"
#include <iostream>
using namespace std;

Helicoptero::Helicoptero(string id, string nombre, string placa, int capacidad)
    : Vehiculo(id, nombre, placa, capacidad) {}

void Helicoptero::ejecutarAccion() {
    cout << ">> Helicoptero " << nombre << ": Realizando extraccion aerea." << endl;
}

void Helicoptero::mostrarInfo() const {
    cout << "[HELICOPTERO] ";
    Vehiculo::mostrarInfo();
    cout << endl;
}

Helicoptero::~Helicoptero() {}
