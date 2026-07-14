#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Vehiculo.h"

class Helicoptero : public Vehiculo {
public:
    Helicoptero(string id, string nombre, string placa, int capacidad);
    void ejecutarAccion() override;
    void mostrarInfo() const override;
    ~Helicoptero();
};

#endif
