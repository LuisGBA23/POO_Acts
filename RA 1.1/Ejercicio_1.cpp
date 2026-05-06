#include <iostream>
using namespace std; 

class Persona {
    protected: 
        string nombre; 
        int edad; 

    public: 
        Persona(string _nombre, int _edad): nombre(_nombre), edad(_edad) {}
        ~Persona() {}

        void saludar() {
            cout<<"hola, mi nombre es "<<this->nombre<<" y tengo "<<this->edad<<"anios"<<endl;
        }

        void cumple() { 
            this->edad += 1;
            cout<<this->nombre<<" ha cumplido anios! Ahora tiene "<<this->edad<<" anios"<<endl;
        }
};

int main() {
    Persona persona1("Orlando", 17);
    Persona persona2("Marco", 16);

    persona1.saludar(); 
    persona2.saludar(); 

    persona1.cumple();

    return 0;
}