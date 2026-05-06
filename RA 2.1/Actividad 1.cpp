#include <iostream> 
using namespace std; 

class Electrodomestico {
    public: 
        string marca; 
        string modelo; 
        double consumo_watts;

    public: 
        Electrodomestico(string ma, string mo, double cw): marca(ma), modelo(mo), consumo_watts(cw) {}
        virtual ~Electrodomestico() {}

        virtual void encender() {
            cout<<"Electrodomestico encendido"<<endl;
        }

        void apagar() {
            cout<<"Electrodomestico apagado"<<endl;
        }
};

class Lavadora : public Electrodomestico {
    double capacidad_kg;

    public:
        Lavadora(string ma, string mo, double cw, double ck): Electrodomestico(ma, mo, cw), capacidad_kg(ck) {}

        void lavar() {
            cout<<"Ciclo de lavado activado"<<endl;
        }
};

class Refrigerador : public Electrodomestico { 
    double temperatura; 

    public: 
        Refrigerador(string ma, string mo, double cw, double t): Electrodomestico(ma, mo,cw), temperatura(t) {}

    void encender() override { 
        cout<<"Refrigerador encendido. Temperatura ajustada a "<<this->temperatura<<" grados"<<endl;
    }
};

int main() { 
    //Prueba 
    Lavadora lavadora("Samsung", "WW90", 2000, 9);
    Refrigerador refri("LG", "GB450", 1500, 4);

    cout<<lavadora.marca<<" "<<lavadora.modelo<<endl;
    lavadora.encender(); //metodo heredado
    lavadora.lavar();
    cout<<"Consumo de watts de la lavadora: "<<lavadora.consumo_watts<<endl;
    lavadora.apagar(); 

    cout<<refri.marca<<" "<<refri.modelo<<endl;
    refri.encender(); //metodo sobrescrito
    refri.apagar(); 
}