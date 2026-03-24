class Calculadora: 
    def __init__(self):
        self.historial = []

    def sumar(self, a , b): 
        resultado= a+b 
        self._guardar_en_historial(f"{a}+{b} = {resultado}")
        return resultado 
    
    def resta(self, a, b): 
        resultado= a-b
        self._guardar_en_historial(f"{a}-{b} = {resultado}")
        return resultado 
    
    def multiplicar(self, a, b): 
        if b != 0: 
            resultado= a*b
            self._guardar_en_historial(f"{a}*{b} = {resultado}")
            return resultado
        else: 
            return "Error: No se puede dividir entre cero"
    
    def dividir(self, a, b): 
        resultado= a/b 
        self._guardar_en_historial(f"{a}/{b} = {resultado:.2f}")
        return resultado

    def _guardar_en_historial(self, operacion): 
        self.historial.append(operacion)

    def mostrar_historial(self): 
        print("\n"+"-"*30)
        print("HISTORIAL DE OPERACIONES")
        print("-"*30)
        for i, op in enumerate(self.historial, 1):
            print(f"{i}. {op}")

calc= Calculadora()
opcion= 0

while opcion != 5: 
    print("\n" + "="*30)
    print("CALCULADORA")
    print("="*30)
    print("1. Sumar")
    print("2. Restar")
    print("3. Multiplicar")
    print("4. Dividir")
    print("5. Salir")

    try: 
        opcion= int(input("\nSeleccione una opcion:"))

        if opcion == 5: 
            print("Programa finalizado")
            break 
        elif opcion in [1,2,3,4]: 
            num1= float(input("Ingrese el primer numero: "))
            num2= float(input("Ingrese el segundo numero: "))
        
            if opcion == 1: 
                resultado= calc.sumar(num1, num2)
                print(f"Resultado: {resultado}")
            elif opcion == 2: 
                resulado= calc.restar(num1, num2)
                print(f"Resultado: {resultado}")
            elif opcion == 3: 
                resulado= calc.multiplicar(num1, num2)
                print(f"Resultado: {resultado}")
            elif opcion == 4: 
                resulado= calc.dividir(num1, num2)
                print(f"Resultado: {resultado}")
        else:
            print("Opcion no valida. intente de nuevo")
    except ValueError: 
        print("Error: Debe ingresar un numero valido")

    ver_historial= input("\nVer historial? (s/n)").lower()
    if ver_historial == "s": 
        calc.mostrar_historial()

print("Programa finalizado")
