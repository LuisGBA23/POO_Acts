class Persona: 
    def __init__(self, nombre, edad):
        self.nombre= nombre 
        self.edad= edad

    def saludar(self): 
        print(f"hola, mi nombre es {self.nombre} y tengo {self.edad} años")

    def cumple(self): 
        self.edad= self.edad+1 
        print(f"{self.nombre} ha cumplido años! Ahora tiene {self.edad} años")

persona1= Persona("Orlando", 17)
persona2= Persona("Marco", 16)

persona1.saludar()
persona2.saludar()

persona1.cumple()