#include <iostream>
#include <vector>
#include <numeric>
using namespace std; 

class Estudiante { 
    protected: 
        string nombre; 
        int edad; 
        vector<float> calificaciones;

    public: 
        Estudiante(string _nombre, int _edad, vector<float> _califs): nombre(_nombre), edad(_edad), calificaciones(_califs) {}

        float calcular_promedio() {
            float suma= accumulate(calificaciones.begin(), calificaciones.end(), 0); 
            float promedio= suma/calificaciones.size(); 
            return promedio;
        }

        void mostrar_info() {
            float promedio= this->calcular_promedio();
            int n= 40; char sm= '='; 
            cout<<"\n"; 
            for (int i= 0; i )


        }
};