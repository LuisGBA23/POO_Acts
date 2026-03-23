class Estudiante: 
    def __init__(self, nombre, edad, calificaciones):
        self.nombre= nombre
        self.edad= edad
        self.calificaciones= calificaciones

    def calcular_promedio(self): 
        suma= sum(self.calificaciones)
        promedio= suma/len(self.calificaciones)
        return promedio
    
    def mostrar_info(self): 
        promedio= self.calcular_promedio()
        print("\n" + "="*40)
        print("INFORME DEL ESTUDIANTE")
        print("="*40)
        print(f"Nombre: {self.nombre}")
        print(f"Edad: {self.edad}")
        print(f"Calificaciones: {self.calificaciones[0]}, {self.calificaciones[1]}, {self.calificaciones[2]}")
        print(f"Promedio: {promedio:.2f}")
        print("="*40)

print("SISTEMA DE REGISTRO DE ESTUDIANTES")
print("-"*40)

nombre = input("Ingrese el nombre del estudiante: ")
edad= int(input("Ingrese la edad del estudiante: "))

calificaciones= []
for i in range(3): 
    cal= float(input(f"Ingrese la {i+1}° calificacion: "))
    calificaciones.append(cal)

estudiante1= Estudiante(nombre, edad, calificaciones)
estudiante1.mostrar_info()