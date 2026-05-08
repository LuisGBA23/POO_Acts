#include <iostream> 
#include <vector>
#include <numeric>
#include <stdexcept>
#include <map> 
#include <iomanip>
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
    public:
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
            while(true) {
                string mat; 
                cout<<"Nombre de la materia (Enter para terminar): ";
                cin>>mat; 
                cout<<endl;
                if (mat == "") {break; return;}

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
        map<string, vector<Estudiante>>::iterator itr;
        for (const auto& est : estudiantes) {
            grupos[est.grupo].push_back(est);
        }
        
        cout<<"\n"<<string(70, '=')<<endl;
        cout<<"REPORTE POR GRUPO"<<endl;
        cout<<string(70, '=')<<endl;

        for (itr= grupos.begin(); itr != grupos.end(); ++itr) {
            cout<<"\nGRUPO: "<<itr->first<<endl;
            cout<<string(50, '-')<<endl;
            cout<<"Matricula | Nombre | Promedio | Estado"<<endl;
            cout<<string(50, '-')<<endl;
            for (int i= 0; i< itr->second.size(); ++i) {
                cout<<itr->second[i].matricula<<" | "
                <<left<<setw(15)<< itr->second[i].nombre <<" | "
                <<fixed<<setprecision(2)<<itr->second[i].calcular_promedio()<<" | "
                <<itr->second[i].obtener_estado()<<endl;
            }
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    SistemaEscolar sistema; 
    int opcion;

    Estudiante ejemplo("A001", "Orlando Estrella", "403");
    ejemplo.agregar_materia("Programacion", 95); 
    ejemplo.agregar_materia("Matematicas", 88);
    sistema.estudiantes.push_back(ejemplo); 

    Estudiante ejemplo2("A002", "Carlos Silos", "408"); 
    ejemplo2.agregar_materia("Programacion", 45);
    ejemplo2.agregar_materia("Matematicas", 52); 
    sistema.estudiantes.push_back(ejemplo2); 

    do { 
        cout<<"\n"<<string(50, '=')<<endl;
        cout<<"SISTEMA DE GESTION ESCOLAR"<<endl;
        cout<<string(50, '=')<<endl;
        cout<<"1. Registrar estudiante"<<endl;
        cout<<"2. Mostrar todos los estudiantes"<<endl;
        cout<<"3. Buscar estudiante"<<endl;
        cout<<"4. Reporte por grupo"<<endl;
        cout<<"5. Agregar calificaciones a estudiante existente"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Elige una opcion: ";
        cin>>opcion;
        cout<<string(50, '=')<<endl;

        switch(opcion) {
            case 1: 
                sistema.registra_estudiante();
                break;
            case 2: 
                sistema.mostrar_todos(); 
                break;
            case 3: 
                sistema.buscar_estudiantes(); 
                break;
            case 4: 
                sistema.generar_reporte_por_grupo();
                break;
            case 5: {
                string matricula;
                string materia; 
                float calif;
                bool encontrado= false; 
                cout<<"Matricula del estudiante: "; 
                getline(cin>> ws, matricula);
                for(auto& est : sistema.estudiantes) {
                    if(est.matricula == matricula) {
                        cout<<"Materia: "; 
                        getline(cin>> ws, materia);
                        try { 
                            cout<<"Calificacion: "; 
                            cin>>calif; 
                            est.agregar_materia(materia, calif); 
                            cout<<"Calificacion agregada"<<endl;
                        } catch(const logic_error& e) {
                            cout<<"Calificacion invalida"<<endl; 
                        }
                        encontrado= true; 
                        break;
                    }
                }
                if(!encontrado) {
                    cout<<"Estudiante no encontrado"<<endl;
                    break;
                }
            }
            case 6: 
                cout<<"Programa finalizado"<<endl; 
                break;
            default: 
                cout<<"Opcion invalida, intente de nuevo"<<endl; 
                break; 
        }

    } while(opcion != 6);

    return 0;
}