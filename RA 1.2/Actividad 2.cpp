#include <iostream> 
#include <vector> 
using namespace std; 

class Calculadora {
    protected: 
        vector<string> historial;

    public: 
        double sumar(double a, double b) { 
            double resultado= a+b; 
            this->guardar_en_historial(to_string(a)+" + "+to_string(b)+" = "+to_string(resultado));
            return resultado;
        }

        double resta(double a, double b) {
            double resultado= a-b; 
            this->guardar_en_historial(to_string(a)+" - "+to_string(b)+" = "+to_string(resultado));
            return resultado;
        }

        double multiplicar(double a, double b) {
            double resultado= a*b; 
            this->guardar_en_historial(to_string(a)+" * "+to_string(b)+" = "+to_string(resultado)); 
            return resultado;  
        }

        double dividir(double a, double b) { 
            if (a != 0 && b != 0) {
                double resultado= a/b; 
                this->guardar_en_historial(to_string(a)+" / "+to_string(b)+" = "+to_string(resultado)); 
                return resultado;
            }
            cout<<"Error: No se puede dividir entre cero"<<endl;
            return 0;
        }

        double potencia(double a, double b) {
            double potencia= a; 
            for (int i= 0; i < (b-1); ++i) {
                potencia= potencia*a;
            }
            this->guardar_en_historial(to_string(a)+" ^ "+to_string(b)+" = "+to_string(potencia));
            return potencia;
        }

        void guardar_en_historial(string operacion) {
            this->historial.push_back(operacion); 
        } 

        void mostrar_historial() {
            cout<<string(30, '-')<<endl;
            cout<<"HISTORIAL DE OPERACIONES"<<endl; 
            cout<<string(30, '-')<<endl;
            for (size_t i= 0; i < historial.size(); ++i) {
                cout<<(i+1)<<". "<<historial[i]<<endl;
            }
        }
};

int main() {
    Calculadora calc;
    int opcion;
    double num1, num2, resultado;

    do {
        cout<<"\n"<<string(30, '=')<<endl;
        cout<<"CALCULADORA"<<endl; 
        cout<<string(30, '=')<<endl;
        cout<<"1. Sumar"<<endl;
        cout<<"2. Restar"<<endl;
        cout<<"3. Multiplicar"<<endl;
        cout<<"4. Dividir"<<endl;
        cout<<"5. Potenciacion"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"\nSeleccione una opcion: ";
        cin>>opcion; 

        switch (opcion) {
            case 1: 
                cout<<"Ingresa el primer numero: "; 
                cin>>num1; 
                cout<<"Ingresa el segundo numero: "; 
                cin>>num2;
                resultado= calc.sumar(num1, num2);
                cout<<"Resultado: "<<resultado<<endl; 
                break;
            case 2: 
                cout<<"Ingresa el primer numero: "; 
                cin>>num1; 
                cout<<"Ingresa el segundo numero: "; 
                cin>>num2;
                resultado= calc.resta(num1, num2);
                cout<<"Resultado: "<<resultado<<endl;
                break;
            case 3: 
                cout<<"Ingresa el primer numero: "; 
                cin>>num1; 
                cout<<"Ingresa el segundo numero: "; 
                cin>>num2;
                resultado= calc.multiplicar(num1, num2);
                cout<<"Resultado: "<<resultado<<endl;
                break;
            case 4: 
                cout<<"Ingresa el primer numero: "; 
                cin>>num1; 
                cout<<"Ingresa el segundo numero: "; 
                cin>>num2;
                resultado= calc.dividir(num1, num2);
                cout<<"Resultado: "<<resultado<<endl;
                break;
            case 5: 
                cout<<"Ingresa el primer numero: "; 
                cin>>num1; 
                cout<<"Ingresa el segundo numero: "; 
                cin>>num2;
                resultado= calc.potencia(num1, num2);
                cout<<"Resultado: "<<resultado<<endl;
                break;
            case 6: 
                cout<<"Programa finalizado."<<endl;
                break;
            default: 
                cout<<"Opcion no valida. intente de nuevo"<<endl;
        }

        string ver_historial; 
        cout<<"\nVer historial? (s/n)"<<endl;
        cin>>ver_historial; 
        
        if (ver_historial == "s") {
            calc.mostrar_historial();
        }
    } while (opcion != 6);

    return 0; 
}