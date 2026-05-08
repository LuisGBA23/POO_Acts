#include <iostream> 
#include <vector>
#include <map> 
#include <algorithm>
using namespace std; 

class Producto {
    public: 
        string codigo; 
        string nombre; 
        double precio; 
        string categoria; 

    public: 
        Producto(string c, string n, double p, string ca): codigo(c), nombre(n), precio(p), categoria(ca) {}
        ~Producto() {}

        friend ostream& operator<<(ostream& os, const Producto& p) {
            os <<p.codigo<<" | "<<p.nombre<<" | $"<<p.precio<<" | "<<p.categoria; 
            return os;
        }
};

class Inventario { 
    protected: 
        vector<Producto> productos;
        struct Estadisticas {
            string categoria;
            int cantidad;
            double precio;
        };
        vector<Estadisticas> estadisticas= {
            {"Electronica", 0, 0.0},
            {"Ropa", 0, 0.0},
            {"Alimentos", 0, 0.0},
            {"Hogar", 0, 0.0}
        };

    public: 
        void agregar_producto(Producto producto) {
            productos.push_back(producto); 
            this->actualizar_estadisticas(producto); 
            cout<<"Producto '"<<producto.nombre<<"' agregado correctamente"<<endl;
        }

        void actualizar_estadisticas(Producto producto) {
            bool encontrado;
            for(size_t i= 0; i < estadisticas.size(); ++i) {
                if(estadisticas[i].categoria == producto.categoria) {
                    estadisticas[i].cantidad += 1; 
                    estadisticas[i].precio += producto.precio;
                    encontrado= true;
                    break;
                }
            }
            if(!encontrado) {
                estadisticas.push_back({producto.categoria, 1, producto.precio});
            }
        }

        vector<Producto> buscar_por_categoria(string categoria) {
            vector<Producto> resultados; 
            for(auto producto : this->productos) {
                if(producto.categoria == categoria) {
                    resultados.push_back(producto);
                }
            }
            return resultados;
        }

        void mostrar_inventario() {
            if (this->productos.empty()) {
                cout<<"Inventario vacio"<<endl; 
                return; 
            }
            cout<<"\n"<<string(60, '=')<<endl; 
            cout<<"LISTA DE PRODUCTOS (Arreglo (vector en C++) Unidimensional)"<<endl; 
            cout<<string(60, '=')<<endl; 
            cout<<"Codigo | Nombre | Precio | Categoria"<<endl; 
            cout<<string(60, '-')<<endl;
            for(auto producto : this->productos) {
                cout<<producto<<endl;
            }
        }

        void mostrar_estadisticas() {
            cout<<"\n"<<string(60, '=')<<endl; 
            cout<<"ESTADISTICAS POR CATEGORIA (Matriz - Arreglo Bidimensional )"<<endl; 
            cout<<string(60, '=')<<endl; 
            cout<<"Categoria | Cantidad | Valor Total"<<endl; 
            cout<<string(60, '-')<<endl;
            for(size_t i= 0; i < estadisticas.size(); ++i) {
                cout<<estadisticas[i].categoria<<" | "<<estadisticas[i].cantidad<<" | $"<<estadisticas[i].precio<<endl;
            }
        }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    Inventario inventario; 

    vector<Producto> productos_iniciales= {
        Producto("001", "Laptop", 12000.00, "Electronica"),
        Producto("002", "Camiseta", 250.00, "Ropa"),
        Producto("003", "Arroz", 85.50, "Alimentos"),
        Producto("004", "Sarten", 350.00, "Hogar"),
        Producto("005", "Smartphone", 8000.00, "Electronica"),
        Producto("006", "Pantalon", 450.00, "Ropa"),
        Producto("007", "Albedo body pillow", 750.00, "Anime")
    }; 

    for(auto prod : productos_iniciales) {
        inventario.agregar_producto(prod);
    }

    inventario.mostrar_inventario();
    inventario.mostrar_estadisticas();

    cout<<string(60, '=')<<endl;
    string categoria_buscar; 
    cout<<"Buscar productos por categoria: ";
    getline(cin>> ws, categoria_buscar); 
    vector<Producto> resultados= inventario.buscar_por_categoria(categoria_buscar);

    if(!resultados.empty()) {
        cout<<"\nProductos en categoria "<<categoria_buscar<<": "<<endl;
        for(auto prod : resultados) {
            cout<<" - "<<prod.nombre<<" - $"<<prod.precio<<endl;
        }
    } else { 
        cout<<"No se encontraron productos en la categoria '"<<categoria_buscar<<"' "<<endl;
        inventario.mostrar_estadisticas();
    }
    return 0;
}