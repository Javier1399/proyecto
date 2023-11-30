#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <string>

class Trabajador {
public:
    std::string nombre;
    int id;
    int horas_trabajadas;

    Trabajador(std::string nombre, int id, int horas);
    virtual double calcularSueldo() const = 0;
    virtual ~Trabajador();
};

#endif // TRABAJADOR_H
