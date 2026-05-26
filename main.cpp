#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std; 

/////////////////////////////////////////////////////////////////// DEFINICION DE CLASES ///////////////////////////////////////////////////////////////////////////////////////
class Figura { 
    //Atributos protegidos (similar a privados) deben definirse asi para poder acceder a ellos desde subclases:
    protected:  
        string nombre;

    public: 
        //Metodo constructor (equivalente a __init__ en python):
        Figura(string _nombre): nombre(_nombre) {}

        //Metodos virtuales puros, obligan a las subclases a implementarlos:
        virtual double calcular_area() const= 0;
        virtual double calcular_perimetro() const= 0;
        //Metodo getter para obtener el nombre de la figura de forma segura:
        string getNombre() const { return nombre; }

        //Sobrecarga de operdores:
        double operator+(const Figura & otro) const {
            return this->calcular_area() + otro.calcular_area(); 
        } //Equivalente a __add__ en python

        string operator<(const Figura & otro) const { 
            if (otro.calcular_area() < this->calcular_area()) { 
                return "El area de "+this->nombre+" es mayor que el area de "+otro.nombre;
            } else if (this->calcular_area() < otro.calcular_area()) {
                return "El area de "+otro.nombre+" es mayor que el area de "+this->nombre;
            } else {
                return "El area de "+this->nombre+" y la de "+otro.nombre+" son iguales";
            }
        } /**Equivalente al hijo no deseado de __str__ y __lt__ en python, 
            porque obliga a una inocente operacion booleana que solo deberia decir SI o NO a regresar un valor string grandote :v**/

        string operator==(const Figura & otro) const { 
            if(this->calcular_area() == otro.calcular_area()) {
                return "El area de "+this->nombre+" es igual al area de "+otro.nombre;
            } else {
                return "El area de "+this->nombre+" y la de "+otro.nombre+" son diferentes";
            }
        } //Igual que arriba pero con __eq__ y __str__ 🥀

        string Figuragrande() { 
            if (this->calcular_area() > 100) {
                return "(Es un "+this->nombre+" GRANDE)";
            }
            return "";
        }

        //Metodo destructor, no se para que sirve pero se ve importante 👀👀👀: 
        virtual ~Figura() {}
};

//Herencia de clases: 
class Circulo : public Figura { 
    double diametro;
    
    public: 
        //Metodo constructor con herencia (equivalente a super() en python):
        Circulo(double _diametro, string _nombre= "Circulo"): Figura(_nombre), diametro(_diametro) {}

        //Sobrescritura de métodos: 
        double calcular_area() const override {
            return M_PI * pow((this->diametro/2), 2);
        }
        
        double calcular_perimetro() const override {
            return M_PI * this->diametro;
        }
};

//Herencia de clases: 
class Rectangulo : public Figura { 
    double ancho, alto;

    public: 
        //Metodo constructor con herencia (equivalente a super() en python):
        Rectangulo(double _ancho, double _alto, string _nombre= "Rectangulo"): Figura(_nombre), ancho(_ancho), alto(_alto) {}

        //Sobrescritura de métodos: 
        double calcular_area() const override { 
            return this->alto * this->ancho;
        }

        double calcular_perimetro() const override { 
            return (this->alto*2) + (this->ancho*2);
        }
};

//Herencia de clases: 
class Cuadrado : public Figura { 
    double lado; 

    public: 
        //Metodo constructor con herencia (equivalente a super() en python):
        Cuadrado(double _lado, string _nombre= "Cuadrado"): Figura(_nombre), lado(_lado) {}

        //Sobrescritura de métodos: 
        double calcular_area() const override { 
            return pow(this->lado, 2);
        }

        double calcular_perimetro() const override { 
            return this->lado * 4; 
        }
}; 

//Herencia de clases: 
class Triangulo : public Figura { 
    double base, lado1, lado2, alto; 

    public: 
        //Metodo constructor con herencia (equivalente a super() en python):
        Triangulo(double _b, double _l1, double _l2, double _a, string _n= "Triangulo"): Figura(_n), base(_b), lado1(_l1), lado2(_l2), alto(_a) {}

        //Sobrescritura de métodos: 
        double calcular_area() const override { 
            return (this->base*this->alto)/2; 
        }

        double calcular_perimetro() const override { 
            return this->base+this->lado1+this->lado2;
        }
};


/////////////////////////////////////////////////////////////////// CODIGO PRINCIPAL Y FUNCIONES DE UTILIDAD ///////////////////////////////////////////////////////////////////////////////////////
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

