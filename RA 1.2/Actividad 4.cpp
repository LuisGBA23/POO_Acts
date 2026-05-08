#include <iostream>
#include <vector>
#include <iomanip>
using namespace std; 


class Cuenta {
    //Atributos:
    private: 
        float tasa_interes_anual= 0.05;
        double saldo; 
        bool activa= true;
    public: 
        string numero_cuenta;

    public: 
        Cuenta(string num_c, double s): numero_cuenta(num_c), saldo(s) {}
        ~Cuenta() {}

        bool depositar(double cantidad) {
            if(!activa) {
                cout<<"Error: Cuenta inactiva"<<endl; 
                return false;
            }

            if(cantidad > 0) {
                saldo += cantidad;
                cout<<"Deposito exitoso. Nuevo saldo: "<<saldo<<endl;
                return true;
            } else {
                cout<<"Error: Cantidad invalida"<<endl;
                return false;
            }

        }

        bool retirar(double cantidad) {
            if(!activa) {
                cout<<"Error: Cuenta inactiva"<<endl; 
                return false;
            }

            if(cantidad > 0 && cantidad <= saldo) {
                saldo -= cantidad; 
                cout<<"Retiro exitoso. Nuevo saldo: "<<saldo<<endl;
                return true; 
            } else {
                cout<<"Error: Fondos insuficientes o cantidad invalida"<<endl;
                return false;
            }
        }

        void aplicar_interes() {
            if(activa) {
                double interes= (saldo*tasa_interes_anual)/12; 
                saldo += interes; 
                cout<<"Interes aplicado: +$"<<interes<<endl;
            }
        }

        double get_saldo() {return saldo;}
        bool esta_activa() {return activa;}

        void cerrar_cuenta() {
            activa= false;
            cout<<"Cuenta "<<numero_cuenta<<" cerrada"<<endl;
        }

        friend ostream& operator<<(ostream& os, Cuenta& c) {
            string estado; 
            if(c.activa) {estado= "Activa";} else {estado= "Inactiva";}

            os <<"Cuenta "<<c.numero_cuenta<<" - Saldo: $"<<c.saldo<<" ("<<estado<<")";
            return os;
        }
};

class Cliente {
    protected: 
        int id_cliente; 
        string nombre; 
        string direccion; 
        vector<Cuenta> cuentas; 

    public: 
        Cliente(int id, string nom, string dir): id_cliente(id), nombre(nom), direccion(dir) {}
        ~Cliente() {}

        void agregar_cuenta(Cuenta cuenta) {
            this->cuentas.push_back(cuenta); 
            cout<<"Cuenta: "<<cuenta.numero_cuenta<<" asociada a "<<nombre<<endl;
        }

        void mostrar_resumen() {
            cout<<"\nCliente: "<<nombre<<" (ID: "<<id_cliente<<")"<<endl;
            cout<<"Cuentas: "<<endl; 
            for(auto cuenta : cuentas) {
                cout<<" -> "<<cuenta<<endl;
            }
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    cout<<"SISTEMA BANCARIO"<<endl;
    cout<<string(50, '=')<<endl;

    Cliente cliente1(1001, "Orlando Estrella", "Av. Principal 123");
    Cliente cliente2(1002, "Marco Carranza", "Calle Secundaria 456");

    Cuenta cuenta_ahorro("SA-001", 5000);
    Cuenta cuenta_ahorro2("SA-002", 10000);
    Cuenta cuenta_corriente("SC-001", 20000); 

    cliente1.agregar_cuenta(cuenta_ahorro); 
    cliente1.agregar_cuenta(cuenta_corriente); 
    cliente2.agregar_cuenta(cuenta_ahorro2); 

    cout<<"\n"<<string(50, '=')<<endl;
    cout<<"OPERACIONES"<<endl;
    cout<<string(50, '=')<<endl; 

    cuenta_ahorro.depositar(1500); 
    cuenta_ahorro2.retirar(2000); 
    cuenta_ahorro.aplicar_interes();
    cuenta_ahorro2.aplicar_interes();

    cout<<"\nSaldo actual: $"<<fixed<<setprecision(2)<<cuenta_ahorro.get_saldo()<<endl;
    cout<<"\nSaldo actual: $"<<fixed<<setprecision(2)<<cuenta_ahorro2.get_saldo()<<endl;

    cout<<"\n"<<string(50, '=')<<endl; 
    cout<<"RESUMEN DE CLIENTES"<<endl; 
    cout<<string(50, '=')<<endl;

    cliente1.mostrar_resumen(); 
    cliente2.mostrar_resumen(); 

    cuenta_corriente.cerrar_cuenta();
    cuenta_corriente.retirar(100);
    
    cout<<"\n"<<string(50, '=')<<endl; 
    cout<<"PROGRAMA FINALIZADO"<<endl;

    return 0;
}