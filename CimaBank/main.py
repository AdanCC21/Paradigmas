import random
import time
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
        PerBase.__count_init__(tmail,pas,phone)

        os.system("cls")
        print("Estos son sus datos")
        print("Nombre :",PerBase._name, end=("\t"))
        print("Apellido paterno :",PerBase._app, end=("\t"))
        print("Apellido Materno :",PerBase._apm)
        
        print("")
        print("Fecha de nacimiento")
        print("Dia",PerBase._day,"Mes",PerBase._month,"Año",PerBase._year)

        print("")
        print("Correo",PerBase._mail,"\tPasword",PerBase._pasword,"\tPhone Number",PerBase._phone)
        
        print("")
        print("Desea continuar?")
        print("1.-Continuar\t2.-Cancelar")
        op=int(input())
        op=op-1
    
    print("Datos copiados\n")
    return PerBase

#------------------------MENU----------------------------
def MenuLogin():
    print("\tBienvenido al CimaBanck")
    print(f'{'Porfavor seleccione una opcion':>35}\n')
    print("1.-Iniciar sesion\t\t2.-Registrarse")

def MenuMain():
    print("Bienvenido",PerBase._name)
    print("Que desea realizar hoy?")
    print("1.-Ver saldo actual\t2.-Transaccion\t3.-Depositar\t4.-Retirar")
    op=int(input())
    return op

#------------------------Aciones---------------------------------
def saldo():
    os.system("cls")
    print("\tSaldo actual")
    print(BankBase._saldo)
    os.system("pause")

def transaccion():
    print("\tTransaccion")

def depositar():
    os.system("cls")
    op=1
    dep=0
    while op!=0:
        print("\tDepositar")
        print("Para salir en cualquier momento escriba -1")
        print("1.-Cuanto quiere depositar")
        dep=int(input())
        if dep== -1:
            print("Operacion cancelada")
            op=0
            os.system("pause")
        else:
            print("Va a depositar :",dep)
            print("Esta seguro?\n1.-Continuar\t2.-Cancelar")
            op=int(input())
            
            if op==1:
                print("Cargando")
                temp=int(BankBase._saldo) + dep
                BankBase._saldo=temp + dep
                time.sleep(2)
                print("listo")
                op=0
                os.system("pause")
            
            elif op== -1:
                print("Operacion cancelada")
                op=0
                os.system("pause")

def retirar():
    os.system("cls")
    op=1
    ret=0
    while op!=0:
        print("\tRetirar")
        print("Para salir en cualquier momento escriba -1")
        print("1.-Cuanto quiere Retirar")
        ret=int(input())
        if ret== -1:
            print("Operacion cancelada")
            op=0
            os.system("pause")
        else:
            print("Va a depositar :",ret)
            print("Esta seguro?\n1.-Continuar\t2.-Cancelar")
            op=int(input())
            
            if op==1:
                print("Cargando")
                temp=(BankBase._saldo)
                BankBase._saldo = temp - ret
                
                time.sleep(2)
                print("listo")
                op=0
                os.system("pause")
            
            elif op== -1:
                print("Operacion cancelada")
                op=0
                os.system("pause")

#----------------------------Docs--------------------------
#Ocupo agregar los datos personales de la persona al mismo docs y crear una funcion para pegarla a la PersonaBase
#ocupo que cada que se acutalizen los datos, se sobreescriban en el txt
""" 
    Ocupo mejorar la forma para iniciar sesion, pidiendo nombre, y contraseña, pondria el nombre del txt con el nombre del usuario y al inicio del txt la contrasena
    y hacer una verificacion de si la contrasena ingresada y registrada son iguales, que copie y pegue los datos

"""

def createTxt():

    #Obtener direccion actual del main
    dirActual=os.path.dirname(os.path.realpath(__file__))

    #Moverse a la carpeta registros y juntarla a la ruta de dirActual
    dirReg=os.path.join(dirActual,"registros")

    #Si no existe registros, la creara
    if not os.path.exists(dirReg):
        os.makedirs(dirReg)

    #Construimos la ruta
    docName=os.path.join(dirReg,PerBase._name + '.txt')
    
    #Copiamos los datos
    tCuenta = BankBase._noCuenta + '\n'
    tClabe = BankBase._clabe + '\n'
    tSaldo = str(BankBase._saldo) + '\n'

    with open(docName, 'a') as doc:
        doc.write(tCuenta)
        doc.write(tClabe)
        doc.write(tSaldo)

def readTxt(name):
     #Obtener direccion actual del main
    dirActual=os.path.dirname(os.path.realpath(__file__))

    #Moverse a la carpeta registros y juntarla a la ruta de dirActual
    dirReg=os.path.join(dirActual,"registros")
    dirReg=os.path.join(dirReg,name)

    print(dirReg)
    os.system("pause")

    if os.path.exists(dirReg):
        #variables temporales
        tCuenta=''
        tClabe=''
        tSaldo=''

        print(dirReg)
        os.system("pause")

        with open (dirReg,'r') as doc:
            tCuenta=doc.readline().strip()
            tClabe=doc.readline().strip()
            tSaldo=doc.readline().strip()

        return tCuenta,tClabe,tSaldo
    else:
        print("Archivo no encontrado")




#--------------------------INICIO DE SESION---------------------------

op=1 #Variable para el ciclo
PerBase=Person.Person("","","","","","") #persona base

while op!=0: #ciclo de inicio de sesion
    os.system("cls")
    MenuLogin()
    op=int(input())

    if op ==1:
        #Iniciar sesion
        print("Ingrese su No.Cuenta")
        sCuenta=input()
        
        print("Ingrese su Nombre")
        sName=input()
        
        BankBase=Bank.Bank(PerBase)
        BankBase._noCuenta,BankBase._clabe,BankBase._saldo=readTxt(sName)
        
        os.system("pause")
        op=0#una vez termine la operacion, inicamos la aplicacion
    
    if op == 2:
        #Registrarse
        PerBase=registrar()
        BankBase=Bank.Bank(PerBase)
        createTxt()
        
        print("")
        print("Estos son sus datos bancarios")
        print("clabe",BankBase._clabe,"\tcuenta",BankBase._noCuenta, "\tsaldo",BankBase._saldo)

        os.system("pause")
        #Una vez termine de registrarse, debera de inciar sesion


#--------------------------INICIO---------------------------

op=1
while op!=0:
    os.system("cls")
    op=MenuMain()
    if op==1:
        saldo()
    elif op==2:
        transaccion()
    elif op==3:
        depositar()
    elif op==4:
        retirar()
