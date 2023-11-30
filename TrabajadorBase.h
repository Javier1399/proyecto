#ifndef TRABAJADORBASE_H
#define TRABAJADORBASE_H

#include "Trabajador.h"

class TrabajadorBase : public Trabajador {
public:
    static constexpr double sueldo_base = 2000;

    TrabajadorBase(std::string nombre, int id, int horas);

    double calcularSueldo() const override;
};

#endif // TRABAJADORBASE_H
