from Person import Person
from Bank import Bank
import platform

import random
import time
import os

system=platform.system()

"""-------------------------------------Funciones--------------------------------------"""

def clear():
    if system == "Linux":
        os.system("clear")
    elif system == "Windows":
        clear()

def pause():
    if system == "Linux":
        input()
    elif system == "Windows":
        os.system("pause")


"""-----------MENU----------"""
def MenuLogin():
    print("\tBienvenido al CimaBanck")
    print(f'{'Porfavor seleccione una opcion':>35}\n')
    print("1.-Iniciar sesion\t\t2.-Registrarse")

def MenuMain():
    # print("Bienvenido",PerBase._name)
    print("Que desea realizar hoy?")
    print("1.-Ver saldo actual\t2.-Transaccion\t3.-Depositar\t4.-Retirar\t0.-Salir")
    op=int(input())
    return op

"""-------Documentos--------"""
def createTxt(user):
    #Obtener direccion actual del main
    dirActual=os.path.dirname(os.path.realpath(__file__))

    #Moverse a la carpeta registros y juntarla a la ruta de dirActual
    dirReg=os.path.join(dirActual,"reg")

    #Si no existe registros, la creara
    if not os.path.exists(dirReg):
        os.makedirs(dirReg)

    #Construimos la ruta
    docName=os.path.join(dirReg,user.name + '.txt')

    tPas=user.getPas()

    with open(docName,'w') as doc:
        doc.write(user.name + '\n')
        doc.write(tPas + '\n')

        doc.write(user.__noCuenta + '\n')
        doc.write(user.__clabe + '\n')
        doc.write(str(user.saldo) + '\n')
    
        doc.write(user.app + '\n')
        doc.write(user.apm + '\n')
        doc.write(str(user.day) + '\n')
        doc.write(str(user.month) + '\n')
        doc.write(str(user.year) + '\n')
        doc.write(user.mail + '\n')
        doc.write(str(user.numPhone) + '\n')

#Iniciar sesion
def readFile(name,pas):
    #Obtener direccion actual del main
    dirActual=os.path.dirname(os.path.realpath(__file__))

    #Moverse a la carpeta registros y juntarla a la ruta de dirActual
    dirReg=os.path.join(dirActual,"reg")
    dirReg=os.path.join(dirReg,name + '.txt')

    if os.path.exists(dirReg):
        with open(dirReg,"r") as doc:
            tName=doc.readline().strip()
            tPass=doc.readline().strip()
            
            tCuenta=doc.readline().strip()
            tClabe=doc.readline().strip()
            tSaldo=doc.readline().strip()
            
            tApp=doc.readline().strip()
            tApm=doc.readline().strip()
            tDay=doc.readline().strip()
            tMonth=doc.readline().strip()
            tYear=doc.readline().strip()
            tMail=doc.readline().strip()
            tPhone=doc.readline().strip()
            
            tuser = Bank(tName,tApp,tApm,tDay,tMonth,tYear,tMail,tPhone,tPass,tCuenta,tClabe,tSaldo)
            return tuser

"""---------Registro----------"""
def registro():
    clear()
    print("Bienvenido al sistema de registro\n","Porfavor ingrese los datos que se pidem")
    
    tName=input("Nombre\n")
    tApp=input("Apellido Paterno\n")
    tApm=input("Apellido Materno\n")

    clear()
    print("Fecha de nacimiento")
    tDay=int(input("dia\n"))
    tMonth=int(input("Mes\n"))
    tYear=int(input("Año\n"))

    clear()
    print("Informacion de contacto")
    tMail=input("Correo\n")
    tPhone=int(input("Numero de celular\n"))

    print("Escriba su contraseña")
    tPass=input("Contraseña\n")

    clear()
    user= Bank(tName,tApp,tApm,tDay,tMonth,tYear,tMail,tPhone,tPass)
    user.__noCuenta=user.genCuenta()
    user.__clabe=user.genClabe()
    print("Usuario registrado correctamente")
    print("Su cuenta es",user.__noCuenta,"su CLABE es",user.__clabe,"Y su saldo actual es",user.saldo,"")
    pause()
    
    return user

"""-------------------------------------MAIN---------------------------------------"""
bandOp=False

"""Inicio de sesion"""
while bandOp!=True: #ciclo de inicio de sesion
    op=1
    ins=False
    
    clear()
    MenuLogin()
    op=int(input())
    
    if op == 1: #Iniciar sesion
        while ins == False:
            print("Para salir ingrese 0")
            print("ingrese su nombre")
            name=input()
            if name==0:
                ins=True
            
            print("ingrese su contraseña")
            pas=input()
            if pas == 0:
                ins=True

            user= readFile(name,pas)

            if user.name == name and user.__pas == pas:
                print("Inicio exitoso")
                pause()
                ins=True
                bandOp=True
            else:
                print("Datos incorrectos")
                pause()
    elif op == 2: #Registrar nuevo usuario
        user = registro()
        createTxt(user)

"""Dentro del programa"""
bandSesion=False

while bandSesion !=True:
    clear()
    op=MenuMain()
    # print("1.-Ver saldo actual\t2.-Transaccion\t3.-Depositar\t4.-Retirar\t0.-Salir")
    if op == 1:
        user.viewSaldo()
    
    elif op == 2:
        print("Transaccion")
    
    elif op == 3:
        user.depositar()
        createTxt(user)
        pause()
    
    elif op==4:
        user.retirar()
        createTxt(user)
        pause()
    
    elif op == 0:
        print("Seguro que quieres salir?\n1.-Cancelar\t2.-Continuar")
        op=int(input())
        if op == 2:
            bandSesion=True


    