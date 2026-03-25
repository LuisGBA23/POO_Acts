class Producto: 
    def __init__(self, codigo, nombre, precio, categoria):
        self.codigo = codigo
        self.nombre = nombre
        self.precio = precio
        self.categoria = categoria

    def __str__(self):
        return f"{self.codigo} | {self.nombre} | {self.precio:.2f} | {self.categoria}"
    
class Inventario: 
    def __init__(self):
        self.productos = []
        self.estadisticas = [
        ["Electronica", 0, 0.0],
        ["Ropa", 0, 0.0],
        ["Alimentos", 0, 0.0],
        ["Hogar", 0, 0.0]
        ]

    def agregar_producto(self, producto): 
        self.productos.append(producto)
        self._actualizar_estadisticas(producto)
        print(f"Producto '{producto.nombre}' agregado correctamente")

    def _actualizar_estadisticas(self, producto):
        for i in range(len(self.estadisticas)):
            if self.estadisticas[i][0] == producto.categoria: 
                self.estadisticas[i][1] += 1
                self.estadisticas[i][2] += producto.precio
                break

    def buscar_por_categoria(self, categoria): 
        resultados= []
        for producto in self.productos:
            if producto.categoria.lower() == categoria.lower():
                resultados.append(producto)
        return resultados 
    
    def mostrar_inventario(self): 
        if not self.productos: 
            print("Inventario vacio")
            return
        
        print("\n" + "="*60)
        print("LISTA DE PRODUCTOS (Arreglo Unidimensional)")
        print("="*60)
        print("Codigo | Nombre | Precio | Categoria")
        print("-"*60)
        for producto in self.productos:
            print(producto)

    def mostrar_estadisticas(self): 
        print("\n" + "="*60)
        print("ESTADISTICAS POR CATEGORIA (Matriz - Arreglo Bidimensional)")
        print("="*60)
        print("Categoria | Cantidad | Valor Total")
        print("-"*60)
        for fila in self.estadisticas:
            print(f"{fila[0]:11} | {fila[1]:8} | ${fila[2]:.2f}")

##################################################################################
inventario= Inventario()

productos_iniciales = [
Producto("001", "Laptop", 12000.00, "Electronica"),
Producto("002", "Camiseta", 250.00, "Ropa"),
Producto("003", "Arroz", 85.50, "Alimentos"),
Producto("004", "Sarten", 350.00, "Hogar"),
Producto("005", "Smartphone", 8000.00, "Electronica"),
Producto("006", "Pantalon", 450.00, "Ropa")
]

for prod in productos_iniciales: 
    inventario.agregar_producto(prod)

inventario.mostrar_inventario()

print("\n" + "="*60)
categoria_buscar= input("Buscar productos por categoria: ")
resultados= inventario.buscar_por_categoria(categoria_buscar)

if resultados: 
    print(f"\nProductos en categoria '{categoria_buscar}':")
    
    for prod in resultados:
        print(f" - {prod.nombre} - ${prod.precio:.2f}")
else:
    print(f"No se encontraron productos en la categoria '{categoria_buscar}'")
    inventario.mostrar_estadisticas()