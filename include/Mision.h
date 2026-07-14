#ifndef MISION_H
#define MISION_H

#include "Recurso.h"
#include <string>
using namespace std;

// Mision NO es dueña de los recursos (agregacion): solo guarda punteros
// Los objetos reales son creados y destruidos por el Controlador
class Mision {
private:
    string id;
    string nombre;
    Recurso** recursosAsignados; // arreglo dinamico de punteros (HT01)
    int cantidadRecursos;
    int capacidadMax;

    void redimensionar(); // duplica la capacidad del arreglo cuando se llena

public:
    Mision(string id, string nombre, int capacidadInicial = 5);

    void agregarRecurso(Recurso* r);   // paso por puntero (HT03)
    void ejecutarMision();             // recorre y llama ejecutarAccion() polimorficamente
    void mostrarInfo() const;

    string getId() const;
    string getNombre() const;
    int getCantidadRecursos() const;

    ~Mision(); // libera SOLO el arreglo de punteros, no los objetos Recurso
};

#endif
