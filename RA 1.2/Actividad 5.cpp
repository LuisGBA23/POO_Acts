#include <iostream> 
#include <vector>
#include <numeric>
#include <stdexcept>
using namespace std;

class Estudiante { 
    protected: 
        string matricula; 
        string nombre; 
        string grupo; 
        vector<float> calificaciones;
        vector<string> materias;

    public: 
        Estudiante(string _matricula, string _nombre, string _grupo): matricula(_matricula), nombre(_nombre), grupo(_grupo) {}
        ~Estudiante() {}
        string getMatricula() {return matricula;}

        void agregar_materia(string _materia, float _calif) { 
            this->materias.push_back(_materia);
            this->calificaciones.push_back(_calif);
        }

        float calcular_promedio() {
            if (calificaciones.empty()) {
                return 0.0; 
            }
            return accumulate(calificaciones.begin(), calificaciones.end(), 0)/calificaciones.size();
        }

        string obtener_estado() { 
            float promedio= this->calcular_promedio(); 
            if (promedio >= 60) { 
                return "APROBADO"; 
            } else {
                return "REPROBADO";
            }
        }

        friend ostream & operator<<(ostream & os, Estudiante & est) {
            float promedio= est.calcular_promedio();
            os <<est.matricula<<" | "<<est.nombre<<" | "<<est.grupo<<" | Prom: "<<promedio<<" | "<<est.obtener_estado(); 
            return os;
        }
};

class SistemaEscolar { 
    protected:
        vector<Estudiante*> estudiantes;

    public: 
        ~SistemaEscolar() {}

        void registra_estudiante() {
            int n= 50;
            char sim= '=';
            cout<<"\n";
            for (int i=0; i < n; i++) {cout<<sim;}
            cout<<"\nREGISTRO DE ESTUDIANTE\n";
            for (int i=0; i < n; i++) {cout<<sim;}
            cout<<"\n"<<endl; 

            string matr;
            cout<<"Matricula: "; 
            cin>>matr;
            cout<<endl;  

            for (const auto& est : estudiantes) { 
                if (est->getMatricula() == matr) {
                    cout<<"Ya existe un estudiante con esta matricula"<<endl; 
                    return;
                }
            }

            string nom; 
            cout<<"Nombre completo: ";
            cin>>nom; 
            cout<<endl;
            string grp; 
            cout<<"Grupo: ";
            cin>>grp; 
            cout<<endl;

            Estudiante estudiante(matr, nom, grp);

            cout<<"\nRegistrar calificaciones"<<endl; 
            while (true) {
                string mat; 
                cout<<"Nombre de la materia (Enter para terminar): ";
                cin>>mat; 
                cout<<endl;
                if (mat == "") {break;}

                try { 
                    float cal; 
                    cout<<"Calificacion de "<<mat<<": ";
                    cin>>mat; 
                    cout<<endl;
                    estudiante.agregar_materia(mat, cal);
                }
                catch(const invalid_argument& e) { 
                    cout<<"Calificacion invalida. Use numeros.";
                }
            }

            estudiantes.push_back(estudiante);
        }
};