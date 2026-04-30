import math

class Figura: 
    def __init__(self, nombre): 
        self.nombre= nombre

    def calcular_area(self): 
        raise NotImplementedError("Las subclases deben tener calcular_area()")
    
    def calcular_perimetro(self): 
        raise NotImplementedError("Las subclases deben tener calcular_perimetro()")
    
    def __add__(self, other): 
        if isinstance(other, Figura): 
            return self.calcular_area() + other.calcular_area()
        return NotImplemented
    
    def __lt__(self, other):
        if isinstance(other, Figura): 
            if other.calcular_area() < self.calcular_area(): 
                return f"El area de {self.nombre} es mayor que el area de {other.nombre}"
            elif self.calcular_area() < other.calcular_area(): 
                return f"El area de {other.nombre} es mayor que el area de {self.nombre}"
        return NotImplemented
    
    def __eq__(self, other): 
        if isinstance(other, Figura):
            if self.calcular_area() == other.calcular_area(): 
                return f"El area de {self.nombre} es igual al area de {other.nombre}"
        return NotImplemented
        
    def Figuragrande(self): 
        if self.calcular_area() > 100: 
            return f"(Es un {self.nombre} GRANDE)"

    def __str__(self): 
        return f"{self.nombre}= {self.calcular_area():.2f}"
    
class Circulo(Figura): 
    def __init__(self, diametro, nombre= "Circulo"):
        super().__init__(nombre)
        self.nombre= nombre
        self.diametro= diametro

    def calcular_area(self):
        return math.pi * (self.diametro/2) ** 2
    
    def calcular_perimetro(self):
        return math.pi * self.diametro
    
class Rectangulo(Figura): 
    def __init__(self, ancho, alto, nombre= "Rectangulo"):
        super().__init__(nombre)
        self.nombre= nombre
        self.ancho= ancho
        self.alto= alto

    def calcular_area(self):
        return self.ancho * self.alto
    
    def calcular_perimetro(self):
        return (self.alto*2) + (self.ancho*2)
    
class Cuadrado(Figura): 
    def __init__(self, lado, nombre= "Cuadrado"):
        super().__init__(nombre)
        self.nombre= nombre
        self.lado= lado

    def calcular_area(self):
        return self.lado ** 2
    
    def calcular_perimetro(self):
        return self.lado * 4

class Triangulo(Figura): 
    def __init__(self, base, lado1, lado2, alto, nombre= "Triangulo"): 
        super().__init__(nombre)
        self.nombre= nombre
        self.base= base
        self.lado1= lado1
        self.lado2= lado2
        self.alto= alto

    def calcular_area(self):
        return (self.base * self.alto)/2
    
    def calcular_perimetro(self):
        return self.base + self.lado1 + self.lado2
    
#Prueba: 
def mostrarfigura(figura): 
    print(f"{figura.nombre}: [\nArea= {figura.calcular_area():.2f}\nPerimetro= {figura.calcular_perimetro():.2f}\n{figura.Figuragrande()}\n]\n")

figuras= [
    Circulo(6), 
    Rectangulo(72, 2),
    Cuadrado(12),
    Triangulo(5, 7, 8, 15)
]

print("=== FIGURAS ===\n")
for fig in figuras: 
    mostrarfigura(fig)

print("== OPERACIONES CON FIGURAS ==")
area_mayor= figuras[1] < figuras[0]
print(f"{area_mayor}\n")
area_menor= figuras[3] < figuras[2]
print(f"{area_menor}\n")
area_igual= figuras[1] == figuras[2]
print(f"{area_igual}\n")
suma_areas= figuras[0] + figuras[3]
print(f"Suma de areas Circulo y Triangulo: {suma_areas:.2f}")