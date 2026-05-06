#include <iostream>
using namespace std; 

class CuentaBancaria { 
    private: 
        double saldo= 0; 

    public: 
        CuentaBancaria(double saldo_in): saldo(saldo_in) {}
        ~CuentaBancaria() {}

        void depositar(double cantidad) { 
            if (cantidad > 0) { 
                this->saldo += cantidad; 
                cout<<"Se hizo un deposito de forma exitosa. El saldo actual es de: $"<<this->saldo<<endl;
            } else { 
                cout<<"La cantidad a ingresar no es una cifra valida"<<endl; 
            }
        }

        void retirar(double cantidad) { 
            if (cantidad > 0 && this->saldo >= cantidad) { 
                this->saldo -= cantidad; 
                cout<<"Se hizo un retiro de forma exitosa. El saldo actual es de: $"<<this->saldo<<endl;
            } else { 
                cout<<"La cantidad a retirar no es valida o el saldo es insuficiente"<<endl;
            }
        }

        void get_saldo() {
            cout<<"Tu saldo actual es de: $"<<this->saldo<<endl;
        }
};

int main() {
    CuentaBancaria mi_cuenta(1000); 
    mi_cuenta.depositar(500); 
    mi_cuenta.retirar(200); 
    mi_cuenta.get_saldo();

    return 0;
}