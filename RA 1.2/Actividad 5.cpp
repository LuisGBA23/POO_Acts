#include <iostream> 
#include <vector>
#include <numeric>
#include <stdexcept>
#include <map> 
using namespace std;

class Estudiante { 
    public: 
        string matricula; 
        string nombre; 
        string grupo; 
        vector<float> calificaciones;
        vector<string> materias;

    public: 
        Estudiante(string _matricula, string _nombre, string _grupo): matricula(_matricula), nombre(_nombre), grupo(_grupo) {}
        ~Estudiante() {}

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
        vector<Estudiante> estudiantes;

    public: 
        ~SistemaEscolar() {}

        void registra_estudiante() {
            cout<<"\n"<<string(50, '=')<<endl;
            cout<<"REGISTRO DE ESTUDIANTE";
            cout<<"\n"<<string(50, '=')<<endl;

            string matr;
            cout<<"Matricula: "; 
            cin>>matr;
            cout<<endl;  

            for (auto est : estudiantes) { 
                if (est.matricula == matr) {
                    cout<<"Ya existe un estudiante con esta matricula"<<endl; 
                    return;
                }
            }

            string nom, grp; 
            cout<<"Nombre completo: ";
            getline(cin>> ws, nom);
            cout<<endl;
            cout<<"Grupo: ";
            cin>>grp; 
            cout<<endl;

            Estudiante estudiante(matr, nom, grp);

            cout<<"\nRegistrar calificaciones"<<endl; 
            while (true) {
                string mat; 
                cout<<"Nombre de la materia (Enter para terminar): ";
                getline(cin >> ws, mat); 
                cout<<endl;
                if (mat.empty()) break;

                try { 
                    float cal; 
                    cout<<"Calificacion de "<<mat<<": ";
                    cin>>cal; 
                    cout<<endl;
                    estudiante.agregar_materia(mat, cal);
                }
                catch(const invalid_argument& e) { 
                    cout<<"Calificacion invalida. Use numeros."<<endl;
                }
            }

            estudiantes.push_back(estudiante);
            cout<<"Estudiante "<<nom<<" registrado exitosamente"<<endl;
        }
    
    void mostrar_todos() {
        if (estudiantes.empty()) {
            cout<<"No hay estudiantes registrados"<<endl;
            return;
        }

        cout<<"\n"<<string(70, '=')<<endl; 
        cout<<"LISTA DE ESTUDIANTES"<<endl; 
        cout<<string(70, '=')<<endl;
        cout<<"Matricula | Nombre | Grupo | Promedio | Estado"<<endl;
        cout<<string(70, '-')<<endl;
        for (auto est : estudiantes) {
            cout<<est<<endl;
        }
    }

    void buscar_estudiantes() {
        string matr; 
        cout<<"Ingrese matricula a buscar: ";
        cin>>matr;

        for (auto est : estudiantes) {
            if (est.matricula == matr) {
                cout<<"\n"<<string(50, '=')<<endl;
                cout<<"DATOS DEL ESTUDIANTE"<<endl;
                cout<<string(50, '=')<<endl;
                cout<<"Matricula: "<<est.matricula<<endl;
                cout<<"Nombre: "<<est.nombre<<endl;
                cout<<"Grupo: "<<est.grupo<<endl;
                cout<<"\nMaterias y calificaciones:"<<endl;
                for (size_t i= 0; i < est.materias.size(); ++i) {
                    cout<<" "<<(i+1)<<". "<<est.materias[i]<<est.calificaciones[i]<<endl;
                }
                cout<<"\nPromedio: "<<est.calcular_promedio()<<endl;
                cout<<"Estado: "<<est.obtener_estado()<<endl;
                return;
            }
        }
        cout<<"No se encontro estudiante con matricula "<<matr<<endl; 
    }

    void generar_reporte_por_grupo() {
        if (estudiantes.empty()) {
            cout<<"No hay estudiantes registrados"<<endl;
            return;
        }

        map<string, vector<Estudiante>> grupos;
        
    }
};