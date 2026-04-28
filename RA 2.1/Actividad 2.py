class Volador: 
    def moverse(self):
        print("volando")

class Nadador: 
    def moverse(self): 
        print("nadando")

#Clase sin sobrescritura: 
class Pato(Volador, Nadador): 
    pass

print("======Sin sobrescritura======")
p= Pato()
p.moverse()

print("Orden MRO: ", Pato.__mro__)

#Clase con sobrescritura y llamadas explicitas: 
class PatoExplicito(Volador, Nadador): 
    def moverse(self): 
        Volador.moverse(self)
        Nadador.moverse(self)
        print("Tambien camino")

print("======Con sobrescritura explicita======")
p2= PatoExplicito()
p2.moverse()