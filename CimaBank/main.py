import random
import os

#Clases
import Person
import Bank

def registrar():
    os.system('cls')
    op=1
    while op!= 0:
        print("Favor de ingresar los datos")
        
        tname=input("Nombre\n")
        tapp=input("Apellido paterno\n")
        tapm=input("Apellido Materno\n")
        os.system('cls')

        print('Fecha de nacimiento')
        tday=input("Dia\n")
        tmonth=input("Mes\n")#metodo de validacion para solo numeros
        tyear=input("Year\n")

        
        #datos de contacto
        os.system('cls')
        tmail=input("Email\n")
        pas=input("Contrasena\n")
        phone=input("Phone number\n")

        #Pega los datos en una variable temporal
        PerBase=Person.Person(tname,tapp,tapm,tday,tmonth,tyear)
        perBase.__count_init__(tmail,pas,phone)

        os.system("cls")
        print("Estos son sus datos")
        print("Nombre :",PerBase._name, end=("\t"))
        print("Apellido paterno :",PerBase._app, end=("\t"))
        print("Apellido Materno :",PerBase._apm)
        
        print("")
        print("Fecha de nacimiento")
        print("Dia",PerBase._day,"Mes",PerBase._month,"Año",PerBase._year)

        print("")
        print("Correo",perBase._mail,"\tPasword",perBase._pasword,"\tPhone Number",perBase._phone)
        
        print("")
        print("Desea continuar?")
        print("1.-Continuar\t2.-Cancelar")
        op=int(input())
        op=op-1
    
    
    
    print("Datos copiados\n")
    return PerBase

def MenuLogin():
    print("\tBienvenido al CimaBanck")
    print(f'{'Porfavor seleccione una opcion':>35}\n')
    print("1.-Iniciar sesion\t\t2.-Registrarse")

#--------------------------INICIO DE SESION---------------------------

op=1 #Variable para el ciclo
perBase=Person.Person("","","","","","") #persona base

while op!=0: #ciclo de inicio de sesion
    os.system("cls")
    MenuLogin()
    op=int(input())

    if op ==1:
        #Iniciar sesion
        print("Ingrese su No.Cuenta")
        
        
        os.system("pause")
        op=0#una vez termine la operacion, inicamos la aplicacion
    
    if op == 2:
        #Registrarse
        PerBase=registrar()
        BankBase=Bank.Bank(perBase)
        
        print("")
        print("Estos son sus datos bancarios")
        print("clabe",BankBase._clabe,"\tcuenta",BankBase._noCuenta, "\tsaldo",BankBase._saldo)

        os.system("pause")
        #Una vez termine de registrarse, debera de inciar sesion

#-------------------------------------------------------------------------

def MenuMain():
    print("Bienvenido",perBase._name)
    print("Que desea realizar hoy?")
    print("1.-Ver saldo actual\t2.-Transaccion\t3.-Depositar\t4.-Retirar")
    op=int(input())
    return op

def saldo(banco):
    print("saldo actual")

#--------------------------INICIO---------------------------

# op=1
# while(op!=0):
#     os.system("cls")
#     op=MenuMain()
    



