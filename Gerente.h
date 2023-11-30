#ifndef GERENTE_H
#define GERENTE_H

#include "Trabajador.h"

class Gerente : public Trabajador {
public:
    double sueldo;

    Gerente(std::string nombre, int id, int horas, double sueldo);

    double calcularSueldo() const override;
};

#endif // GERENTE_H
