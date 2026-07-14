#ifndef RECURSO_H
#define RECURSO_H

#include <string>
using namespace std;

// Clase base abstracta. Representa cualquier activo (humano o vehicular)
class Recurso {
protected:
    string id;
    string nombre;

public:
    Recurso(string id, string nombre);

    // Metodo virtual puro -> obliga a las clases hijas a implementarlo (polimorfismo)
    virtual void ejecutarAccion() = 0;

    // Metodo virtual, puede ser sobreescrito por hijos para mostrar info especifica
    virtual void mostrarInfo() const;

    string getId() const;
    string getNombre() const;

    virtual ~Recurso(); // Destructor virtual OBLIGATORIO por la jerarquia polimorfica
};

#endif
