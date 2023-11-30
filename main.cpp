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
                const vector<Departamento>& departamentos = empresa.obtenerDepartamentos();
                for (size_t i = 0; i < departamentos.size(); ++i) {
                    cout << i + 1 << ". " << departamentos[i].obtenerNombre() << endl;
                }
                cin >> index;

                if (index > 0 && index <= departamentos.size()) {
                    Proyecto nuevoProyecto(nombreProy);
                    empresa.obtenerDepartamento(index - 1).agregarProyecto(nuevoProyecto);
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
                    empresa.agregarTrabajador(nuevoTrabajador);
                } else if (tipoTrabajador == 2) {
                    double sueldo;
                    cout << "Ingrese el sueldo del gerente: ";
                    cin >> sueldo;
                    Gerente* nuevoGerente = new Gerente(nombre, id, horas, sueldo);
                    empresa.agregarTrabajador(nuevoGerente);
                } else {
                    cout << "Tipo de trabajador inválido." << endl;
                }

                int depIndex;
                cout << "Seleccione el departamento al que desea asignar el trabajador:" << endl;
                const vector<Departamento>& departamentos = empresa.obtenerDepartamentos();
                for (size_t i = 0; i < departamentos.size(); ++i) {
                    cout << i + 1 << ". " << departamentos[i].obtenerNombre() << endl;
                }
                cin >> depIndex;

                if (depIndex > 0 && depIndex <= departamentos.size()) {
                    int projIndex;
                    cout << "Seleccione el proyecto al que desea asignar el trabajador:" << endl;
                    const vector<Proyecto>& proyectos = empresa.obtenerDepartamento(depIndex - 1).obtenerProyectos();
                    for (size_t j = 0; j < proyectos.size(); ++j) {
                        cout << j + 1 << ". " << proyectos[j].obtenerNombre() << endl;
                    }
                    cin >> projIndex;

                    if (projIndex > 0 && projIndex <= proyectos.size()) {
                        empresa.obtenerDepartamento(depIndex - 1).obtenerProyectos()[projIndex - 1].agregarTrabajador(empresa.obtenerTrabajadores().back());
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
                const vector<Departamento>& departamentos = empresa.obtenerDepartamentos();
                for (size_t i = 0; i < departamentos.size(); ++i) {
                    cout << i + 1 << ". " << departamentos[i].obtenerNombre() << endl;
                }
                cin >> depIndex;

                if (depIndex > 0 && depIndex <= departamentos.size()) {
                    cout << "Registro de proyectos en el departamento " << empresa.obtenerDepartamento(depIndex - 1).obtenerNombre() << ":" << endl;
                    const vector<Proyecto>& proyectos = empresa.obtenerDepartamento(depIndex - 1).obtenerProyectos();
                    for (size_t i = 0; i < proyectos.size(); ++i) {
                        cout << "- " << proyectos[i].obtenerNombre() << endl;
                    }
                } else {
                    cout << "Índice de departamento inválido." << endl;
                }
                break;
            }
            case 5: {
                int depIndex, projIndex;
                cout << "Seleccione el departamento del cual quiere ver el registro de trabajadores:" << endl;
                const vector<Departamento>& departamentos = empresa.obtenerDepartamentos();
                for (size_t i = 0; i < departamentos.size(); ++i) {
                    cout << i + 1 << ". " << departamentos[i].obtenerNombre() << endl;
                }
                cin >> depIndex;

                if (depIndex > 0 && depIndex <= departamentos.size()) {
                    cout << "Seleccione el proyecto del cual quiere ver el registro de trabajadores:" << endl;
                    const vector<Proyecto>& proyectos = empresa.obtenerDepartamento(depIndex - 1).obtenerProyectos();
                    for (size_t j = 0; j < proyectos.size(); ++j) {
                        cout << j + 1 << ". " << proyectos[j].obtenerNombre() << endl;
                    }
                    cin >> projIndex;

                    if (projIndex > 0 && projIndex <= proyectos.size()) {
                        cout << "Registro de trabajadores en el proyecto " << empresa.obtenerDepartamento(depIndex - 1).obtenerProyectos()[projIndex - 1].obtenerNombre() << ":" << endl;

                        vector<Trabajador*>& trabajadores = empresa.obtenerDepartamento(depIndex - 1).obtenerProyectos()[projIndex - 1].obtenerTrabajadores();
                        double costoTotal = 0;

                        for (size_t k = 0; k < trabajadores.size(); ++k) {
                            cout << "- Nombre: " << trabajadores[k]->getNombre() << ", Sueldo: " << trabajadores[k]->calcularSueldo() << endl;
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
                empresa.eliminarTrabajadores();
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}

