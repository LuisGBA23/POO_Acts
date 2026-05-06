#include <iostream>
#include <vector>
using namespace std; 

class Animal {
    public:
        virtual ~Animal() {}
        virtual void hacer_sonido() {
            cout<<"Sonido generico"<<endl;
        }
};

class Perro : public Animal {
    public: 
        void hacer_sonido() override { 
            cout<<"Guau!"<<endl;
        }
};

class Gato : public Animal { 
    public: 
        void hacer_sonido() override {
            cout<<"Miau!"<<endl;
        }
};

int main() {
    vector<Animal*> animales= {
        new Perro(),
        new Gato(), 
        new Animal()
    };

    for (auto animal : animales) {
        animal->hacer_sonido();
    }

    return 0;
}