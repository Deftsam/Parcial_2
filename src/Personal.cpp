#include "Personal.h"
#include <iostream>
using namespace std;

Personal::Personal(string id, string nombre, string especialidad)
    : Recurso(id, nombre), especialidad(especialidad) {}

void Personal::mostrarInfo() const {
    Recurso::mostrarInfo();
    cout << " | Especialidad: " << especialidad;
}

Personal::~Personal() {}
