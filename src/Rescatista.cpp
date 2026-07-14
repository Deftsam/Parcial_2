#include "Rescatista.h"
#include <iostream>
using namespace std;

Rescatista::Rescatista(string id, string nombre, string especialidad)
    : Personal(id, nombre, especialidad) {}

void Rescatista::ejecutarAccion() {
    cout << ">> Rescatista " << nombre << ": Buscando sobrevivientes en escombros." << endl;
}

void Rescatista::mostrarInfo() const {
    cout << "[RESCATISTA] ";
    Personal::mostrarInfo();
    cout << endl;
}

Rescatista::~Rescatista() {}
