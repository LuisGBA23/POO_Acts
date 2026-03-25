class Cliente: 
    def __init__(self, id_cliente, nombre, direccion):
        self.id_cliente= id_cliente
        self.nombre= nombre 
        self.direccion= direccion
        self.cuentas= []

    def agregar_cuenta(self, cuenta): 
        self.cuentas_append(cuenta)
        print(f"Cuenta {cuenta.numero_cuenta} asociada a {self.nombre}")

    def mostrar_resumen(self): 
        print(f"\nCliente: {self.nombre} (ID: {self.id_cliente})")
        print("Cuentas: ")
        for cuenta in self.cuentas: 
            print(f" -> {cuenta}")

class Cuenta: 
    def __init__(self, numero_cuenta, saldo_inicial= 0):
        self.numero_cuenta= numero_cuenta
        self._saldo= saldo_inicial 
        self._activa= True

    def depositar(self, cantidad):
        if cantidad > 0 and self._activa: 
            self._saldo += cantidad
            print(f"Deposito exitoso. Nuevo saldo: {self._saldo:.2f}")
            return True
        else: 
            print("Error: Cantidad invalida o cuenta inactiva")
            return False
        
    def retirar(self, cantidad): 
        if not self._activa:
            print("Error: Cuenta inactiva")
            return False
        if cantidad > 0 and cantidad <= self._saldo: 
            self._saldo -= cantidad
            print(f"Retiro exitoso. Nuevo saldo: {self._saldo:.2f}")
            return True
        else: 
            print("Error: Fondos insuficientes o cantidad invalida")
            return False
        
    def aplicar_interes(self): 
        if self._activa: 
            interes= self._saldo * Cuenta.tasa_interes_anual/12
            self._saldo += interes
            print(f"Interes aplicado: +${interes:.2f}")

    def get_saldo(self): 
        return self._saldo
    
    def esta_activa(self): 
        return self._activa
    
    def cerrar_cuenta(self): 
        self._activa= False
        print(f"Cuenta {self.numero_cuenta} cerrada")

    def __str__(self):
        estado= "Activa" if self._activa else "Inactiva"
        return f"Cuenta {self.numero_cuenta} - Saldo: ${self._saldo:.2f} ({estado})"
    
#################################################################################################
print("SISTEMA BANCARIO")
print("="*50)

cliente1= Cliente(1001, "Orlando Estrella", "Av. Principal 123")
cliente2= Cliente(1002, "Marco Carranza", "Calle Secundaria 456")

cuenta_ahorro= Cuenta("SA-001", 5000)
cuenta_ahorro2= Cuenta("SA-002", 10000)
cuenta_corriente= Cuenta("SC-001", 20000)

cliente1.agregar_cuenta(cuenta_ahorro)
cliente1.agregar_cuenta(cuenta_corriente)
cliente2.agregar_cuenta(cuenta_ahorro2)

print("\n" + "="*50)
print("OPERACIONES")
print("="*50)

cuenta_ahorro.depositar(1500)
cuenta_ahorro2.retirar(2000)
cuenta_ahorro.aplicar_interes()
cuenta_ahorro2.aplicar_interes()

print(f"\nSaldo actual: ${cuenta_ahorro.get_saldo():.2f}")
print(f"\nSaldo actual: ${cuenta_ahorro2.get_saldo():.2f}")

print("\n" + "="*50)
print("RESUMEN DE CLIENTES")
print("="*50)

cliente1.mostrar_resumen()
cliente2.mostrar_resumen()

cuenta_corriente.cerrar_cuenta()
cuenta_corriente.retirar(100)

print("\n" + "="*50)
print("PROGRAMA FINALIZADO")