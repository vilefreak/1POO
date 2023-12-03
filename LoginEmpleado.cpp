//DATOS ADMIN: admin, pass1234
//DATOS SUPER ADMIN: superadmin, MaxVerstappen

#include <iostream>
#include <string>
#include "ClaseEmpleado.h"

using namespace std;

int main() {
    Empleado admin("admin", "pass1234");
    Empleado superadmin("superadmin", "MaxVerstappen");

    string intentoUsername;
    string intentoContrasena;

    while (true) {
        cout << "Ingresa tu nombre de usuario: ";
        cin >> intentoUsername;
        cout << "Ingresa tu contraseña: ";
        cin >> intentoContrasena;

        if (admin.login(intentoUsername, intentoContrasena)) {
            cout << "Bienvenido admin.\n";
            break;
        } else if (admin.isLocked()) {
            cout << "Admin bloqueado, ingresar con superadmin.\n";
            admin.eliminarAdmin();
        } else if (superadmin.login(intentoUsername, intentoContrasena)) {
            cout << "Bienvenido superadmin.\n";
            break;
        } else {
            cout << "Datos invalidos.\n";
        }
    }

    return 0;
}
