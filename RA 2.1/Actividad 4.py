import math 

class Forma: 
    def area(self): 
        raise NotImplementedError("Las subclases deben implementar area()")
    
class Circulo(Forma): 
    def __init__(self, radio):
        self.radio= radio
    
    def area(self): 
        return math.pi * self.radio ** 2
    
class Rectangulo(Forma): 
    def __init__(self, ancho, alto): 
        self.ancho= ancho 
        self.alto= alto

    def area(self):
        return self.ancho * self.alto
    

class Triangulo(Forma): 
    def __init__(self, base, altura): 
        self.base= base 
        self.altura= altura

    def area(self): 
        return (self.base * self.altura)/2
    
#Función polimórfica 
def mostrar_area(forma): 
    print(f"El area es: {forma.area():.2f}")

#Prueba
figuras= [Circulo(5), Rectangulo(4, 6), Circulo(2.5), Rectangulo(3, 3), Triangulo(5, 2)]

for figura in figuras: 
    mostrar_area(figura)