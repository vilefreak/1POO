#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Empleado {
public:
    int id;
    string name;
    double sueldo;

    Empleado() : id(0), name(""), sueldo(1000) {}  // default constructor
    Empleado(int id, string name) : id(id), name(name), sueldo(1000) {}
};
