#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>
#include <vector>
#include "Trabajador.h"

using namespace std;

class Proyecto {
private:
    string nombre;
    vector<Trabajador*> trabajadores;

public:
    Proyecto(const string& nombre);
    string obtenerNombre() const;
    void establecerNombre(const string& nuevoNombre);
    void agregarTrabajador(Trabajador* trabajador);
    vector<Trabajador*>& obtenerTrabajadores();
};

#endif 


