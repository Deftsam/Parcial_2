#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"

class Personal : public Recurso {
protected:
    string especialidad;

public:
    Personal(string id, string nombre, string especialidad);
    void mostrarInfo() const override;
    virtual ~Personal();
};

#endif
