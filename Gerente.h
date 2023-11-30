#ifndef GERENTE_H
#define GERENTE_H

#include "Trabajador.h"
using namespace std;

class Gerente : public Trabajador {
private:
    double sueldo;

public:
    Gerente(const std::string& nombre, int id, int horas, double sueldo);

    double calcularSueldo() const override;

    double getSueldo() const;
    void setSueldo(double nuevoSueldo);
};

#endif 