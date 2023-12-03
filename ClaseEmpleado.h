//include <F:\UNI TEC\Primer Semestre\Programación Objetos\Proyecto Empleados\ClaseEmpleado.h>

#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
    string username;
    string password;
    int loginIntentos;

public:
    Empleado(string username, string password) : username(username), password(password), loginIntentos(0) {}

    bool login(string intentoUsername, string intentoContrasena) {
        if (intentoUsername == username && intentoContrasena == password) {
            loginIntentos = 0;
            return true;
        } else {
            loginIntentos++;
            return false;
        }
    }

    bool isLocked() {
        if (username == "admin" && loginIntentos >= 3) {
            return true;
        } else {
            return false;
        }
    }

    void eliminarAdmin() {
        username = "";
        password = "";
    }
};
