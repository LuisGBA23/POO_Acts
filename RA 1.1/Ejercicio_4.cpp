#include <iostream> 
using namespace std; 

class Motor { 
    protected: 
        string tipo; 
        double caballos; 

    public: 
        Motor(string _tipo, double _caballos): tipo(_tipo), caballos(_caballos) {}
        ~Motor() {}

        string describir() { 
            return "Motor "+this->tipo+" de "+to_string(this->caballos)+" CV";
        }
};

class Coche {
    protected: 
        string marca; 
        string modelo; 
        Motor motor;

    public: 
        Coche(string _marca, string _modelo, Motor _motor): marca(_marca), modelo(_modelo),  motor(_motor) {}
        ~Coche() {}

        void mostrar_info() {
            cout<<"Coche: "<<this->marca<<" "<<this->modelo<<endl;
            cout<<this->motor.describir()<<endl;
        }
};

int main() { 
    Motor motor_v8("gasolina", 450); 

    Coche automovil("Nissan", "Sentra", motor_v8); 

    automovil.mostrar_info();

    return 0;
}