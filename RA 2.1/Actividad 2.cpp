#include <iostream> 
using namespace std;

class Volador { 
    public: 
        virtual void moverse() {
            cout<<"volando"<<endl;
        }
};

class Nadador { 
    public: 
        virtual void movrese() {
            cout<<"nadando"<<endl;
        }
};

//Clase sin sobrescritura
class Pato : public Volador, public Nadador {

};

//Clase con sobrescritura
class PatoExplicito : public Volador, public Nadador { 
    public: 
        void moverse() override { 
            Volador::moverse(); 
            Nadador::movrese(); 
            cout<<"Tambien camino"<<endl;
        }
};

int main() {
    cout<<"======Sin sobrescritura======"<<endl;
    Pato p;
    p.moverse();

    cout<<"======Con sobrescritura explicita======"<<endl;
    PatoExplicito p2; 
    p2.moverse();
}

