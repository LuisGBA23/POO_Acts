#include <iostream> 
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std; 

class Figura { 
    protected:  
        string nombre;

    public: 
        //Metodo constructor:
        Figura(string _nombre): nombre(_nombre) {}

        //Metodos virtuales puros, obligan a las subclases a implementarlos:
        virtual double calcular_area() const= 0;
        virtual double calcular_perimetro() const= 0;
        string getNombre() const { return nombre; }

        double operator+(const Figura & otro) const {
            return this->calcular_area() + otro.calcular_area(); 
        }

        string operator<(const Figura & otro) const { 
            if (otro.calcular_area() < this->calcular_area()) { 
                return "El area de "+this->nombre+" es mayor que el area de "+otro.nombre;
            }
            else if (this->calcular_area() < otro.calcular_area()) {
                return "El area de "+otro.nombre+" es mayor que el area de "+this->nombre;
            }
        }

        string operator==(const Figura & otro) const { 
            return "El area de "+this->nombre+" es igual al area de "+otro.nombre;
        }

        string Figuragrande() { 
            if (this->calcular_area() > 100) {
                return "(Es un "+this->nombre+" GRANDE)";
            }
            return "";
        }

        //Metodo destructor: 
        virtual ~Figura() {}
};

class Circulo : public Figura { 
    double diametro;
    
    public: 
        Circulo(double _diametro, string _nombre= "Circulo"): Figura(_nombre), diametro(_diametro) {}

        double calcular_area() const override {
            return M_PI * pow((this->diametro/2), 2);
        }
        
        double calcular_perimetro() const override {
            return M_PI * this->diametro;
        }
};

class Rectangulo : public Figura { 
    double ancho, alto;

    public: 
        Rectangulo(double _ancho, double _alto, string _nombre= "Rectangulo"): Figura(_nombre), ancho(_ancho), alto(_alto) {}

        double calcular_area() const override { 
            return this->alto * this->ancho;
        }

        double calcular_perimetro() const override { 
            return (this->alto*2) + (this->ancho*2);
        }
};

class Cuadrado : public Figura { 
    double lado; 

    public: 
        Cuadrado(double _lado, string _nombre= "Cuadrado"): Figura(_nombre), lado(_lado) {}

        double calcular_area() const override { 
            return pow(this->lado, 2);
        }

        double calcular_perimetro() const override { 
            return this->lado * 4; 
        }
}; 

class Triangulo : public Figura { 
    double base, lado1, lado2, alto; 

    public: 
        Triangulo(double _b, double _l1, double _l2, double _a, string _n= "Triangulo"): Figura(_n), base(_b), lado1(_l1), lado2(_l2), alto(_a) {}

        double calcular_area() const override { 
            return (this->base*this->alto)/2; 
        }

        double calcular_perimetro() const override { 
            return this->base+this->lado1+this->lado2;
        }
};

//Prueba
void mostrarfigura(Figura* fig) { 
    cout<<fig->getNombre()<<": "<<"[\n"<<
    fixed<<setprecision(2)<<
    "Area= "<<fig->calcular_area()<<
    "\nPerimetro= "<<fig->calcular_perimetro()<<endl;

    string figgrande = fig->Figuragrande();
    if (!figgrande.empty()) {
        cout<<figgrande<<endl;
    }

    cout<<"]\n"<<endl;
}

//Funcion polimorfica 
double funcionpolimorfica(vector<Figura*> & lista_figs) {
    double total= 0; 

    for (const auto & fig : lista_figs) {
        total+= fig->calcular_area();
    }
    return total;
}

int main() { 
    vector<Figura*> figuras = {
        new Circulo(6), 
        new Rectangulo(72, 2), 
        new Cuadrado(12), 
        new Triangulo(5, 7, 8, 15)
    };

    cout<<"=== FIGURAS ===\n"<<endl;
    for (auto fig : figuras) { 
        mostrarfigura(fig);
    }

    cout<<"=== FUNCION POLIMORFICA ===\n"<<endl;
    cout<<funcionpolimorfica(figuras)<<"\n"<<endl;

    cout<<"=== OPERACIONES CON FIGURAS ===\n"<<endl; 
    cout<<(*figuras[1] < *figuras[0])<<endl;
    cout<<(*figuras[3] < *figuras[2])<<endl;
    cout<<(*figuras[1] == *figuras[2])<<endl; 
    double suma_areas= *figuras[0] + *figuras[3];
    cout<<"Suma de areas Circulo y Triangulo: "<<suma_areas<<endl;

    //Limpiar la memoria:
    for (auto fig : figuras) delete fig;
    
    return 0;
}