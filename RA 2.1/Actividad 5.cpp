#include <iostream>
#include <vector> 
#include <iomanip>
using namespace std; 

class Empleado { 
    protected: 
        string nombre;
        double salario_base; 

    public: 
        Empleado(string n, double sb): nombre(n), salario_base(sb) {}
        virtual ~Empleado() {}

        virtual double calcular_salario() {return salario_base;}
        string getNombre() const {return nombre;}

        double operator+(Empleado & otro) {
            return this->calcular_salario() + otro.calcular_salario();
        } 

        string operator<(Empleado & otro) {
            if (this->calcular_salario() < otro.calcular_salario()) {
                return otro.nombre+" tiene un mayor salario que "+this->nombre;
            }
            else if (otro.calcular_salario() < this->calcular_salario()) { 
                return this->nombre+" tiene un mayor salario que "+otro.nombre;
            }
            else { 
                return this->nombre+" y "+otro.nombre+" tienen el mismo salario";
            }
        }

};

class EmpleadoComision : public Empleado {
    double ventas;
    double porcentaje_comision; 

    public: 
        EmpleadoComision(string n, double sb, double v, double pcom): Empleado(n, sb), ventas(v), porcentaje_comision(pcom) {}

        double calcular_salario() override { 
            double comision= this->ventas * this->porcentaje_comision / 100;
            return this->salario_base + comision;
        }
};

class EmpleadoTemporal : public Empleado {
    double dias_trabajados;  
    double pago_por_dia;

    public: 
        EmpleadoTemporal(string n, double dt, double ppd, int sb= 0): Empleado(n, sb), dias_trabajados(dt), pago_por_dia(ppd) {}
        
        double calcular_salario() override { 
            return this->dias_trabajados * this->pago_por_dia;
        }
};

void mostrar_salario(Empleado* emp) {
    cout<<"Empleado: "<<emp->getNombre()
    <<fixed<<setprecision(2) 
    <<" -> Salario: $"<<emp->calcular_salario()<<endl;
}

int main() { 
    vector<Empleado*> empleados= {
        new Empleado("Orlando", 3000),
        new EmpleadoComision("Marco", 2000, 50000, 5),
        new EmpleadoTemporal("Carlos", 20, 150)
    };

    cout<<"=== Lista de empleados ==="<<endl;
    for (auto emp : empleados) {
        mostrar_salario(emp);
    }

    cout<<"=== Suma de salarios usando sobrecarga '+' ==="<<endl;
    double suma= *empleados[0] + *empleados[1]; 
    cout<<"Orlando + Marcos= $"<<suma<<endl;
    cout<<(*empleados[1] < *empleados[0])<<endl;

    for (auto emp : empleados) delete emp;

    return 0;
}