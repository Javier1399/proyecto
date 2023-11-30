#ifndef TRABAJADORBASE_H
#define TRABAJADORBASE_H

#include "Trabajador.h"
using namespace std;

class TrabajadorBase : public Trabajador {
protected:
    static constexpr double sueldo_base = 2000;

public:
    TrabajadorBase(const string& nombre, int id, int horas);

    double calcularSueldo() const override;
};

#endif 