#include <iostream> 
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std; 

class Forma { 
    public: 
        virtual ~Forma() {}
        virtual double area() const= 0;
};

class Circulo : public Forma { 
    double radio; 

    public:  
        Circulo(double r): radio(r) {}

        double area() const override { 
            return M_PI * pow(this->radio, 2); 
        }
};

class Rectangulo : public Forma { 
    double ancho; 
    double alto; 

    public: 
        Rectangulo(double an, double al): ancho(an), alto(al) {}

        double area() const override { 
            return this->ancho * this->alto;
        }
};

class Triangulo : public Forma { 
    double base; 
    double altura; 

    public: 
        Triangulo(double b, double al): base(b), altura(al) {}

        double area() const override { 
            return (this->base*this->altura)/2;
        }
};

//Funcion polimorfica:
void mostrar_area(Forma* frm) { 
    cout<<"El area es: "<<fixed<<setprecision(2)<<frm->area()<<endl;
}

//Prueba:
int main() {
    vector<Forma*> figuras= { 
        new Circulo(5), 
        new Rectangulo(4, 6),
        new Circulo(2.5),
        new Rectangulo(3, 3), 
        new Triangulo(5, 2)
    };

    for (auto fig : figuras) {
        mostrar_area(fig);
    }

    for (auto fig : figuras) delete fig;
    return 0;
}