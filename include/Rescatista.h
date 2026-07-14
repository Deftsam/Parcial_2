#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "Personal.h"

class Rescatista : public Personal {
public:
    Rescatista(string id, string nombre, string especialidad);
    void ejecutarAccion() override;
    void mostrarInfo() const override;
    ~Rescatista();
};

#endif
