class Animal: 
    def hacer_sonido(self): 
        print("Sonido genérico")

class Perro(Animal):
    def hacer_sonido(self):
        print("Guau!")

class Gato(Animal): 
    def hacer_sonido(self):
        print("Miau!")

animales= [Perro(), Gato(), Animal()]

for animal in animales: 
    animal.hacer_sonido()