class CuentaBancaria: 
    def __init__(self, saldo_inicial=0):
        self._saldo= saldo_inicial
    
    def depositar(self, cantidad):
        if cantidad > 0: 
            self._saldo += cantidad 
            print(f"Se hizo un deposito de forma exitosa. El saldo actual es de: ${self._saldo}")
        else: 
            print("La cantidad a ingresar no es una cifra valida")

    def retirar(self, cantidad):
        if cantidad > 0 and self._saldo >= cantidad: 
            self._saldo -= cantidad 
            print(f"Se hizo un retiro de forma exitosa. El saldo actual es de: ${self._saldo}")
        else:
            print("La cantidad a retirar no es valida o el saldo es insuficiente")

    def get_saldo(self):
        print(f"Tu saldo actual es de: ${self._saldo}")

mi_cuenta = CuentaBancaria(1000)
mi_cuenta.depositar(500) 
mi_cuenta.retirar(200) 
mi_cuenta.get_saldo()