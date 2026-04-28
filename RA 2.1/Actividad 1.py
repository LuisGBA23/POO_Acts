class Electrodomestico: 
    def __init__(self, marca, modelo, consumo_watts):
        self.marca= marca
        self.modelo= modelo
        self.consumo_watts= consumo_watts

    def encender(self):
        print("Electrodomestico encendido")

    def apagar(self): 
        print("Electrodomestico apagado")

class Lavadora(Electrodomestico): 
    def __init__(self, marca, modelo, consumo_watts, capacidad_kg):
        super().__init__(marca, modelo, consumo_watts)
        self.capacidad_kg= capacidad_kg

    def lavar(self): 
        print("Ciclo de lavado activado")

class Refrigerador(Electrodomestico): 
    def __init__(self, marca, modelo, consumo_watts, temperatura):
        super().__init__(marca, modelo, consumo_watts)
        self.temperatura= temperatura

    def encender(self): 
        print(f"Refrigerador encendido. Temperatura ajustada a {self.temperatura} grados")

#Prueba: 
lavadora= Lavadora("Samsung", "WW90", 2000, 9)
refri= Refrigerador("LG", "GB450", 1500, 4)

print(lavadora.marca, lavadora.modelo)
lavadora.encender() #metodo heredado 
lavadora.lavar()
print(f"Consumo de watts de la lavadora: {lavadora.consumo_watts}")
lavadora.apagar()

print(refri.marca, refri.modelo)
refri.encender() #metodo sobrescrito
refri.apagar()