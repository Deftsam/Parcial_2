#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"

// Clase intermedia abstracta (sigue sin implementar ejecutarAccion)
class Vehiculo : public Recurso {
protected:
    string placa;
    int capacidad;

public:
    Vehiculo(string id, string nombre, string placa, int capacidad);
    void mostrarInfo() const override;
    virtual ~Vehiculo();
};

#endif
