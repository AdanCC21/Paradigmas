class Persona:
    n=''
    e=0
    c=''
    def __init__(self,nombre, edad, cuenta):
        self.n = nombre
        self.e = edad
        self.c = cuenta

# Ejemplo de cómo crear una instancia de la clase Persona
persona1 = Persona("Juan", 30, "1234567890")
print("Nombre:", persona1.n)
print("Edad:", persona1.e)
print("Cuenta:", persona1.c)
