#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "Vehiculo.h"

class Ambulancia : public Vehiculo {
public:
    Ambulancia(string id, string nombre, string placa, int capacidad);
    void ejecutarAccion() override;
    void mostrarInfo() const override;
    ~Ambulancia();
};

#endif
