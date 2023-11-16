#include <iostream>
#include <string>

using namespace std;

class CtaBanco {
private:
	string nombre;
	double saldo, retirar, deposito;
	
public:
	//Seccion 1
	void setNombre() {
    	cout << "Ingresa tu nombre: ";
    	cin >> nombre;
   		}
   	void setSaldo(int s) {
       saldo = s;
   		}
   	void setDeposito() {
   		cout << "Cantidad a depositar: ";
    	cin >> deposito;
    }
   	bool setRetirar(double cantidad) {
   		bool flag;
   		if(flag) {
   			saldo -= cantidad; 
		   } else {
		   	cout<< "Saldo negativo, revisa tu estado de cuenta";
		}
   		 
	}
	
	//Seccion 2	
	string getNombre() {
		return nombre;
	}
	double getSaldo() {
		return saldo;
	}
	double getDeposito() {
		return (deposito + saldo);
	}
	double getRetirar() {
		return retirar;
	}	
};


int main() {
    CtaBanco miCuenta; // Crear un objeto de la clase 
    miCuenta.setNombre();
    miCuenta.setSaldo(10000);
    miCuenta.setDeposito();
    miCuenta.setRetirar();
    
    cout << "Ingresa cantidad a retirar: ";
    double nuevacantidad;
    cin >> nuevacantidad;
    retirar(nuevaCantidad);
    
    
    cout << "Hola de nuevo " << miCuenta.getNombre() << endl;
    cout << "Tu saldo antes del deposito era de: " << miCuenta.getSaldo() << " vbucks" << endl;
    cout << "Tu saldo tras el deposito es de: " << miCuenta.getDeposito() << " vbucks" << endl;
    
    return 0;
}
