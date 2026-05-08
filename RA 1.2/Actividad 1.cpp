#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std; 

class Estudiante { 
    protected: 
        string nombre; 
        int edad; 
        vector<float> calificaciones;

    public: 
        Estudiante(string _nombre, int _edad, vector<float> _califs): nombre(_nombre), edad(_edad), calificaciones(_califs) {}
        ~Estudiante() {}

        float calcular_promedio() {
            float suma= accumulate(calificaciones.begin(), calificaciones.end(), 0); 
            float promedio= suma/calificaciones.size(); 
            return promedio;
        }

        void mostrar_info() {
            float promedio= this->calcular_promedio();
            cout<<"\n"<<string(40, '=')<<endl;
            cout<<"INFORME DEL ESTUDIANTE"<<endl;
            cout<<string(40, '=')<<endl;
            cout<<"Nombre: "<<this->nombre<<endl; 
            cout<<"Edad: "<<this->edad<<endl;
            cout<<"Calificaciones: ";
            for (auto cal : calificaciones) {
                cout<<cal<<" ";
            }
            cout<<"Promedio: "<<fixed<<setprecision(2)<<promedio<<endl;
            cout<<string(40, '=')<<endl; 
        }
};

int main() {
    cout<<"SISTEMA DE REGISTRO DE ESTUDIANTES"<<endl;
    cout<<string(40, '-')<<endl; 

    string nombre; 
    int edad, var; 
    cout<<"Ingresa el nombre del estudiante: "; 
    getline(cin>> ws, nombre);
    cout<<"Ingresa la edad del estudiante: "; 
    cin>>edad; 
    cout<<"Ingresa el numero de calificaciones a registrar: "; 
    cin>>var; 

    vector<float> calificaciones;
    for (int i= 0; i < var; ++i) { 
        float cal; 
        cout<<"Ingrese la "<<(i+1)<<" calificacion: "; 
        cin>>cal;
        calificaciones.push_back(cal); 
    }

    Estudiante estudiante1(nombre, edad, calificaciones);
    estudiante1.mostrar_info(); 

    return 0; 
}