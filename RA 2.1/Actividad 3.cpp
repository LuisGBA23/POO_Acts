#include <iostream>
using namespace std;

class Vector { 
    protected: 
        float x; 
        float y;
    
    public: 
        Vector(float _x, float _y): x(_x), y(_y) {}
        ~Vector() {}

        Vector operator-() const {
            return Vector(-this->x, -this->y);
        }

        Vector operator+(Vector & otro) const { 
            return Vector(this->x + otro.x, this->y + otro.y);
        }
        Vector operator*(float escalar) const { 
            return Vector(this->x * escalar, this-> y * escalar);
        }
        friend Vector operator*(float escalar, const Vector& v) { 
            return v * escalar;
        }

        Vector operator*(Vector & otro) const {
            return Vector(this->x * otro.x, this->y * otro.y);
        }

        bool operator==(Vector & otro) const { 
            return this->x == otro.x and this->y == otro.y;
        }

        friend ostream& operator<<(ostream& os, const Vector& v) { 
            os << "("<<v.x<<", "<<v.y<<")";
            return os;
        }
};

int main() { 
    //Prueba 
    Vector v1(3, 4);
    Vector v2(1, -2); 

    cout<<"v1 = "<<v1<<endl;
    cout<<"v2 = "<<v2<<endl;
    cout<<"-v1 = "<<-v1<<endl;
    cout<<"v1 + v2 = "<<v1 + v2<<endl;
    cout<<"v1 * 3 = "<<v1 * 3<<endl;
    cout<<"5 * v2 = "<<5 * v2<<endl; 
    cout<<"v1 == v2? "<<(v1 == v2)<<endl;
    cout<<"v1 * v2 = "<<v1 * v2<<endl;

    Vector v3(3, 4); 
    cout<<"v1 == v3? "<<(v1 == v3)<<endl;
}

