class Motor: 
    def __init__(self, tipo, caballos):
        self.tipo= tipo
        self.caballos= caballos 

    def describir(self): 
        return f"Motor {self.tipo} de {self.caballos} CV"

class Coche: 
    def __init__(self, marca, modelo, motor):
        self.marca= marca 
        self.modelo= modelo
        self.motor= motor

    def mostrar_info(self): 
        print(f"Coche: {self.marca} {self.modelo}")
        print(self.motor.describir())

motor_v8= Motor("gasolina", 450)

auto= Coche("Nissan", "Sentra", motor_v8)

auto.mostrar_info()