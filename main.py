import math

############################################### DEFINICION DE CLASES ################################################
class Figura: 
    #Atributo privado y metodo constructor:
    def __init__(self, nombre): 
        self._nombre= nombre

    def calcular_area(self): 
        raise NotImplementedError("Las subclases deben tener calcular_area()")
    
    def calcular_perimetro(self): 
        raise NotImplementedError("Las subclases deben tener calcular_perimetro()")

    #Metodo getter para obtener el nombre de la figura de forma segura:
    def getNombre(self): return self._nombre
    
    #brecarga de operdores:
    def __add__(self, other): 
        if isinstance(other, Figura): 
            return self.calcular_area() + other.calcular_area()
        return NotImplemented
    
    def __lt__(self, other):
        if isinstance(other, Figura): 
            if other.calcular_area() < self.calcular_area(): 
                return f"El area de {self._nombre} es mayor que el area de {other._nombre}"
            elif self.calcular_area() < other.calcular_area(): 
                return f"El area de {other._nombre} es mayor que el area de {self._nombre}"
            else: 
                return f"El area de {self._nombre} y la de {other._nombre} son iguales"
        return NotImplemented
    
    def __eq__(self, other): 
        if isinstance(other, Figura):
            if self.calcular_area() == other.calcular_area(): 
                return f"El area de {self._nombre} es igual al area de {other._nombre}"
            else: 
                return f"El area de {self._nombre} y la de {other._nombre} son diferentes"
        return NotImplemented
        
    def Figuragrande(self): 
        if self.calcular_area() > 100: 
            return f"(Es un {self._nombre} GRANDE)"

    def __str__(self): 
        return f"{self._nombre}= {self.calcular_area():.2f}"
    
#Herencia de clases: 
class Circulo(Figura):
    #Metodo constructor con herencia (super()):
    def __init__(self, diametro, nombre= "Circulo"):
        super().__init__(nombre)
        self._nombre= nombre
        self.diametro= diametro

    #Sobrescritura de metodos:
    def calcular_area(self):
        return math.pi * (self.diametro/2) ** 2
    
    def calcular_perimetro(self):
        return math.pi * self.diametro
    
#Herencia de clases: 
class Rectangulo(Figura): 
    #Metodo constructor con herencia (super()):
    def __init__(self, ancho, alto, nombre= "Rectangulo"):
        super().__init__(nombre)
        self._nombre= nombre
        self.ancho= ancho
        self.alto= alto

    #Sobrescritura de metodos:
    def calcular_area(self):
        return self.ancho * self.alto
    
    def calcular_perimetro(self):
        return (self.alto*2) + (self.ancho*2)
    
#Herencia de clases: 
class Cuadrado(Figura): 
    #Metodo constructor con herencia (super()):
    def __init__(self, lado, nombre= "Cuadrado"):
        super().__init__(nombre)
        self._nombre= nombre
        self.lado= lado

    #Sobrescritura de metodos:
    def calcular_area(self):
        return self.lado ** 2
    
    def calcular_perimetro(self):
        return self.lado * 4

#Herencia de clases: 
class Triangulo(Figura): 
    #Metodo constructor con herencia (super()):
    def __init__(self, base, lado1, lado2, alto, nombre= "Triangulo"): 
        super().__init__(nombre)
        self._nombre= nombre
        self.base= base
        self.lado1= lado1
        self.lado2= lado2
        self.alto= alto

    #Sobrescritura de metodos:
    def calcular_area(self):
        return (self.base * self.alto)/2
    
    def calcular_perimetro(self):
        return self.base + self.lado1 + self.lado2
    
############################################### CODIGO PRINCIPAL Y FUNCIONES DE UTILIDAD ################################################
def mostrarfigura(figura): 
    print(f"{figura.getNombre()}: [\nArea= {figura.calcular_area():.2f}\nPerimetro= {figura.calcular_perimetro():.2f}\n{figura.Figuragrande()}\n]\n")

figuras= []
def agregarfigura(): 
    flag= False
    eleccion= input("Que tipo de figura quieres agrear? (circulo, retangulo, cuadrado, triangulo): ")

    if eleccion == "circulo": 
        diametro = float(input("Ingresa el diametro del circulo: "))
        figuras.append(Circulo(diametro))
        flag= True
    elif eleccion == "rectangulo": 
        datos= input("Ingresa el ancho y alto del rectangulo (separados por un espacio): ")
        ancho, alto= map(float, datos.split())  
        figuras.append(Rectangulo(ancho, alto))
        flag= True
    elif eleccion == "cuadrado": 
        lado= float(input("Ingresa el lado del cuadrado: "))
        figuras.append(Cuadrado(lado))
        flag= True
    elif eleccion == "triangulo": 
        datos= input("Ingresa la base, dos lados y la altura del triangulo (separados por espacios): ")
        base, lado1, lado2, alto= map(float, datos.split())
        figuras.append(Triangulo(base, lado1, lado2, alto))
        flag= True
    else: 
        print("Figura no valida/Te equivocaste al escribir XDDD. Vuelve a intentar papu")

    if flag: 
        print("Figura agregada con exito :)")

def ops_with_figs(): 
    for x, fig in enumerate(figuras): 
        print(f"{x+1}- {fig.getNombre()}: Area= {fig.calcular_area():.2f}, Perimetro= {fig.calcular_perimetro():.2f}")

    datos= input("\nEscribe la operacion a realizar (sumar, mayor, igual) y los indices de dos figuras: ")
    operacion= datos.split()[0]
    choice1, choice2= int(datos.split()[1]), int(datos.split()[2])

    if operacion == "sumar": 
        print(f"El resultado de la suma de areas es: {(figuras[choice1-1] + figuras[choice2-1]):.2f}")
    elif operacion == "mayor": 
        print(figuras[choice1-1] <  figuras[choice2-1])
    elif operacion == "igual": 
        print(figuras[choice1-1] == figuras[choice2-1])

#Función polimórfica 
def funcionpolimorfica(lista_figs): 
    #Recibe lista de figuras y calcula el area total
    total= 0 
    for figura in lista_figs: 
        total += figura.calcular_area()
    print(f"La suma del area de todas las figuras es: {total:.2f}")

opcion= 0
flag_menu= True
while opcion != 5: 
    if flag_menu: 
        print("\n"+"="*50)
        print("BASE DE DATOS: FIGURAS :V")
        print("="*50)
        print("1. Agregar nueva figura")
        print("2. Mostrar figuras")
        print("3. Operaciones con figuras")
        print("4. Sumar el area de todas las figuras (funcion polimorfica)")
        print("5. Salir")
        opcion= int(input("Elige una opcion: "))
    flag_menu= False 

    match opcion: 
        case 1: 
            print("\n"+"-"*50)
            print("AGREGAR FIGURAS")
            print("-"*50)
            agregarfigura()
            flag_menu= True
            continue
        case 2: 
            print("\n"+"-"*50)
            print("FIGURAS GUARDADAS")
            print("-"*50)
            for figura in figuras: 
                mostrarfigura(figura)
            flag_menu= True
            continue
        case 3: 
            print("\n"+"-"*50)
            print("QUICK FIGURAS DISPONIBLES")
            print("-"*50)
            ops_with_figs()
            flag_menu= True
            continue
        case 4: 
            print("\n"+"-"*50)
            print("SUMA DEL AREA DE TODAS LAS FIGURAS GUARDADAS")
            print("-"*50)
            funcionpolimorfica(figuras)
            flag_menu= True
            continue
        case 5: 
            print("Cerrando el programa...")
            break
        case _: 
            print("Esa opcion no esta we, intenta otra vez")
            flag_menu= True
            continue