//Funcion polimorfica (llama al metodo calcular_area de cada figura sin importar su tipo especifico):
void funcionpolimorfica(vector<Figura*> & lista_figs) {
    double total= 0; 

    for (const auto & fig : lista_figs) {
        total+= fig->calcular_area();
    }
    cout<<"La suma del area de todas las figuras es: "<<total<<endl;
}

//Vector de punteros a objetos de tipo Figura (equivalente a un array/lista de objetos en python):
static vector<Figura*> figuras;
void agregarfigura() {
    string eleccion;
    bool flag= false;
    
    cout<<"Que tipo de figura quieres agrear? (circulo, retangulo, cuadrado, triangulo): ";
    cin>>eleccion;

    if(eleccion == "circulo") {
        double diametro; 
        cout<<"Ingresa el diametro del circulo: ";
        cin>>diametro; 

        figuras.push_back(new Circulo(diametro));
        flag= true;
    } else if(eleccion == "rectangulo") {
        double ancho, alto; 
        cout<<"Ingresa el ancho y alto del rectangulo (separados por un espacio): ";
        cin>>ancho>>alto;

        figuras.push_back(new Rectangulo(ancho, alto));
        flag= true;
    } else if(eleccion == "cuadrado") {
        double lado; 
        cout<<"Ingresa el lado del cuadrado: "; 
        cin>>lado; 

        figuras.push_back(new Cuadrado(lado));
        flag= true;
    } else if(eleccion == "triangulo") {
        double base, lado1, lado2, altura; 
        cout<<"Ingresa la base, dos lados y la altura del triangulo (separados por espacios): "; 
        cin>>base>>lado1>>lado2>>altura;

        figuras.push_back(new Triangulo(base, lado1, lado2, altura));
        flag= true;
    } else {
        cout<<"Figura no valida/Te equivocaste al escribir XDDD. Vuelve a intentar papu"<<endl;
    }

    if(flag) {
        cout<<"Figura agregada con exito :)"<<endl;
    }
};

void ops_with_figs() {
    string operacion;
    int choice1, choice2;

    int x = 1;
    for(auto fig : figuras) {
        cout<<x<<"- "<<fig->getNombre()<<": Area= "<<fig->calcular_area()<<", Perimetro= "<<fig->calcular_perimetro()<<endl;
        x++;
    }

    cout<<"\nEscribe la operacion a realizar (sumar, mayor, igual) y los indices de dos figuras: ";
    cin>>operacion>>choice1>>choice2;
    if(operacion == "sumar") {
        cout<<"El resultado de la suma de areas es: "<<(*figuras[choice1-1] + *figuras[choice2-1])<<endl;
    } else if(operacion == "mayor") {
        cout<<(*figuras[choice1-1] < *figuras[choice2-1])<<endl;
    } else if(operacion == "igual") {
        cout<<(*figuras[choice1-1] == *figuras[choice2-1])<<endl;
    }
};

int main() { 
    int choice;

    //Entrada y salida por consola con un menu simple:
    do {
        cout<<"\n"<<string(50, '=')<<endl;
        cout<<"BASE DE DATOS: FIGURAS :v"<<endl;
        cout<<string(50, '=')<<endl;
        cout<<"1. Agregar nueva figura"<<endl; 
        cout<<"2. Mostrar figuras"<<endl;
        cout<<"3. Operaciones con figuras"<<endl;
        cout<<"4. Sumar el area de todas las figuras (funcion polimorfica)"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Elige una opcion: ";
        cin>>choice;

        switch(choice) {
            case 1: 
                cout<<"\n"<<string(50, '-')<<endl;
                cout<<"AGREGAR FIGURAS"<<endl;
                cout<<string(50, '-')<<endl;
                agregarfigura();
                break;
            case 2: 
                cout<<"\n"<<string(50, '-')<<endl;
                cout<<"FIGURAS GUARDADAS"<<endl;
                cout<<string(50, '-')<<endl;
                for(auto fig : figuras) {
                    mostrarfigura(fig);
                }
                break;
            case 3: 
                cout<<"\n"<<string(50, '-')<<endl;
                cout<<"QUICK FIGURAS DISPONIBLES "<<endl;
                cout<<string(50, '-')<<endl;
                ops_with_figs();
                break;
            case 4: 
                cout<<"\n"<<string(50, '-')<<endl;
                cout<<"SUMA DEL AREA DE TODAS LAS FIGURAS GUARDADAS "<<endl;
                cout<<string(50, '-')<<endl;
                funcionpolimorfica(figuras);
                break;
            case 5: 
                cout<<"Cerrando el programa..."<<endl;
                break; 
            default: 
                cout<<"Esa opcion no esta we, intenta otra vez"<<endl; 
                break;
        }
    } while(choice != 5);

    //Limpiar la memoria al finalizar el programa:
    for (auto fig : figuras) delete fig;
    
    return 0;
}