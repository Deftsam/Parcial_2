#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Recurso.h"
#include "Mision.h"

class Controlador {
private:
    Recurso** listaRecursos;
    int cantidadRecursos;
    int capacidadRecursos;

    Mision** listaMisiones;
    int cantidadMisiones;
    int capacidadMisiones;

    void redimensionarRecursos();
    void redimensionarMisiones();

    void cargarDatosPrueba(); // metodo "oculto" (privado) - HU05
    void mostrarMenu();

    void verRecursos();
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMisionMenu();
    void verMisiones();

public:
    Controlador();
    void iniciar(); // unico metodo publico que usa main.cpp
    ~Controlador();
};

#endif
