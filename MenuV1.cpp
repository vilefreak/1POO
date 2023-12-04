#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "ClaseEmpleado.h"

using namespace std;

struct MatchId {
    int id;
    MatchId(int id) : id(id) {}
    bool operator()(const Empleado& empleado) const {
        return empleado.id == id;
    }
};

int main() {
    vector<Empleado> empleados(3);

    // Initialize the first 3 employees
    for (int i = 0; i < 3; ++i) {
        stringstream ss;
        ss << (i + 1);
        string idStr = ss.str();
        empleados[i] = Empleado(i + 1, "user" + idStr);
    }
    int opcion;
    do {
        cout << "1. Agregar Empleado\n2. Mostrar Empleados\n3. Modificar Empleado\n4. Eliminar Empleado\n5. Asignar Salario y Bonos\n6. Salir\n";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int id;
            string name;
            cout << "Ingresa ID: ";
            cin >> id;
            cout << "Ingresa nombre: ";
            cin >> name;
            empleados.push_back(Empleado(id, name));
            break;
        }
        case 2: {
            for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
                cout << "ID: " << it->id << ", Nombre: " << it->name << ", Salario: " << it->sueldo << "\n";
            }
            break;
        }
        case 3: {
            int id;
            string name;
            cout << "Ingresa ID: ";
            cin >> id;
            cout << "Ingresa nuevo nombre: ";
            cin >> name;
            for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
                if (it->id == id) {
                    it->name = name;
                    break;
                }
            }
            break;
        }
        case 4: {
            int id;
            cout << "Ingresa ID: ";
            cin >> id;
            empleados.erase(remove_if(empleados.begin(), empleados.end(), MatchId(id)), empleados.end());
            break;
	    }
        case 5: {
            int id;
            double salarioBase, actividadesExtra, horasExtra;
            cout << "Ingresa ID: ";
            cin >> id;
            cout << "Ingresa salario base: ";
            cin >> salarioBase;
            cout << "Ingresa actividades extra: ";
            cin >> actividadesExtra;
            cout << "Ingresa horas extra: ";
            cin >> horasExtra;
            double salarioNuevo = salarioBase + actividadesExtra * 175 + horasExtra * 450;
            for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
                if (it->id == id) {
                    it->sueldo = salarioNuevo;
                    break;
                }
            }
            break;
        }
        case 6:
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);

    return 0;
}
