#include <iostream>
#include "Empresa.h"
#include "Departamento.h"
#include "Proyecto.h"
#include "TrabajadorBase.h"
#include "Gerente.h"
using namespace std;

int main() {
    Empresa empresa;
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Agregar departamento" << endl;
        cout << "2. Agregar proyecto" << endl;
        cout << "3. Agregar trabajador" << endl;
        cout << "4. Mostrar registro de proyectos de un departamento" << endl;
        cout << "5. Mostrar registro de trabajadores de un proyecto" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombreDep;
                cout << "Ingrese el nombre del departamento: ";
                cin.ignore();
                getline(cin, nombreDep);
                Departamento nuevoDepartamento(nombreDep);
                empresa.agregarDepartamento(nuevoDepartamento);
                break;
            }
            case 2: {
                string nombreProy;
                cout << "Ingrese el nombre del proyecto: ";
                cin.ignore();
                getline(cin, nombreProy);

                int index;
                cout << "Seleccione el departamento al que desea agregar el proyecto:" << endl;
                for (size_t i = 0; i < empresa.departamentos.size(); ++i) {
                    cout << i + 1 << ". " << empresa.departamentos[i].nombre << endl;
                }
                cin >> index;

                if (index > 0 && index <= empresa.departamentos.size()) {
                    Proyecto nuevoProyecto(nombreProy);
                    empresa.departamentos[index - 1].agregarProyecto(nuevoProyecto);
                } else {
                    cout << "Índice de departamento inválido." << endl;
                }
                break;
            }
            case 3: {
                string nombre;
                int id, horas;
                cout << "Ingrese el nombre del trabajador: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el ID del trabajador: ";
                cin >> id;
                cout << "Ingrese las horas trabajadas por el trabajador: ";
                cin >> horas;

                int tipoTrabajador;
                cout << "Seleccione el tipo de trabajador:" << endl;
                cout << "1. Trabajador Base" << endl;
                cout << "2. Gerente" << endl;
                cin >> tipoTrabajador;

                if (tipoTrabajador == 1) {
                    TrabajadorBase* nuevoTrabajador = new TrabajadorBase(nombre, id, horas);
                    empresa.trabajadores.push_back(nuevoTrabajador);
                } else if (tipoTrabajador == 2) {
                    double sueldo;
                    cout << "Ingrese el sueldo del gerente: ";
                    cin >> sueldo;
                    Gerente* nuevoGerente = new Gerente(nombre, id, horas, sueldo);
                    empresa.trabajadores.push_back(nuevoGerente);
                } else {
                    cout << "Tipo de trabajador inválido." << endl;
                }

                int depIndex;
                cout << "Seleccione el departamento al que desea asignar el trabajador:" << endl;
                for (size_t i = 0; i < empresa.departamentos.size(); ++i) {
                    cout << i + 1 << ". " << empresa.departamentos[i].nombre << endl;
                }
                cin >> depIndex;

                if (depIndex > 0 && depIndex <= empresa.departamentos.size()) {
                    int projIndex;
                    cout << "Seleccione el proyecto al que desea asignar el trabajador:" << endl;
                    for (size_t j = 0; j < empresa.departamentos[depIndex - 1].proyectos.size(); ++j) {
                        cout << j + 1 << ". " << empresa.departamentos[depIndex - 1].proyectos[j].nombre << endl;
                    }
                    cin >> projIndex;

                    if (projIndex > 0 && projIndex <= empresa.departamentos[depIndex - 1].proyectos.size()) {
                        empresa.departamentos[depIndex - 1].proyectos[projIndex - 1].agregarTrabajador(empresa.trabajadores.back());
                    } else {
                        cout << "Índice de proyecto inválido." << endl;
                    }
                } else {
                    cout << "Índice de departamento inválido." << endl;
                }
                break;
            }
            case 4: {
                int depIndex;
                cout << "Seleccione el departamento del cual quiere ver el registro de proyectos:" << endl;
                for (size_t i = 0; i < empresa.departamentos.size(); ++i) {
                    cout << i + 1 << ". " << empresa.departamentos[i].nombre << endl;
                }
                cin >> depIndex;

                if (depIndex > 0 && depIndex <= empresa.departamentos.size()) {
                    cout << "Registro de proyectos en el departamento " << empresa.departamentos[depIndex - 1].nombre << ":" << endl;
                    for (size_t i = 0; i < empresa.departamentos[depIndex - 1].proyectos.size(); ++i) {
                        cout << "- " << empresa.departamentos[depIndex - 1].proyectos[i].nombre << endl;
                    }
                } else {
                    cout << "Índice de departamento inválido." << endl;
                }
                break;
            }
            case 5: {
                int depIndex, projIndex;
                cout << "Seleccione el departamento del cual quiere ver el registro de trabajadores:" << endl;
                for (size_t i = 0; i < empresa.departamentos.size(); ++i) {
                    cout << i + 1 << ". " << empresa.departamentos[i].nombre << endl;
                }
                cin >> depIndex;

                if (depIndex > 0 && depIndex <= empresa.departamentos.size()) {
                    cout << "Seleccione el proyecto del cual quiere ver el registro de trabajadores:" << endl;
                    for (size_t j = 0; j < empresa.departamentos[depIndex - 1].proyectos.size(); ++j) {
                        cout << j + 1 << ". " << empresa.departamentos[depIndex - 1].proyectos[j].nombre << endl;
                    }
                    cin >> projIndex;

                    if (projIndex > 0 && projIndex <= empresa.departamentos[depIndex - 1].proyectos.size()) {
                        cout << "Registro de trabajadores en el proyecto " << empresa.departamentos[depIndex - 1].proyectos[projIndex - 1].nombre << ":" << endl;

                        vector<Trabajador*>& trabajadores = empresa.departamentos[depIndex - 1].proyectos[projIndex - 1].trabajadores;
                        double costoTotal = 0;

                        for (size_t k = 0; k < trabajadores.size(); ++k) {
                            cout << "- Nombre: " << trabajadores[k]->nombre << ", Sueldo: " << trabajadores[k]->calcularSueldo() << endl;
                            costoTotal += trabajadores[k]->calcularSueldo();
                        }

                        cout << "Costo total del proyecto: " << costoTotal << endl;
                    } else {
                        cout << "Índice de proyecto inválido." << endl;
                    }
                } else {
                    cout << "Índice de departamento inválido." << endl;
                }
                break;
            }
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    for (auto trabajador : empresa.trabajadores) {
        delete trabajador;
    }
    empresa.trabajadores.clear();

    return 0;
}