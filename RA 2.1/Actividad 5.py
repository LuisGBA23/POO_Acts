class Empleado: 
    def __init__(self, nombre, salario_base):
        self.nombre= nombre
        self.salario_base= salario_base

    def calcular_salario(self): 
        return self.salario_base
    
    def __add__(self, otro): 
        if isinstance(otro, Empleado): 
            return self.calcular_salario() + otro.calcular_salario()
        return NotImplemented
    
    def __lt__(self, otro):
        if isinstance(otro, Empleado): 
            
        return NotImplemented

    def __str__(self): 
        return f"{self.nombre}: ${self.calcular_salario():.2f}"
    
class EmpleadoComision(Empleado): 
    def __init__(self, nombre, salario_base, ventas, porcentaje_comision): 
        super().__init__(nombre, salario_base) 
        self.ventas= ventas
        self.porcentaje_comision= porcentaje_comision

    def calcular_salario(self): 
        comision= self.ventas * self.porcentaje_comision / 100 
        return self.salario_base + comision 
    
class EmpleadoTemporal(Empleado): 
    def __init__(self, nombre, dias_trabajados, pago_por_dia, salario_base= None): 
        #salario_base no se necesita pero se mantiene por herencia: 
        super().__init__(nombre, salario_base)
        self.dias_trabajados= dias_trabajados
        self.pago_por_dia= pago_por_dia

    def calcular_salario(self):
        return self.dias_trabajados * self.pago_por_dia
    
def mostrar_salario(empleado): 
    print(f"Empleado: {empleado.nombre} -> Salario: ${empleado.calcular_salario():.2f}")

#Programa principal 
empleados = [ 
    Empleado("Orlando", 3000),
    EmpleadoComision("Marco", 2000, 50000, 5), 
    EmpleadoTemporal("Carlos", 20, 150)
]

print("=== Lista de empleados ===")

for emp in empleados: 
    mostrar_salario(emp)

print("=== Suma de salarios usando sobrecarga '+' ===")
suma= empleados[0] + empleados[1]
print(f"Orlando + Marco = ${suma:.2f}")

#suma_total= empleados[0] + empleados[1] + empleados[2]
#print(f"Suma total Orlando + Marco + Carlos = ${suma_total:.2f}")