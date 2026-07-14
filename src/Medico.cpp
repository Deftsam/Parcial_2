#include "Medico.h"
#include <iostream>
using namespace std;

Medico::Medico(string id, string nombre, string especialidad)
    : Personal(id, nombre, especialidad) {}

void Medico::ejecutarAccion() {
    cout << ">> Medico " << nombre << ": Estabilizando signos vitales." << endl;
}

void Medico::mostrarInfo() const {
    cout << "[MEDICO] ";
    Personal::mostrarInfo();
    cout << endl;
}

Medico::~Medico() {}
