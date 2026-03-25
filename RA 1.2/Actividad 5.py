class Estudiante: 
    def __init__(self, matricula, nombre, grupo):
        self.matricula= matricula
        self.nombre= nombre
        self.grupo= grupo
        self.calificaciones= []
        self.materias= []

    def agregar_materia(self, materia, calificacion): 
        self.materias.append(materia)
        self.calificaciones.append(calificacion)

    def calcular_promedio(self): 
        if not self.calificaciones: 
            return 0.0 
        return sum(self.calificaciones)/len(self.calificaciones)
    
    def obtener_estado(self): 
        promedio= self.calcular_promedio()
        if promedio >= 60: 
            return "APROBADO"
        else: 
            return "REPROBADO"
        
    def __str__(self):
        promedio= self.calcular_promedio()
        return f"{self.matricula} | {self.nombre:15} | {self.grupo} | Prom: {promedio:.2f} | {self.obtener_estado()}"
    
class SistemaEscolar: 
    def __init__(self):
        self.estudiantes= []

    def registra_estudiante(self):
        print("\n" + "="*50)
        print("REGISTRO DE ESTUDIANTE")
        print("="*50)

        matricula= input("Matricula: ")

        for est in self.estudiantes: 
            if est.matricula == matricula: 
                print("Ya existe un estudiante con esa matricula")
                return
        
        nombre= input("Nombre completo: ")
        grupo= input("Grupo: ")

        estudiante= Estudiante(matricula, nombre, grupo)

        print("\nRegistrar calificaciones")
        while True: 
            materia= input("Nombre de la materia (Enter para terminar): ")
            if materia == "": 
                break

            try:
                calificacion= float(input(f"Calificacion de {materia}: "))
                estudiante.agregar_materia(materia, calificacion)
            except ValueError: 
                print("Calificacion invalida. Use numeros.")

        self.estudiantes.append(estudiante)
        print(f"Estudiante {nombre} registrado exitosamente")

    def mostrar_todos(self):
        if not self.estudiantes: 
            print("No hay eswtudiantes registrados")
            return

        print("\n" + "="*70)
        print("LISTA DE ESTUDIANTES")
        print("="*70)
        print("Matricula | Nombre | Grupo | Promedio | Estado")
        print("-"*70)
        for estudiante in self.estudiantes:
            print(estudiante)

    def buscar_estudiantes(self):
        matricula= input("Ingrese matricula a buscar: ")

        for estudiante in self.estudiantes: 
            if estudiante.matricula == matricula: 
                print("\n" + "="*50)
                print("DATOS DEL ESTUDIANTE")
                print("="*50)
                print(f"Matricula: {estudiante.matricula}")
                print(f"Nombre: {estudiante.nombre}")
                print(f"Grupo: {estudiante.grupo}")
                print("\nMaterias y calificaciones:")
                for i, (materia, calif) in enumerate(zip(estudiante.materias, estudiante.calificaciones), 1):
                    print(f" {i}. {materia}: {calif}")

                print(f"\nPromedio: {estudiante.calcular_promedio():.2f}")
                print(f"Estado: {estudiante.obtener_estado()}")
                return
            
        print(f"No se encontro estudiante con matricula {matricula}")

    def generar_reporte_por_grupo(self): 
        if not self.estudiantes: 
            print("No hay estudiantes registrados")
            return
        
        grupos= {}
        for est in self.estudiantes: 
            if est.grupo not in grupos: 
                grupos[est.grupo]= []
            grupos[est.grupo].append(est)

        print("\n" + "="*70)
        print("REPORTE POR GRUPO")
        print("="*70)

        for grupo, estudiantes in grupos.items(): 
            print(f"\nGRUPO: {grupo}")
            print("-"*50)
            print("Matricula | Nombre | Promedio | Estado")
            print("-"*50)
            for est in estudiantes:
                print(f"{est.matricula} | {est.nombre:15} | {est.calcular_promedio():.2f} | {est.obtener_estado()}")

###########################################################################################################################
def main(): 
    sistema= SistemaEscolar()
    opcion= 0 

    ejemplo= Estudiante("A001", "Orlando Estrella", "403")
    ejemplo.agregar_materia("Programacion", 95)
    ejemplo.agregar_materia("Matematicas", 88)
    sistema.estudiantes.append(ejemplo)

    ejemplo2= Estudiante("A002", "Carlos Silos", "408")
    ejemplo2.agregar_materia("Programacion", 45)
    ejemplo2.agregar_materia("Matematicas", 52)
    sistema.estudiantes.append(ejemplo2)

    while opcion != 6: 
        print("\n" + "="*50)
        print("SISTEMA DE GESTION ESCOLAR")
        print("="*50)
        print("1. Registrar estudiante")
        print("2. Mostrar todos los estudiantes")
        print("3. Buscar estudiante")
        print("4. Reporte por grupo")
        print("5. Agregar calificaciones a estudiante existente")
        print("6. Salir")
        print("="*50)

        try: 
            if opcion == 1: 
                sistema.registra_estudiante()
            elif opcion == 2: 
                sistema.mostrar_todos()
            elif opcion == 3: 
                sistema.buscar_estudiantes()
            elif opcion == 4:
                sistema.generar_reporte_por_grupo()
            elif opcion == 5: 
                matricula= input("Matricula del estudiante: ")
                encontrado= False
                for est in sistema.estudiantes: 
                    if est.matricula == matricula: 
                        materia = input("Materia: ")
                        try: 
                            calif= float(input("Calificacion: "))
                            est.agregar_materia(materia, calif)
                            print("Calificacion agregada")
                        except ValueError: 
                            print("Calificacion invalida")
                        encontrado= True
                        break
                if not encontrado: 
                    print("Estudiante no encontrado")
            elif opcion == 6: 
                print("Programa finalizado")
            else: 
                print("Opcion invalida")
        except ValueError: 
            print("Por favor, ingrese un numero valido")

if __name__ == "__main__": 
    main()